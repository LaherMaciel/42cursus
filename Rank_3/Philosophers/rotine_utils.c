/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:33:27 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/07/23 16:32:22 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_death_message(long now, t_table *table, int i)
{
	pthread_mutex_lock(&table->print_mutex);
	printf("%ld %d died\n",
		now - table->philos[i]->start_time, table->philos[i]->id);
	pthread_mutex_unlock(&table->print_mutex);
}

int	check_philo_death(t_table *table, int i)
{
	long	now;
	long	last_eaten;

	pthread_mutex_lock(&table->death);
	now = time_in_ms();
	pthread_mutex_lock(&table->philos[i]->time_mutex);
	last_eaten = table->philos[i]->time_that_eaten;
	pthread_mutex_unlock(&table->philos[i]->time_mutex);
	if (now - last_eaten > table->time_to_die)
	{
		print_death_message(now, table, i);
		table->is_dead = 1;
		pthread_mutex_unlock(&table->death);
		return (1);
	}
	pthread_mutex_unlock(&table->death);
	return (0);
}
