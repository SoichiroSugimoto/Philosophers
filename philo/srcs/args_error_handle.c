/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_error_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:11:47 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/28 15:37:52 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	intrange_error(void)
{
	if (g_num_of_philos < 0
		|| g_time_to_die < 0
		|| g_time_to_eat < 0
		|| g_time_to_sleep < 0)
	{
		printf(ARGS_ERROR);
		return (ERROR);
	}
	if (g_num_of_must_eat < -1)
	{
		printf(ARGS_ERROR);
		return (ERROR);
	}
	return (1);
}

void	malloc_error_deal(void *mem)
{
	if (mem == NULL)
	{
		g_starvation_flag = 1;
		printf(MALLOC_ERROR);
	}
}

int	pthread_create_error(void)
{
	int	i;

	i = 0;
	while (i < g_created_philoth)
	{
		pthread_detach(g_philo_thread[i]);
		if (i < g_created_monith)
			pthread_detach(g_monitor_thread[i]);
		i++;
	}
	printf(THREAD_CREATE_ERROR);
	return (ERROR);
}

int	numrange_error(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!('0' <= num[i] && num[i] <= '9'))
		{
			printf(ARGS_ERROR);
			return (ERROR);
		}
		i++;
	}
	return (1);
}

int	args_error(int argc, char **args)
{
	int	i;
	int	res;

	i = 1;
	res = 1;
	if (4 >= argc || argc >= 7)
	{
		printf(ARGS_ERROR);
		return (ERROR);
	}
	while (i < argc)
	{
		if (numrange_error(args[i]) == ERROR)
			return (ERROR);
		i++;
	}
	return (1);
}
