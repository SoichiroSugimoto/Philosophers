/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:49:15 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/12 12:25:22 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define ERROR -1;

# define UNUSED 1
# define USED 0

typedef struct s_philo
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	int				*fork;
	int				philo_descriptor;
	pthread_t		*philo_thread;
	pthread_mutex_t	*fork_mutex;
}				t_philo;

// ---------------------------get_struct.c
long long			my_atoi(const char *str);
int					get_struct(int argc, char **args, t_philo	*data);

// ---------------------------

#endif
