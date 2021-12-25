/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_error_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:11:47 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/25 16:04:53 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (4 > argc || argc > 5)
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
