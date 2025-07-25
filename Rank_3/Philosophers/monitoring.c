/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:24:33 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/07/24 16:24:52 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		if (check_all_philos_death(table))
			return (NULL);
		if (all_philos_ate_enough(table))
		{
			pthread_mutex_lock(&table->death);
			table->is_dead = 1;
			pthread_mutex_unlock(&table->death);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
