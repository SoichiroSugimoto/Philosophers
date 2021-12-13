/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:24:23 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/12 12:24:49 by sosugimo         ###   ########.fr       */
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

int	get_struct(int argc, char **args, t_philo	*data)
{
	data->num_of_philos = (int)my_atoi(args[1]);
	data->time_to_die = (int)my_atoi(args[2]);
	data->time_to_eat = (int)my_atoi(args[3]);
	data->time_to_sleep = (int)my_atoi(args[4]);
	if (argc == 6)
		data->num_of_must_eat = (int)my_atoi(args[5]);
	else
		data->num_of_must_eat = -1;
	data->philo_descriptor = 0;
	data->philo_thread
		= (pthread_t *)malloc(sizeof(pthread_t) * data->num_of_philos);
	data->fork_mutex
		= (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t) * data->num_of_philos);
	return (1);
}
