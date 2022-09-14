/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:16:18 by jmorneau          #+#    #+#             */
/*   Updated: 2022/09/13 21:41:32 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void atime_init(t_atime *atime, char **arg)
{
	atime->die_t = ft_atoi(arg[2]);
	atime->eat_t = ft_atoi(arg[3]);
	atime->sleep_t = ft_atoi(arg[4]);
	if (arg[5])
		atime->neat_t = ft_atoi(arg[5]);
	else
		atime->neat_t = 0;
}

void *print_hello(void *arg)
{	
	t_philo *philo = (t_philo *)arg;
	time_t time_eat;
	time_t time;
	int i;
	
	i = 0;
	atime_init(&philo->time, philo->arg);
	time = get_time_in_ms();
	time_eat = get_time_in_ms();
	while (*philo->alive && (philo->time.neat_t > i || philo->time.neat_t == 0))
	{
		action(philo, time, THINK, 0, time_eat);
		time_eat = get_time_in_ms();
		action(philo, time, EAT, philo->time.eat_t, time_eat);
		i++;
		pthread_mutex_unlock(&philo->fork_left->fork);
		philo->fork_left->in_use = 0;
		pthread_mutex_unlock(&philo->fork_right->fork);
		philo->fork_right->in_use = 0;
		action(philo, time, SLEEP, philo->time.sleep_t, time_eat);
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
		if (pthread_create(&data->philos_thread[i], NULL, print_hello, &data->philos[i]))
			return (printf("Error\n"));
		i++;
	}
	i = 0;
	while (i < data->count)
	{
		if (pthread_join(data->philos_thread[i], NULL))
			return (printf("Error\n"));
		i++;
	}
	return (0);
}