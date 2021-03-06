/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:56:35 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/27 14:41:27 by sosugimo         ###   ########.fr       */
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
			while (i < g_num_of_philos)
			{
				pthread_detach(g_philo_thread[i]);
				pthread_detach(g_monitor_thread[i]);
				i++;
			}
			break ;
		}
		usleep(200);
	}
	return (arg);
}
