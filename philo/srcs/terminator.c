/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:56:35 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/21 09:45:01 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	terminate_all(void)
{
	int	i;

	i = 0;
	while (i < g_num_of_philos)
	{
		pthread_detach(&(g_philo_thread[i]));
		pthread_detach(&(g_monitor_thread[i]));
		i++;
	}
}

void	*terminator_thread(void *arg)
{
	while (1)
	{
		if (g_starvation_flag == DEATH)
		{
			terminate_all();
			break ;
		}
		usleep(200);
	}
	return (NULL);
}

int	create_terminator(void)
{
	pthread_t	terminator_thread;

	if (pthread_create(&terminator_thread, NULL,
			terminator_thread, (void *)i) != 0)
	{
		perror("pthread_create");
		return (1);
	}
	pthread_join(terminator_thread, NULL);
}
