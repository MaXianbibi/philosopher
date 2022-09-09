/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:18:30 by jmorneau          #+#    #+#             */
/*   Updated: 2022/09/09 19:23:55 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void philo_action(t_philo *philo)
{

	time_t wake_up;
	
	wake_up = get_time_in_ms + ft_atoi(philo->arg[4]);
	
	while (get_time_in_ms() < wake_up)
	{
		
		if (game->alive == 0)
			break;
			
	}
	

}