/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:59:10 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/24 15:45:10 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	output_with_mutex(int x, struct timeval	time, char *message)
{
	pthread_mutex_lock(&g_output_mutex);
	// if (x == 1)
	// 	printf("   ----------   :  ");
	if (g_starvation_flag == LIFE)
		printf("%lld %d %s", get_timemsec(time), x, message);
	pthread_mutex_unlock(&g_output_mutex);
}

void	xiseating(t_action *data)
{
	int			pd;
	int			i;

	pd = data->philo_descriptor;
	i = pd - 2;
	if (i <= 0)
		i = g_num_of_philos - 1;
	// printf("i :  %d      pd :  %d\n", i, pd);
	pthread_mutex_lock(&(g_fork_mutex[i]));
	gettimeofday(&(data->time), NULL);
	output_with_mutex(pd, data->time, TAKEAFORK);
	pthread_mutex_lock(&(g_fork_mutex[pd - 1]));
	gettimeofday(&(data->time), NULL);
	output_with_mutex(pd, data->time, TAKEAFORK);
	output_with_mutex(pd, data->time, EATING);
	ft_usleep(data, g_time_to_eat);
	g_end_of_eating[pd - 1] = get_timemsec(data->time);
	pthread_mutex_unlock(&(g_fork_mutex[pd - 1]));
	pthread_mutex_unlock(&(g_fork_mutex[i]));
}

void	xissleeping(t_action *data)
{
	int			pd;

	pd = data->philo_descriptor;
	// printf("-------------  pd  : %d\n", pd);
	output_with_mutex(pd, data->time, SLEEPING);
}

void	xisthinking(t_action *data)
{
	int			pd;

	pd = data->philo_descriptor;
	ft_usleep(data, g_time_to_sleep);
	output_with_mutex(pd, data->time, THINKING);
}
