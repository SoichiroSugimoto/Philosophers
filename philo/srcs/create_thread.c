/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:58:15 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/27 19:36:19 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eatcnt_checker(void)
{
	int	i;

	i = 0;
	if (g_eatcount_flag == NULL)
		return (-1);
	while (i < g_num_of_philos)
	{
		if (g_eatcount_flag[i] < g_num_of_must_eat)
			return (-1);
		i++;
	}
	return (1);
}

void	*moni_thread_routine(void *arg)
{
	t_action		*data;
	struct timeval	now;
	long long		now_ms;

	pthread_mutex_lock(&g_output_mutex);
	g_created_monith++;
	pthread_mutex_unlock(&g_output_mutex);
	data = (t_action *)arg;
	while (1)
	{
		gettimeofday(&now, NULL);
		now_ms = get_timemsec(now);
		if ((now_ms - g_end_of_eating[data->philo_descriptor - 1]
				> g_time_to_die
				&& g_end_of_eating[data->philo_descriptor - 1] != -1)
			|| eatcnt_checker() == 1)
		{
			pthread_mutex_lock(&g_monitor_mutex);
			g_starvation_flag = data->philo_descriptor;
			g_death_time = now_ms;
			pthread_mutex_unlock(&g_monitor_mutex);
		}
		usleep(200);
	}
}

int	philo_thread_routine_util(t_action *data)
{
	int	pd;

	pthread_mutex_lock(&g_output_mutex);
	g_created_philoth++;
	pd = g_philo_descriptor;
	g_philo_descriptor++;
	pthread_mutex_unlock(&g_output_mutex);
	gettimeofday(&(data->time), NULL);
	g_end_of_eating[pd] = get_timemsec(data->time);
	data->philo_descriptor = pd + 1;
	data->num_of_forks = 0;
	return (pd);
}

void	*philo_thread_routine(void *arg)
{
	int			pd;
	t_action	*data;

	data = (t_action *)malloc(sizeof(t_action));
	malloc_error_deal(data);
	pd = philo_thread_routine_util(data);
	if (pthread_create(&(g_monitor_thread[pd]), NULL,
			moni_thread_routine, (void *)data) != 0)
		pthread_create_error();
	if (pd % 2 == 1)
		usleep(200);
	while (1)
	{
		xiseating(data);
		if (g_num_of_must_eat != -1)
		{
			pthread_mutex_lock(&g_monitor_mutex);
			g_eatcount_flag[pd] += EAT;
			pthread_mutex_unlock(&g_monitor_mutex);
		}
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
		if (pthread_create(&(g_philo_thread[i]), NULL,
				philo_thread_routine, NULL) != 0)
			pthread_create_error();
		i++;
	}
}
