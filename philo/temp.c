#include "philo.h"

void	*myTurn(t_data *data)
{
	int	i;

	i = 0;
	gettimeofday(&data->start, NULL);
	while (i < 50)
	{
		pthread_mutex_lock(&data->mutex1);
		data->death++;
		pthread_mutex_unlock(&data->mutex1);
		i++;
	}
	gettimeofday(&data->end, NULL);
	return (NULL);
}

void	*yourTurn(t_data *data)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		pthread_mutex_lock(&data->mutex1);
		data->death++;
		pthread_mutex_unlock(&data->mutex1);
		i++;
	}
	sleep(1);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_data			data;
	pthread_t		thread1;
	pthread_t		thread2;

	(void)argc;
	(void)argv;
	data.death = 0;
	pthread_mutex_init(&data.mutex1, NULL);
	if (pthread_create(&thread1, NULL, (void*)myTurn, (void *)&data) != 0)
		return (1);
	if (pthread_create(&thread2, NULL, (void*)yourTurn, (void *)&data) != 0)
		return (2);
	if (pthread_join(thread1, NULL) != 0)
		return (3);
	if (pthread_join(thread2, NULL) != 0)
		return (4);
	pthread_mutex_destroy(&data.mutex1);
	
	printf("Death %d\n", data.death);
	printf("Time taken for all threads: %ld mili seconds\n",\
		((data.end.tv_sec * 1000000 + data.end.tv_usec) - (data.start.tv_sec * 1000000 + data.start.tv_usec)));
	return (0);
}
