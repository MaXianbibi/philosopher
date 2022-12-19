/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:12:20 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/19 12:18:06 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print_error(char *str)
{
	printf("Error\n");
	printf("%s", str);
	return (0);
}

static int	check_arg(char **argv)
{
	if (ft_atoi(argv[2]) < 60)
	{
		printf("Error : le time to die doit être supérieur ou égal a 60\n");
		return (0);
	}
	if (ft_atoi(argv[3]) < 60)
	{
		printf("Error : le time to eat doit être supérieur ou égal a 60\n");
		return (0);
	}
	if (ft_atoi(argv[4]) < 60)
	{
		printf("Error : le time to sleep doit être supérieur ou égal a 60\n");
		return (0);
	}
	if (argv[5] && ft_atoi(argv[5]) < 1)
	{
		printf("Error : le n-eat doit être supérieur ou égal a 1\n");
		return (0);
	}
	return (1);
}

static int	check_nb_philo(char **argv, t_global *data)
{
	if (ft_atoi(argv[1]) == 1)
	{
		usleep(ft_atoi(argv[2]) * 100);
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
		printf("Error : Le nombre de philosophes doit être inferieur a 200.\n");
		return (0);
	}
	data->time_delay = 0;
	if (ft_atoi(argv[1]) == 2)
		data->time_delay = 1;
	return (1);
}

static void	ft_free_ft(t_global *data)
{
	if (data->philos)
		free (data->philos);
	if (data->fork)
		free (data->fork);
	if (data->philos_thread)
		free (data->philos_thread);
}

int	main(int argc, char **argv)
{
	t_global	data;

	if (argc != 5 && argc != 6)
		return (print_error("Il faut exactement 4 ou 5 arguments\n"));
	if (!check_nb_philo(argv, &data))
		return (0);
	if (!check_arg(argv))
		return (0);
	data_init(&data, argv);
	if (thread_init(argv, &data))
		printf("Error\n");
	ft_free_ft(&data);
	return (0);
}
