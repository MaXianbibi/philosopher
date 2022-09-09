/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:16:18 by jmorneau          #+#    #+#             */
/*   Updated: 2022/09/09 19:14:00 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"




void *print_hello(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	struct timeval time;
	struct timeval time_eat;

	gettimeofday(&time, NULL);
	gettimeofday(&time_eat, NULL);
	while (*philo->alive)
	{
		if (philo->digit & 1)
		{	
			is_thinking(philo, time);
			pthread_mutex_lock(philo->fork_left);
			take_a_fork(philo, time);
			pthread_mutex_lock(philo->fork_right); 
			take_a_fork(philo, time);
		}
		else
		{
			is_thinking(philo, time);
			pthread_mutex_lock(philo->fork_right);
			take_a_fork(philo, time);
			pthread_mutex_lock(philo->fork_left);
			take_a_fork(philo, time);
		}
		if (is_he_dead(philo, time_eat, time) != 0)
		{
			pthread_mutex_unlock(philo->fork_left);
			pthread_mutex_unlock(philo->fork_right);
			return (0);
		}
		is_eating(philo, time);
		gettimeofday(&time_eat, NULL);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		is_sleeping(philo, time);
	}
	return (NULL);
}

int thread_init(char **argv, t_global *data)
{
	int i;

	i = 0;
	(void)argv;
	while (i < data->count)
	{
		if (pthread_create(&data->philos_thread[i], NULL, print_hello, &data->philos[i]) == -1)
			return -1;
		i++;
	}
	
	i = 0;
	while (i < data->count)
	{
		pthread_join(data->philos_thread[i], NULL);
		i++;
	}
	return (0);
}