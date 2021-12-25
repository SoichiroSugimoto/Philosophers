/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:56:35 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/25 18:12:44 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*terminator_thread(void *arg)
{
	int	i;

	i = 0;
	while (1)
	{
		if (g_starvation_flag != LIFE)
		{
			printf("[terminator_thread] Recognize death of a philosopher.\n");
			while (i < g_num_of_philos)
			{
				// pthread_mutex_lock(&g_output_mutex);
				pthread_detach(g_philo_thread[i]);
				pthread_detach(g_monitor_thread[i]);
				i++;
				// pthread_mutex_unlock(&g_output_mutex);
			}
			break ;
		}
		usleep(200);
	}
	return (arg);
}
