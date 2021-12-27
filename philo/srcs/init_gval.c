/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:24:23 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/27 18:57:56 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	my_atoi(const char *str)
{
	long long	res;
	int			i;
	int			sign;

	res = 0;
	i = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((0 <= str[i] && str[i] <= 47) || (58 <= str[i] && str[i] <= 127))
			return (0);
		res = res * 10;
		res += (int)str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	set_mutex(void)
{
	int	i;

	i = 0;
	g_fork_mutex = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * g_num_of_philos);
	while (i < g_num_of_philos)
	{
		pthread_mutex_init(&((g_fork_mutex)[i]), NULL);
		i++;
	}
	pthread_mutex_init(&g_output_mutex, NULL);
	pthread_mutex_init(&g_monitor_mutex, NULL);
}

int	init_eatcount_flag(void)
{
	int	i;

	i = 0;
	if (g_num_of_must_eat != -1)
	{
		g_eatcount_flag = (int *)malloc(sizeof(int) * g_num_of_philos);
		if (g_monitor_thread == NULL)
		{
			printf(MALLOC_ERROR);
			return (ERROR);
		}
		while (i < g_num_of_philos)
		{
			g_eatcount_flag[i] = 0;
			i++;
		}
	}
	return (1);
}

int	gval_malloc(void)
{
	g_end_of_eating
		= (long long *)malloc(sizeof(long long) * g_num_of_philos);
	if (g_end_of_eating == NULL)
	{
		printf(MALLOC_ERROR);
		return (ERROR);
	}
	g_philo_thread
		= (pthread_t *)malloc(sizeof(pthread_t) * g_num_of_philos);
	if (g_philo_thread == NULL)
	{
		printf(MALLOC_ERROR);
		free(g_end_of_eating);
		return (ERROR);
	}
	g_monitor_thread
		= (pthread_t *)malloc(sizeof(pthread_t) * g_num_of_philos);
	if (g_monitor_thread == NULL)
	{
		printf(MALLOC_ERROR);
		free(g_end_of_eating);
		free(g_philo_thread);
		return (ERROR);
	}
	return (1);
}

int	init_gval(int argc, char **args)
{
	if (args_error(argc, args) == ERROR)
		return (ERROR);
	g_starvation_flag = LIFE;
	g_num_of_philos = (int)my_atoi(args[1]);
	g_time_to_die = (int)my_atoi(args[2]);
	g_time_to_eat = (int)my_atoi(args[3]);
	g_time_to_sleep = (int)my_atoi(args[4]);
	if (argc == 6)
		g_num_of_must_eat = (int)my_atoi(args[5]);
	else
		g_num_of_must_eat = -1;
	g_philo_descriptor = 0;
	if (gval_malloc() == ERROR || init_eatcount_flag() == ERROR)
		return (ERROR);
	g_end_of_eating();
	set_mutex();
	g_death_time = 0;
	g_created_philoth = 0;
	g_created_monith = 0;
	return (1);
}
