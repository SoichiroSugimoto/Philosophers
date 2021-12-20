/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:52:28 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/20 20:02:03 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(struct timeval	start, long long	sleep_ms)
{
	struct timeval	now;

	start = (long long)start.tv_sec * 1000 + (long long)start.tv_usec / 1000;
	while (1)
	{
		gettimeofday(now, NULL);
		now = (long long)now.tv_sec * 1000 + (long long)now.tv_usec / 1000;
		if (now - start >= sleep_ms)
			break ;
		usleep(200);
	}
}

long long	get_timesec(struct timeval	time)
{
	long long	ms;

	ms = (long long)time.tv_sec * 1000 + (long long)time.tv_usec / 1000;
	return (ms);
}
