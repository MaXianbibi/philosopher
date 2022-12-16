/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:12:20 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/12 18:35:56 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print_error(char *str)
{
	printf("Error\n");
	printf("%s", str);
	return (0);
}

static int check_nb_philo(char **argv, t_global *data)
{
	if (ft_atoi(argv[1]) == 1)
	{
		printf("[%d] 1 died 💀\n", ft_atoi(argv[2]));
		return (0);
	}
	if (ft_atoi(argv[1]) == 0)
	{
		printf("Error : Il faut au moins 1 philosophe.\n");
		return (0);
	}
	if (ft_atoi(argv[1]) > 200)
	{
		printf("Error : Le nombre de philosophes doit être entre 1 et 200.\n");
		return (0);
	}
	if (ft_atoi(argv[1]) == 2)
		data->time_delay = 1;
	else 
		data->time_delay = 0;
	return (1);
}

int main(int argc, char **argv)
{
	t_global data;
	
	if (argc != 5 && argc != 6)
		return(print_error("Il faut exactement 4 ou 5 arguments\n"));
	if (!check_nb_philo(argv, &data))
		return (0);	
	data_init(&data, argv);
	if (thread_init(argv, &data))
		printf("Error\n");
	return (0);
}