/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:33:00 by jmorneau          #+#    #+#             */
/*   Updated: 2022/09/02 17:13:47 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
#include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

struct s_philo
{
		pthread_mutex_t fork_right;
		pthread_mutex_t fork_left;
		int 			digit;
};
typedef struct s_philo t_philo;

struct s_global
{
	pthread_mutex_t *fork;
	pthread_t		*nb_philos;
	t_philo			*philos;
	int				nphilo;
};
typedef struct s_global t_global;


int	ft_atoi(const char *str);
int thread_init(char **argv, t_global *data);
int data_init(t_global *data, char **argv);

#endif