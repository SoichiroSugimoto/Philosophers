/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_error_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:11:47 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/21 15:22:18 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	numrange_error(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!(0 <= num[i] && num[i] <= 9))
		{
			printf("Errror : Arguments format is not appropriate.");
			return (ERROR);
		}
		i++;
	}
	return (1);
}

int	args_error(int argc, char **argv)
{
	int	i;
	int	res;

	i = 1;
	res = 1;
	if (argc < 4)
	{
		printf("Errror : The number of arguments is too small.");
		return (ERROR);
	}
	if (argc > 5)
	{
		printf("Errror : The number of arguments is too many.");
		return (ERROR);
	}
	while (i < argc)
	{
		res = numrange_error(argv[i]);
		i++;
	}
	return (res);
}
