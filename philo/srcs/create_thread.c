/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:58:15 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/20 19:37:37 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*moni_thread_routine(void *arg)
{
}

void	*philo_thread_routine(void *arg)
{
	int	pd;

	pd = (int)arg + 1;
	if (pthread_create(&(g_monitor_thread[(int)arg]), NULL,
			moni_thread_routine, (void *)data) != 0)
	{
		perror("pthread_create");
		return (1);
	}
	while (1)
	{
		iseating();
		issleeping();
		isthinking();
	}
	return (NULL);
}

int	create_thread(void)
{
	int	i;

	i = 0;
	while (i < g_num_of_philos)
	{
		if (pthread_create(&(g_philo_thread[i]), NULL,
				philo_thread_routine, (void *)i) != 0)
		{
			perror("pthread_create");
			return (1);
		}
		i++;
	}
}
