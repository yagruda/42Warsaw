 /*
Assignment name  : sandbox
Expected files   : sandbox.c
Allowed functions: fork, waitpid, exit, alarm, sigaction, kill, printf, strsignal,
errno, sigaddset, sigemptyset, sigfillset, sigdelset, sigismember
--------------------------------------------------------------------------------------

Write the following function:

#include <stdbool.h>
int sandbox(void (*f)(void), unsigned int timeout, bool verbose);

This function must test if the function f is a nice function or a bad function, you
will return 1 if f is nice, 0 if f is bad or -1 in case of an error in your function.

A function is considered bad if it is terminated or stopped by a signal (segfault, abort...),
if it exit with any other exit code than 0 or if it times out.

If verbose is true, you must write the appropriate message among the following:
"Nice function!\n"
"Bad function: exited with code <exit_code>\n"
"Bad function: <signal description>\n"
"Bad function: timed out after <timeout> seconds\n"

You must not leak processes (even in zombie state, this will be checked using wait).

We will test your code with very bad functions.
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>

// man errno

// DONE:
// track exit code of function passed. If != 0 write Bad function: exited with code <exit_code>\n otherwise write Nice function!\n
// track signals that cause termination of function passed. If signal is received, write bad function: <signal description>

// TBD:
// track time of execution of function passed. if time passed kill process, waitpid (so there wouldn't be zombie state) and write Bad function: timed out after <timeout> seconds\n

void alarm_handler(int x)
{
	printf("alarm! karamba!\n");
	(void)x;
}

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{	
	pid_t pid;
	int status;
	struct sigaction sa;

	sa.sa_handler = alarm_handler;
	sa.sa_flags = 0;

	sigemptyset(&sa.sa_mask);
	sigaction(SIGALRM, &sa, 0);

	pid = fork();
	if (pid == -1)
		return -1;

	//errno set and -1 returned if signl or error

	else if (pid == 0)
	{
		f();
		exit(0);
	}

	alarm(timeout);
	if (waitpid(pid, &status, 0) == -1)
	{
		if (errno == EINTR)
		{
			if (verbose)
				printf("Bad function: timed out after %d seconds\n", timeout);
			return 0;
		}
		else
		{
			printf("waitpid error and not by a timer\n");
			return -1;
		}
	}
	alarm(0);




	// add  && WEXITSTATUS(status) == 0
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
	{
		if (verbose)
			printf("Nice function\n");
		return 1;
	}
	else if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	{
		if (verbose)
			printf("Bad function: exited with code %d\n", WEXITSTATUS(status));
		return 0;
	}
	else if (WIFSIGNALED(status))
	{
		if (verbose)
			printf("Bad function: %d\n", WTERMSIG(status));
		return 0;
	}


	return 0;
}

void test_good_func()
{
	printf("Im  test good func!\n");
	usleep(4000000);
}

void test_bad_func()
{
	int *ptr = NULL;
	*ptr = 42;
}

void test_bad_func_two()
{
	usleep(40000000);
}

int main()
{
	sandbox(test_good_func, 5, true);
	printf("------------------------------\n");
	sandbox(test_bad_func, 5, true);
	printf("------------------------------\n");
	sandbox(test_bad_func_two, 1, true);
}