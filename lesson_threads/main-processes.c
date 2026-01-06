// #include "lesson.h"


// int main()
// {
// 	int x = 2;
// 	int pid = fork();
// 	if (pid < 0)
// 		return 1;

// 	if (pid == 0)
// 	{
// 		printf("i am a child, x is %d and pid is %d\n", ++x, pid);
// 		wait(NULL);
// 	}
// 	else
// 	{	
// 		printf("i am a parent, x is %d and pid is %d\n", x, pid);
// 	}

// 	return 0;
// }