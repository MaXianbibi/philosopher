/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:25:17 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/19 09:13:20 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	fork_init(t_global *data, int i)
{
	if (data->philos[i].digit == data->count - 1)
		data->philos[i].fork_right = &data->fork[0];
	else
		data->philos[i].fork_right = &data->fork[i + 1];
	data->philos[i].fork_left = &data->fork[i];
}

int	data_init(t_global *data, char **argv)
{
	int	i;

	i = 0;
	data->alive = 1;
	data->count = ft_atoi(argv[1]);
	data->philos_thread = malloc(sizeof(pthread_t) * data->count);
	data->fork = malloc(sizeof(t_fork) * data->count);
	data->philos = malloc(sizeof(t_philo) * data->count);
	pthread_mutex_init(&data->superviseur, NULL);
	while (i < data->count)
	{
		pthread_mutex_init(&data->fork[i].fork, NULL);
		data->fork->in_use = 0;
		i++;
	}
	i = 0;
	while (i < data->count)
	{
		data->philos[i].digit = i;
		fork_init(data, i);
		data->philos[i].arg = argv;
		data->philos[i].alive = &data->alive;
		data->philos[i++].superviseur = &data->superviseur;
	}
	return (0);
}
