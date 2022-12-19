/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:18:30 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/19 09:37:36 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	checkifdead(t_philo *philo, time_t eat_time, time_t time)
{
	if (eat_time + philo->time.die_t <= get_time_in_ms())
	{
		action(philo, time - 1, DIE, 0);
		*philo->alive = 0;
		return (1);
	}
	return (0);
}

int	checkifneat(t_philo *philo)
{
	if (philo->time.neat_t <= 0)
		return (1);
	return (0);
}

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	philo_action_time(t_philo *philo, time_t action_time,
	time_t eat_time, time_t time)
{
	time_t	wake_up;
	time_t	before_die;

	(void)time;
	wake_up = get_time_in_ms() + action_time;
	before_die = get_time_in_ms() + philo->time.die_t - eat_time;
	while (get_time_in_ms() < wake_up)
	{
		if (philo->alive == 0)
			break ;
		usleep(100);
	}
}
