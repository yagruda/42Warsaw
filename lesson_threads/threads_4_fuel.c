#include "lesson.h"

int fuel = 0;
pthread_mutex_t  mutexFuel;
pthread_cond_t condFuel;

void* car(void* arg)
{
	while (fuel < 40)
	{
		printf("Don't have enough fuel. Waiting\n");
		pthread_cond_wait(&condFuel, &mutexFuel); // wait when mutexFuel is unlocked
	}

	printf("We have enough fuel, let's go!\n");
	fuel -= 40;
	printf("We drove the car! Left fuel: %d\n", fuel);

}

void* to_fill(void* arg)
{
	pthread_mutex_lock(&mutexFuel);
	while (fuel <= 40)
	{
		fuel += 15;
		printf("Filling up... Current fuel: %d\n", fuel);
	}
	printf("finished filling up\n");
	pthread_mutex_unlock(&mutexFuel);
	pthread_cond_signal(&condFuel); // signal the waiting thread (inside car's while loop) that we unlocked the mutexFuel 
	
}

int main()
{
	pthread_t th[5];

	pthread_cond_init(&condFuel, NULL);
	pthread_mutex_init(&mutexFuel, NULL);

	for (int i = 0; i < 5; i++)
	{
		if (i == 4)
		{
			if(pthread_create(&th[i], NULL, &car, NULL) != 0)
			{
				perror("Failed to create thread");
				return 1;
			}
		}
		else 
		{
			if(pthread_create(&th[i], NULL, &to_fill, NULL) != 0)
			{
				perror("Failed to create thread");
				return 1;
			}
		}
	}


	for(int i = 0; i < 5; i++)
	{
		if (pthread_join(th[5], NULL) != 0)
		{
			perror("Failed to join thread");
			return 1;
		}
	}

	pthread_cond_destroy(&condFuel);
	pthread_mutex_destroy(&mutexFuel);

	return 0;
}