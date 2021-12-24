/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:52:28 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/24 13:12:01 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	ft_usleep(struct timeval	start, long long	sleep_ms)
// {
// 	struct timeval	now;
// 	long long		now_ms;
// 	long long		start_ms;

// 	start_ms = (long)start.tv_sec * 1000 + (long)start.tv_usec / 1000;
// 	while (1)
// 	{
// 		gettimeofday(&now, NULL);
// 		now_ms = (long)now.tv_sec * 1000 + (long)now.tv_usec / 1000;
// 		if (now_ms - start_ms >= sleep_ms)
// 		{
// 			// printf("           start_ms:  %lld        now_ms:  %lld\n", start_ms, now_ms);
// 			break ;
// 		}
// 		usleep(200);
// 	}
// }

void	ft_usleep(t_action	*data, long long	sleep_ms)
{
	struct timeval	start;
	// struct timeval	now;
	long long		now_ms;
	long long		start_ms;

	start = data->time;
	start_ms = (long)start.tv_sec * 1000 + (long)start.tv_usec / 1000;
	while (1)
	{
		gettimeofday(&(data->time), NULL);
		now_ms = (long)(data->time).tv_sec * 1000 + (long)(data->time).tv_usec / 1000;
		if (now_ms - start_ms >= sleep_ms)
		{
			// printf("           start_ms:  %lld        now_ms:  %lld\n", start_ms, now_ms);
			break ;
		}
		usleep(200);
	}
}

long long	get_timemsec(struct timeval	time)
{
	long long	ms;

	ms = (long)time.tv_sec * 1000 + (long)time.tv_usec / 1000;
	return (ms);
}

// 3 20 5 10
