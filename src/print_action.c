/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:01:27 by jmorneau          #+#    #+#             */
/*   Updated: 2022/09/13 01:56:14 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void action(t_philo *philo, time_t time, int digit, time_t action_time, time_t time_eat)
{
	static char	color[][5][20] = 
	{
	{HBLU, "is sleeping 💤"},
	{HRED, "is eating 🍝"},
	{HYEL, "is thinking 🤔"},
	{HGRN, "has take a fork 🍴"},
	{HWHT, "died 💀"}
	};
	
	if (*philo->alive)				
	{
		printf("%s[%ld] %d %s\n", color[digit][0], (get_time_in_ms() - time), philo->digit + 1, color[digit][1]);
		if (action_time > 0)
			philo_action_time(philo, action_time, time_eat);
	}
}
