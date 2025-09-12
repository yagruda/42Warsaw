// #include "lesson.h"
// #include <time.h>

// int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

// void* routine(void* arg)
// {
// 	int index = *(int*)arg;
// 	int sum = 0;
// 	for (int i = 0; i < 5; i++)
// 	{
// 		sum += primes[index + i];
// 	}
// 	*(int*)arg = sum;
// 	printf("Local sum is %d\n", sum);
// 	return arg;
// }

// int main()
// {
	
// 	pthread_t th[2];

// 	for (int i = 0; i < 2; i++)
// 	{
// 		int *a = malloc(sizeof(int));
// 		*a = i * 5;

// 		if (pthread_create(&th[i], NULL, &routine, a) != 0)
// 		{
// 			perror("Failed to create thread");
// 			return 1;
// 		}
// 	}
// 	int globalSum = 0;
// 	for(int i = 0; i < 2; i++)
// 	{
// 		int* r;
// 		if (pthread_join(th[i], (void**)&r) != 0)
// 		{
// 			perror("Failed to join thread");
// 			return 1;
// 		}
// 		globalSum += *r;
// 		free(r);
// 	}

// 	printf("Total sum = %d\n", globalSum);


// 	return 0;
// }