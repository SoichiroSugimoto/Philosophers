/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:11:55 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/24 15:51:43 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	main(int argc, char *argv[])
// {
// 	init_gval(argc, argv);
// 	print_gval();
// 	create_terminator();
// 	create_thread();
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	pthread_t	tmn_thread;

	init_gval(argc, argv);
	print_gval();
	if (pthread_create(&tmn_thread, NULL,
			terminator_thread, 0) != 0)
	{
		perror("pthread_create");
		return (0);
	}
	create_thread();
	printf("[start]    --------------- terminator\n");
	pthread_join(tmn_thread, NULL);
	printf("[finish]   --------------- terminator\n");
	pthread_mutex_lock(&g_output_mutex);
	printf("######################## \n\n");
	printf("%lld %d %s", g_death_time, g_starvation_flag, DIED);
	printf("\n########################\n");
	pthread_mutex_unlock(&g_output_mutex);
	return (0);
}
