/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:56:35 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/24 12:13:15 by sosugimo         ###   ########.fr       */
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
}

void	*terminator_thread(void *arg)
{
	while (1)
	{
		if (g_starvation_flag == DEATH)
		{
			printf("[terminator_thread] Recognize death of a philosopher.\n");
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
