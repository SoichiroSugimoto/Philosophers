/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:49:15 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/27 19:42:22 by sosugimo         ###   ########.fr       */
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

# define ERROR -1

# define EAT 1
# define LIFE 1
# define DEATH 0

# define MALLOC_ERROR			"ERROR: malloc error\n"
# define ARGS_ERROR				"ERROR: your argument is improper\n"
# define THREAD_CREATE_ERROR	"ERROR: pthread_create() did not work well\n"

# define TAKEAFORK	"has taken a fork\n"
# define EATING		"is eating\n"
# define SLEEPING	"is sleeping\n"
# define THINKING	"is thinking\n"
# define DIED		"died\n"

int				g_starvation_flag;
long long		*g_end_of_eating;
int				g_num_of_philos;
int				g_time_to_die;
int				g_time_to_eat;
int				g_time_to_sleep;
int				g_num_of_must_eat;
int				g_philo_descriptor;
int				*g_eatcount_flag;
long long		*g_end_of_eating;
pthread_t		*g_philo_thread;
pthread_t		*g_monitor_thread;
pthread_mutex_t	*g_fork_mutex;
pthread_mutex_t	g_output_mutex;
pthread_mutex_t	g_monitor_mutex;
long long		g_death_time;
int				g_created_philoth;
int				g_created_monith;

typedef struct s_action
{
	struct timeval	time;
	int				philo_descriptor;
	int				num_of_forks;
}				t_action;

// ---------------------------  philo.c

// ---------------------------  args_error_handle.c
void			malloc_error_deal(void *mem);
int				pthread_create_error(void);
int				numrange_error(char *num);
int				args_error(int argc, char **args);

// ---------------------------  init_gval.c
long long		my_atoi(const char *str);
void			set_mutex(void);
int				init_gval(int argc, char **args);

// ---------------------------  init_gval2.c
void			init_g_end_of_eating(void);

// ---------------------------  create_thread.c
void			*moni_thread_routine(void *arg);
void			*philo_thread_routine(void *arg);
void			create_thread(void);

// ---------------------------  actions.c
void			output_with_mutex(int x, struct timeval	time, char *message);
void			xiseating(t_action *data);
void			xissleeping(t_action *data);
void			xisthinking(t_action *data);

// ---------------------------  terminator.c
void			terminate_all(void);
void			*terminator_thread(void *arg);
void			create_terminator(void);

// ---------------------------  utils.c
int				get_total(int *array, int len);
void			ft_usleep(t_action	*data, long long	sleep_ms);
long long		get_timemsec(struct timeval	time);

#endif
