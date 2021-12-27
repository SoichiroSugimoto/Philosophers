/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:11:55 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/27 19:19:47 by sosugimo         ###   ########.fr       */
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

	if (init_gval(argc, argv) == ERROR)
		return (0);
	print_gval();
	if (is_numof_philo_one() == 1)
		return (0);
	if (pthread_create(&tmn_thread, NULL, terminator_thread, 0) != 0)
	{
		printf(THREAD_CREATE_ERROR);
		return (0);
	}
	create_thread();
	pthread_join(tmn_thread, NULL);
	if (g_num_of_must_eat == -1)
		printf("%lld %d %s", g_death_time, g_starvation_flag, DIED);
	return (0);
}
