/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:11:47 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/11 19:39:55 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	argc_error(int argc)
{
	if (argc < 4)
	{
		printf("Errror : The number of arguments is too small.")
		return (ERROR);
	}
	if (argc > 5)
	{
		printf("Errror : The number of arguments is too many.")
		return (ERROR);
	}
	return (1);
}

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
