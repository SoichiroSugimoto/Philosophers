#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	global_val = 0;

void	*thread_start_routine(void *data)
{
	int	val = (int)data;
	int	i;

	printf("● ● ● ● ● ● ● ● ● ● thread_start_routine : val=%d\n", val);
	for (i=0; i<10; i++) {
		global_val++;
		printf("thread_start_routine : i=%d, g=%d\n", i, global_val);
		sleep(2);
	}
	printf("end of start_routine(func)\n");
	return (NULL);
}

int	main(void)
{
	int			i;
	pthread_t	th;
	void		*th_ret;

	if (pthread_create(&th, NULL, thread_start_routine, (void *)100) != 0)
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
	if (pthread_join(th, &th_ret) != 0)
	{
		perror("pthread_join");
		return (1);
	}
	printf("\n--------------------------------------end of main\n");
	return (0);
}
