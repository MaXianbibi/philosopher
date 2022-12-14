/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:01:27 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/19 09:19:11 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	action_routine(t_philo *philo, time_t time, int state)
{
	if (philo->fork_right->in_use == 0 && state)
	{
		pthread_mutex_lock(&philo->fork_right->fork);
		philo->fork_right->in_use = 1;
		if (philo->fork_left->in_use == 0)
		{
			pthread_mutex_lock(&philo->fork_left->fork);
			philo->fork_left->in_use = 1;
			action(philo, time, FORK, 0);
			action(philo, time, FORK, 0);
			return (1);
		}
		else
		{
			philo->fork_right->in_use = 0;
			pthread_mutex_unlock(&philo->fork_right->fork);
		}
	}
	return (0);
}

void	think_action(t_philo *philo, time_t time_eat, time_t time)
{
	time_t	i;
	int		state;

	(void)time_eat;
	if (get_time_in_ms() == time)
		state = 1;
	else
		state = 0;
	i = get_time_in_ms();
	while (philo->alive)
	{
		if (action_routine(philo, time, state))
			break ;
		if (get_time_in_ms() - i >= ((philo->time.die_t
					- (philo->time.eat_t + philo->time.sleep_t)) / 2))
			state++;
	}
}

void	action(t_philo *philo, time_t time, int digit,
	time_t action_time)
{
	static char	color[][5][20]
		= {
	{HBLU, "is sleeping 💤"},
	{HRED, "is eating 🍝"},
	{HYEL, "is thinking 🤔"},
	{HGRN, "has take a fork 🍴"},
	{HWHT, "died 💀"}
	};

	if (*philo->alive)
	{	
		pthread_mutex_lock(philo->superviseur);
		if (*philo->alive)
			printf("%s[%ld] %d %s\n", color[digit][0],
				(get_time_in_ms() - time), philo->digit + 1, color[digit][1]);
		pthread_mutex_unlock(philo->superviseur);
		if (action_time > 0)
			philo_action_time(philo, action_time, philo->last_meal, time);
		if (digit == THINK)
			think_action(philo, philo->last_meal, time);
	}
}
