#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

// while の条件とmutexの組み合わせについて

// int	global_val = 0;
// int judge = 0;

typedef struct thread_data
{
	int	global_val;
	int	judge;
	int	p;
}				t_data;

void	*thread_start_routine(void *data)
{
	int	val = 100;
	int	i;
	t_data *t_data;

	t_data = (t_data *)data;
	i = 0;
	while (t_data->global_val < 20 && t_data->judge == 0)
	{
		t_data->global_val++;
		i++;
		printf("[1] thread_start_routine : i=%d, g=%d\n", i, t_data->global_val);
		sleep(1);
	}
	return (NULL);
}

void	*thread_start_routine2(void *data)
{
	int	val = 100;
	int	i;
	t_data *t_data;

	t_data = (t_data *)data;
	i = 0;
	while (t_data->global_val < 20 && judge == 0)
	{
		t_data->global_val++;
		i++;
		printf("[2] thread_start_routine : i=%d, g=%d\n", i, t_data->global_val);
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
	t_data *t_data;

	t_data = (t_data *)malloc(sizeof(t_data));
	t_data->global_val = 0;
	t_data->judge = 0;
	if (pthread_create(&th, NULL, thread_start_routine, (void *)t_data) != 0)
	{
		perror("pthread_create");
		return (1);
	}
	if (pthread_create(&th2, NULL, thread_start_routine2, (void *)t_data) != 0)
	{
		perror("pthread_create");
		return (1);
	}
	printf("--------------------------------------------------------------\n");
	for (i=0; i<10; i++)
	{
		t_data->global_val++;
		printf("\n+++++++++++++  main : i=%d, g=%d\n", i, t_data->global_val);
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
