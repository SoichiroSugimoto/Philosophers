/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:49:15 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/20 19:16:10 by sosugimo         ###   ########.fr       */
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

# define LIFE 1
# define DEATH 0

int				g_starvation_flag;
long long		*g_end_of_eating;
int				g_num_of_philos;
int				g_time_to_die;
int				g_time_to_eat;
int				g_time_to_sleep;
int				g_num_of_must_eat;
int				g_eat_counter;
long long		*g_end_of_eating;
pthread_t		*g_philo_thread;
pthread_t		*g_monitor_thread;
pthread_mutex_t	*g_fork_mutex;
pthread_mutex_t	g_output_mutex;

typedef struct s_monitor
{
	struct timeval	time;
	int				philo_descriptor;
}				t_monitor;

// typedef struct s_philo
// {
// 	// 全部g_valでよくね？
// 	int				num_of_philos;
// 	int				time_to_die;
// 	int				time_to_eat;
// 	int				time_to_sleep;
// 	int				num_of_must_eat;
// 	long long		*end_of_eating;

// 	pthread_t		*philo_thread;
// 	pthread_t		*monitor_thread;
// 	pthread_mutex_t	*fork_mutex;
// 	pthread_mutex_t	output_mutex;
// }				t_philo;

// ---------------------------args_error_handle.c
int					numrange_error(char *num);
int					args_error(int argc, char **argv);

// ---------------------------get_struct.c
long long			my_atoi(const char *str);
void				set_mutex(t_philo *data);
int					get_struct(int argc, char **args, t_philo	*data);

#endif
