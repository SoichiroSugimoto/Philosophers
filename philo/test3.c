#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

// while の条件とmutexの組み合わせについて

int	global_val = 0;
int judge = 0;

void	*thread_start_routine(void *data)
{
	int n = (int)data;
	int	val = 100;
	int	i;

	i = 0;
	while (global_val < 20 && judge == 0)
	{
		global_val++;
		i++;
		printf("[%d] thread_start_routine : i=%d, g=%d\n", n, i, global_val);
		sleep(1);
	}
	return (NULL);
}

void	*thread_start_routine2(void *data)
{
	int n = (int)data;
	int	val = 100;
	int	i;

	i = 0;
	while (global_val < 20 && judge == 0)
	{
		global_val++;
		i++;
		printf("[%d] thread_start_routine : i=%d, g=%d\n", n, i, global_val);
		sleep(1);
	}
	return (NULL);
}

int	main(void)
{
	int			i;
	pthread_t	th;
	pthread_t	th2;
	void		*th_ret;

	if (pthread_create(&th, NULL, thread_start_routine, (void *)1) != 0)
	{
		perror("pthread_create");
		return (1);
	}
	if (pthread_create(&th2, NULL, thread_start_routine2, (void *)2) != 0)
	{
		perror("pthread_create");
		return (1);
	}
	printf("--------------------------------------------------------------\n");
	for (i=0; i<10; i++)
	{
		global_val++;
		printf("\n+++++++++++++  main : i=%d, g=%d\n", i, global_val);
		sleep(1);
	}
	if (pthread_detach(th) != 0)
	{
		perror("pthread_join");
		return (1);
	}
	printf("\n--------------------------------------end of main\n");
	return (0);
}
