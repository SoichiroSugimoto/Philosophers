#include "philo.h"

void	print_gval(void)
{
	int	i;

	i = 0;
	printf("==================================\n");
	printf("g_starvation_flag :    %d\n", g_starvation_flag);
	printf("g_num_of_philos   :    %d\n", g_num_of_philos);
	printf("g_time_to_die     :    %d\n", g_time_to_die);
	printf("g_time_to_eat     :    %d\n", g_time_to_eat);
	printf("g_time_to_sleep   :    %d\n", g_time_to_sleep);
	printf("g_num_of_must_eat :    %d\n", g_num_of_must_eat);
	printf("g_philo_descriptor:    %d\n", g_philo_descriptor);
	printf("g_eat_counter     :    %d\n", g_eat_counter);
	while (i < g_num_of_philos)
	{
		printf("g_philo_thread[i]  :   %p\n", &(g_philo_thread[i]));
		i++;
	}
	printf("==================================\n");
	printf("\n\n\n\n");
}
