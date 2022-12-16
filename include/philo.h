/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:33:00 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/15 19:27:34 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./color.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

enum	e_action
{
	SLEEP,
	EAT,
	THINK,
	FORK,
	DIE
};

struct s_atime
{
	int die_t;
	int eat_t;
	int sleep_t;
	int neat_t;
};
typedef struct s_atime t_atime;

struct s_fork
{
	pthread_mutex_t fork;
	int				in_use;
};
typedef struct s_fork t_fork;

struct s_philo
{
		t_fork				*fork_right;
		t_fork				*fork_left;
		pthread_mutex_t		*superviseur;
		time_t				last_meal;
		int 				digit;
		char				**arg;
		int					*alive;
		t_atime				time;
};
typedef struct s_philo t_philo;

struct s_global
{
	t_fork				*fork;
	pthread_t			*philos_thread;
	t_philo				*philos;
	pthread_mutex_t		superviseur;
	int					time_delay;
	int					count;
	int					alive;
};
typedef struct s_global t_global;

int	ft_atoi(char *str);
int thread_init(char **argv, t_global *data);
int data_init(t_global *data, char **argv);

// actions
void action (t_philo *philo, time_t time, int digit, time_t action_time, time_t time_eat);

// time gestion
void 	philo_action_time(t_philo *philo, time_t action_time, time_t eat_time, time_t time);
time_t	get_time_in_ms(void);
int checkifdead(t_philo *philo, time_t eat_time, time_t time);
int checkifneat(t_philo *philo);

#endif