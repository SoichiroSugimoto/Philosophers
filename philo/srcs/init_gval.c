/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:24:23 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/25 16:05:02 by sosugimo         ###   ########.fr       */
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
	pthread_mutex_init(&(g_output_mutex), NULL);
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
	g_eat_counter = 0;
	g_philo_descriptor = 0;
	g_end_of_eating
		= (long long *)malloc(sizeof(long long) * g_num_of_philos);
	g_philo_thread
		= (pthread_t *)malloc(sizeof(pthread_t) * g_num_of_philos);
	g_monitor_thread
		= (pthread_t *)malloc(sizeof(pthread_t) * g_num_of_philos);
	set_mutex();
	g_death_time = 0;
	return (1);
}
