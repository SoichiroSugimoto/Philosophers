/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:59:10 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/21 10:42:47 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	output_with_mutex(int x, struct timeval	time, char *message)
{
	pthread_mutex_lock(&g_output_mutex);
	printf("%lld %d %s\n", get_timemsec(data->time), x, message);
	pthread_mutex_unlock(&g_output_mutex);
}

void	xiseating(t_action *data)
{
	int			pd;
	int			i;

	pd = data->philo_descriptor;
	i = pd - 1;
	if (i <= 0)
		i = g_num_of_philos;
	pthread_mutex_lock(&(g_fork_mutex[i]));
	gettimeofday(&(data->time), NULL);
	output_with_mutex(pd, data->time, TAKEAFORK);
	pthread_mutex_lock(&(g_fork_mutex[pd]));
	gettimeofday(&(data->time), NULL);
	output_with_mutex(pd, data->time, TAKEAFORK);
	output_with_mutex(pd, data->time, EATING);
	pthread_mutex_unlock(&(g_fork_mutex[pd]));
	pthread_mutex_unlock(&(g_fork_mutex[i]));
}

void	xissleeping(t_action *data)
{
	int			pd;

	pd = data->philo_descriptor;
	ft_usleep(data->time, g_time_to_eat);
	g_end_of_eating[pd - 1] = get_timemsec(data->time);
	output_with_mutex(pd, data->time, SLEEPING);
}

void	xisthinking(t_action *data)
{
	int			pd;

	pd = data->philo_descriptor;
	ft_usleep(data->time, g_time_to_sleep);
	output_with_mutex(pd, data->time, THINKING);
}
