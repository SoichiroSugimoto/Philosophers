/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:52:28 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/27 19:29:08 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_total(int *array, int len)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < len && g_eatcount_flag != NULL)
	{
		res += array[i];
		i++;
	}
	return (res);
}

void	ft_usleep(t_action	*data, long long	sleep_ms)
{
	struct timeval	start;
	long long		now_ms;
	long long		start_ms;

	start = data->time;
	start_ms = (long)start.tv_sec * 1000 + (long)start.tv_usec / 1000;
	while (1)
	{
		gettimeofday(&(data->time), NULL);
		now_ms = (long)(data->time).tv_sec * 1000
			+ (long)(data->time).tv_usec / 1000;
		if (now_ms - start_ms >= sleep_ms)
			break ;
		usleep(200);
	}
}

long long	get_timemsec(struct timeval	time)
{
	long long	ms;

	ms = (long)time.tv_sec * 1000 + (long)time.tv_usec / 1000;
	return (ms);
}
