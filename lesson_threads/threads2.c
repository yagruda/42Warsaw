// #include "lesson.h"
// #include <time.h>

// get return from a function


// pthread_mutex_t mutex;

// void* dice()
// {
// 	int result = (rand() % 6) + 1;
// 	int* res = malloc(sizeof(result));
// 	*res = result; 

// 	return (void*) res;
// }

// int main()
// {
// 	int *res; 
// 	int k = 1;
// 	pthread_t th[k];

// 	for (int i = 0; i < k; i++)
// 	{
// 		if(pthread_create(th + i, NULL, &dice, NULL) != 0)
// 		{
// 			return 1;
// 		}
// 		printf("thread %d created\n", i);
// 	}

// 	for (int i = 0; i < k; i++)
// 	{
// 		if(pthread_join(th[i], (void**) &res) != 0)
// 		{
// 			return 1;
// 		}
// 		printf("thread %d finished execution\n", i);
// 	}

// 	printf("dice is %d\n", *res);

// 	free(res);
// 	return 0;
// }