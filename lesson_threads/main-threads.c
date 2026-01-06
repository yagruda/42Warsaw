// #include "lesson.h"


// int mails = 0;
// int lock = 0;
// pthread_mutex_t mutex;

// void* routine()
// {
// 	for (int i = 0; i < 100000; i++)
// 	{
// 		pthread_mutex_lock(&mutex);
// 		mails++;
// 		pthread_mutex_unlock(&mutex);
// 	}
// 	printf("%d mails are now in routine1\n", mails);
// 	return NULL;
// }

// void* routine2()
// {
// 	for (int i = 0; i < 100000; i++)
// 	{
// 		pthread_mutex_lock(&mutex);
// 		mails++;
// 		pthread_mutex_unlock(&mutex);
// 	}
// 	printf("%d mails are now in routine2 \n", mails);
// 	return NULL;
// }

// int main()
// {
// 	pthread_t th[4];
// 	pthread_mutex_init(&mutex, NULL);


// 	for (int i = 0; i < 4; i++)
// 	{
// 		if(pthread_create(th + i, NULL, &routine, NULL) != 0)
// 		{
// 			return 1;
// 		}
// 		printf("thread %d created\n", i);
// 	}

// 	for (int i = 0; i < 4; i++)
// 	{
// 		if(pthread_join(th[i], NULL) != 0)
// 		{
// 			return 1;
// 		}
// 		printf("thread %d finished execution\n", i);
// 	}
	
	
// 	pthread_mutex_destroy(&mutex);
// 	printf("Final mails count: %d\n", mails);
// 	return 0;
// }