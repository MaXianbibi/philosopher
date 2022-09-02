/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:16:18 by jmorneau          #+#    #+#             */
/*   Updated: 2022/09/02 17:28:17 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


void *print_hello(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	
	(void)philo;
	// printf("im the philosopher #%d\n", philo->digit);
	return (NULL);

}

int thread_init(char **argv, t_global *data)
{
	int i;

	i = 0;
	(void)argv;
		// printf("%d\n", data->philos[0].digit);
	while (i < data->nphilo)
	{
		if (pthread_create(&data->nb_philos[i], NULL, print_hello, &data->philos[i]) == -1)
			return -1;
		i++;
	}
	
	i = 0;
	while (i < data->nphilo)
	{
		pthread_join(data->nb_philos[i], NULL);
		i++;
	}
	
	
	return (0);
}