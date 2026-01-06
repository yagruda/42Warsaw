// #include "lesson.h"
// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <pthread.h>


// static void* thread_fn_callback(void* arg)
// {
// 	char* input = (char*) arg;
	
// 	while (5 < 10)
// 	{
// 		printf("input string: %s", input);
// 		sleep(1);
// 	}
// }

// void thread1_create()
// {
// 	pthread_t pthread1;
	
// 	static char *thread_input1 = "Thread 1: Hello from thread 1!\n";
	
// 	// why is it static ? why not just char *thread_input1 = "Thread 1: Hello from thread 1!\n"; ? 
// 	// Because if it is not static, it will be created on the stack, and when the function ends, it will be destroyed.
// 	// Then the thread will try to access a destroyed variable, which will lead to undefined behavior.

// 	int rc = pthread_create(&pthread1, NULL, thread_fn_callback, (void*) thread_input1);
// 	if (rc != 0)
// 	{
// 		ft_printf("Error: pthread_create() failed with code %d\n", rc);
// 		exit(0);
// 	}
	
// }

// int main(void)
// {
// 	thread1_create();
// 	ft_printf("main fn paused!\n");
// 	pause(1)
// 	return (0);
// }