/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:12:20 by jmorneau          #+#    #+#             */
/*   Updated: 2022/09/13 00:44:12 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print_error(char *str)
{
	printf("Error\n");
	printf("%s", str);
	return (0);
}

int main(int argc, char **argv)
{
	t_global data;
	
	if (argc != 5 && argc != 6)
		return(print_error("Il faut exactement 4 ou 5 arguments\n"));
	data_init(&data, argv);
	if (thread_init(argv, &data))
		printf("Error\n");
	return (0);
}