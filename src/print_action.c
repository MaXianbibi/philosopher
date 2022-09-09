/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:01:27 by jmorneau          #+#    #+#             */
/*   Updated: 2022/09/09 19:06:40 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void take_a_fork(t_philo *philo, struct timeval time)
{
	struct timeval live_time;
	
	gettimeofday(&live_time, NULL);
	printf("%s[%ld] %d has taken fork 🍴\n", HGRN,(live_time.tv_sec - time.tv_sec) * 100, philo->digit + 1);
}

void is_eating(t_philo *philo, struct timeval time)
{
	struct timeval live_time;
	long			time_2_action;
	
	time_2_action = ft_atoi(philo->arg[3]) * 1000;
	gettimeofday(&live_time, NULL);
	printf("%s[%ld] %d is eating 🍝\n", HRED,(live_time.tv_sec - time.tv_sec) * 100, philo->digit + 1);
	usleep(time_2_action);
}

void is_sleeping(t_philo *philo, struct timeval time)
{
	struct timeval live_time;
	long			time_2_action;
	
	time_2_action = ft_atoi(philo->arg[4]) * 1000;
	gettimeofday(&live_time, NULL);
	printf("%s[%ld] %d is sleeping 💤\n", HBLU, (live_time.tv_sec - time.tv_sec) * 100, philo->digit + 1);
	usleep(time_2_action);
}

void is_thinking(t_philo *philo, struct timeval time)
{
	struct timeval live_time;

	gettimeofday(&live_time, NULL);
	printf("%s[%ld] %d is thinking 🤔\n", HYEL,(live_time.tv_sec - time.tv_sec) * 100, philo->digit + 1);
}

int is_he_dead(t_philo *philo, struct timeval time_eat, struct timeval time)
{
	struct timeval live_time;
	float time_s;
	
	gettimeofday(&live_time, NULL);
	time_s = ((live_time.tv_sec - time_eat.tv_sec) + 1e-6*(live_time.tv_usec - time_eat.tv_usec)) * 1000;
	if ((int)time_s >= ft_atoi(philo->arg[2]))
	{
		*(philo->alive) = 0;
		return(printf("%s[%ld] %d is dead 💀\n", WHT, (live_time.tv_sec - time.tv_sec) * 100, philo->digit + 1));
	}
	return (0);
}
