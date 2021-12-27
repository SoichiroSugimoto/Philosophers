/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_error_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:11:47 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/27 19:00:24 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			return (ERROR);
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
	printf("argc :  %d\n", argc);
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
