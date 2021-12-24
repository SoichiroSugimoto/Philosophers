/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:56:35 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/24 14:55:14 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	terminate_all(void)
{
	int	i;

	i = 0;
	while (i < g_num_of_philos)
	{
		pthread_detach(g_philo_thread[i]);
		pthread_detach(g_monitor_thread[i]);
		i++;
	}
	pthread_mutex_lock(&g_output_mutex);
	printf("%lld %d %s", g_death_time, g_starvation_flag, DIED);
	pthread_mutex_unlock(&g_output_mutex);
}

void	*terminator_thread(void *arg)
{
	while (1)
	{
		if (g_starvation_flag != LIFE)
		{
			printf("                   [terminator_thread] Recognize death of a philosopher.\n");
			terminate_all();
			break ;
		}
		usleep(200);
	}
	return (arg);
}

void	create_terminator(void)
{
	pthread_t	tmn_thread;

	if (pthread_create(&tmn_thread, NULL,
			terminator_thread, 0) != 0)
	{
		perror("pthread_create");
		return ;
	}
	printf("[start]    --------------- terminator\n");
	pthread_join(tmn_thread, NULL);
	printf("[finish]   --------------- terminator\n");
}
