/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:58:15 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/25 16:56:17 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*moni_thread_routine(void *arg)
{
	int				i;
	t_action		*data;
	struct timeval	now;
	long long		now_ms;

	i = 0;
	data = (t_action *)arg;
	while (i < g_num_of_philos)
	{
		g_end_of_eating[i] = -1;
		i++;
	}
	while (1)
	{
		gettimeofday(&now, NULL);
		now_ms = get_timemsec(now);
		if (now_ms - g_end_of_eating[data->philo_descriptor - 1]
			> g_time_to_die
			&& g_end_of_eating[data->philo_descriptor - 1] != -1)
		{
			pthread_mutex_lock(&g_output_mutex);
			g_starvation_flag = data->philo_descriptor;
			g_death_time = now_ms;
			pthread_mutex_unlock(&g_output_mutex);
		}
		usleep(200);
	}
}

void	*philo_thread_routine(void *arg)
{
	int			pd;
	t_action	*data;

	pthread_mutex_lock(&g_output_mutex);
	pd = g_philo_descriptor;
	g_philo_descriptor++;
	pthread_mutex_unlock(&g_output_mutex);
	data = (t_action *)malloc(sizeof(t_action));
	data->philo_descriptor = pd + 1;
	data->num_of_forks = 0;
	gettimeofday(&(data->time), NULL);
	g_end_of_eating[pd] = get_timemsec(data->time);
	if (pthread_create(&(g_monitor_thread[pd]), NULL,
			moni_thread_routine, (void *)data) != 0)
	{
		perror("pthread_create");
		return (NULL);
	}
	if (pd % 2 == 1)
		usleep(200);
	while (1)
	{
		xiseating(data);
		xissleeping(data);
		xisthinking(data);
	}
	return (arg);
}

void	create_thread(void)
{
	int	i;

	i = 0;
	while (i < g_num_of_philos)
	{
		// printf("g_philo_thread[i] : %p\n", &(g_philo_thread[i]));
		// printf("i :  %d\n", i);
		if (pthread_create(&(g_philo_thread[i]), NULL,
				philo_thread_routine, NULL) != 0)
		{
			perror("pthread_create");
			return ;
		}
		i++;
	}
}
