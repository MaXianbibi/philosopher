/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:25:17 by jmorneau          #+#    #+#             */
/*   Updated: 2022/09/02 17:44:55 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// static void fork_init(t_global *data, int i)
// {
// 	if (data->philos[i].digit == 0)
// 		data->philos[i].fork_left = data->fork[data->nphilo - 1];
// 	else
// 		data->philos[i].fork_left = data->fork[i - 1];
// 	data->philos[i].fork_right = data->fork[i];
// }

int data_init(t_global *data, char **argv)
{
	int i;

	i = 0;
	data->nphilo = ft_atoi(argv[1]);
	data->nb_philos = malloc(sizeof(data->nb_philos) * data->nphilo);
	data->fork = malloc(sizeof(data->fork) * data->nphilo);
	data->philos = malloc(sizeof(data->philos) * data->nphilo);
	while (i < data->nphilo)
	{
		data->philos[i].digit = i;
		printf("%d\n", data->philos[0].digit);
		pthread_mutex_init(&data->fork[i], NULL);
		// fork_init(data, i);
		i++;
	}
	return (0);
}
