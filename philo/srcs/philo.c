/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:11:55 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/25 18:42:00 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_numof_philo_one(void)
{
	struct timeval	time;

	if (g_num_of_philos == 1)
	{
		gettimeofday(&time, NULL);
		output_with_mutex(1, time, DIED);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	pthread_t		tmn_thread;
	int i = 0;

	if (init_gval(argc, argv) == ERROR)
		return (0);
	print_gval();
	if (is_numof_philo_one() == 1)
		return (0);
	if (pthread_create(&tmn_thread, NULL, terminator_thread, 0) != 0)
	{
		perror("pthread_create");
		return (0);
	}
	create_thread();
	printf("[start]    --------------- terminator\n");
	pthread_join(tmn_thread, NULL);
	printf("[finish]   --------------- terminator\n");
	// pthread_mutex_lock(&g_output_mutex);
	printf("####################### \n\n");
	printf("%lld %d %s", g_death_time, g_starvation_flag, DIED);
	printf("\n#######################\n");
	// pthread_mutex_unlock(&g_output_mutex);
	while (i < g_num_of_philos)
	{
		printf("Philo[%d] :   %lld   + 800 + 1 =  %lld\n", i, g_end_of_eating[i], g_end_of_eating[i] + 801);
		i++;
	}
	return (0);
}
