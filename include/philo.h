/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:33:00 by jmorneau          #+#    #+#             */
/*   Updated: 2022/09/09 19:04:12 by jmorneau         ###   ########.fr       */
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

struct s_philo
{
		pthread_mutex_t *fork_right;
		pthread_mutex_t *fork_left;
		int 			digit;
		char			 **arg;
		int				*alive;
};
typedef struct s_philo t_philo;

struct s_global
{
	pthread_mutex_t *fork;
	pthread_t		*philos_thread;
	t_philo			*philos;
	int				count;
};
typedef struct s_global t_global;

int	ft_atoi(char *str);
int thread_init(char **argv, t_global *data);
int data_init(t_global *data, char **argv);

// actions
void take_a_fork(t_philo *philo, struct timeval time);
void is_eating(t_philo *philo, struct timeval time);
void is_sleeping(t_philo *philo, struct timeval time);
void is_thinking(t_philo *philo, struct timeval time);
int is_he_dead(t_philo *philo, struct timeval time_eat, struct timeval time);

#endif