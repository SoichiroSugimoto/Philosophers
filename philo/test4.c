#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	global_val = 0;
int judge = 0;
pthread_mutex_t	th_mutex;

void	*thread_start_routine(void *data)
{
	int	val;
	int	i;

	val = (int)data;
	printf("● ● ● ● ● ● ● ● ● ● thread_start_routine : val=%d\n", val);
	i = 0;
	while (i < 10)
	{
		printf("######## [1] ######## judge :  %d\n", judge);
		sleep(1);
		printf("######## [2] ######## judge :  %d\n", judge);
		sleep(1);
		printf("######## [3] ######## judge :  %d\n", judge);
		sleep(1);
		i++;
	}
	printf("end of start_routine(func)\n");
	return (NULL);
}

void	*monitor(void *data)
{
	pthread_t	th;

	th = (pthread_t)data;
	while (1)
	{
		if (judge == 1)
		{
			printf("@@@@@@@@@@@@@@@@@ DETECT @@@@@@@@@@@@@@@@@@@@\n");
			pthread_detach(th);
			break ;
		}
		usleep(1000);
	}
	printf("\n--------------------------------------end of monitoring\n");
	return (NULL);
}

int	main(void)
{
	int			i;
	pthread_t	th;
	pthread_t	th_mon;
	void		*th_ret;

	i = 0;
	if (pthread_create(&th, NULL, thread_start_routine, (void *)100) != 0)
	{
		perror("pthread_create");
		return (1);
	}
	if (pthread_create(&th_mon, NULL, monitor, (void *)th) != 0)
	{
		perror("pthread_create");
		return (1);
	}
	// while (i < 3)
	// {
	// 	global_val++;
	// 	printf("\n+++++++++++++  main : i=%d, g=%d\n", i, global_val);
	// 	sleep(1);
	// 	i++;
	// }
	sleep(5);
	judge = 1;
	if (pthread_join(th_mon, &th_ret) != 0)
	{
		perror("pthread_join");
		return (1);
	}
	printf("\n--------------------------------------end of main(1)\n");
	return (0);
}
