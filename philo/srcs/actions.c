/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:59:10 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/30 17:40:05 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	output_with_mutex(int x, struct timeval	time, char *message)
{
	pthread_mutex_lock(&g_output_mutex);
	if (g_starvation_flag == LIFE)
		printf("%lld %d %s", get_timemsec(time), x, message);
	pthread_mutex_unlock(&g_output_mutex);
}

void	xiseating(t_action *data)
{
	int	pd;
	int	fork1;
	int	fork2;

	pd = data->philo_descriptor;
	fork1 = pd - 2;
	if (fork1 < 0)
		fork1 = g_num_of_philos - 1;
	fork2 = pd - 1;
	pthread_mutex_lock(&(g_fork_mutex[fork1]));
	gettimeofday(&(data->time), NULL);
	output_with_mutex(pd, data->time, TAKEAFORK);
	pthread_mutex_lock(&(g_fork_mutex[fork2]));
	gettimeofday(&(data->time), NULL);
	output_with_mutex(pd, data->time, TAKEAFORK);
	gettimeofday(&(data->time), NULL);
	g_end_of_eating[pd - 1] = get_timemsec(data->time);
	output_with_mutex(pd, data->time, EATING);
	gettimeofday(&(data->time), NULL);
	ft_usleep(data, g_time_to_eat);
	pthread_mutex_unlock(&(g_fork_mutex[fork2]));
	pthread_mutex_unlock(&(g_fork_mutex[fork1]));
}

void	xissleeping(t_action *data)
{
	int			pd;

	pd = data->philo_descriptor;
	output_with_mutex(pd, data->time, SLEEPING);
}

void	xisthinking(t_action *data)
{
	int			pd;

	pd = data->philo_descriptor;
	ft_usleep(data, g_time_to_sleep);
	output_with_mutex(pd, data->time, THINKING);
}
