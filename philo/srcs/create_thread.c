/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:58:15 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/21 10:10:25 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*moni_thread_routine(void *arg)
{
	struct timeval	now;
	long long		now_ms;

	while (1)
	{
		gettimeofday(&now, NULL);
		now_ms = get_timesec(now);
		if (g_end_of_eating[(int)arg] - now >= g_time_to_die)
			g_starvation_flag = DEATH;
		usleep(200);
	}
}

void	*philo_thread_routine(void *arg)
{
	int			pd;
	t_action	*data;

	pd = (int)arg + 1;
	data = (t_action *)malloc(sizeof(t_action));
	data->philo_descriptor = pd;
	data->num_of_forks = 0;
	if (pthread_create(&(g_monitor_thread[(int)arg]), NULL,
			moni_thread_routine, (void *)data) != 0)
	{
		perror("pthread_create");
		return (1);
	}
	while (1)
	{
		iseating(data);
		issleeping(data);
		isthinking(data);
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
