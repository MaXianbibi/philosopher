/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:12:20 by jmorneau          #+#    #+#             */
/*   Updated: 2022/09/02 17:13:32 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_global data;
	
	if (argc < 2)
		return (0);
	data_init(&data, argv);
	if (thread_init(argv, &data) == -1)
		printf("Error\n");
	return (0);
}