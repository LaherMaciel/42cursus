/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:24:33 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/07/27 14:04:56 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;
	long	current_time;
	long	last_eaten;

	table = (t_table *)arg;
	while (1)
	{
		i = 0;
		while (i < table->num_of_philos)
		{
			current_time = time_in_ms();
			pthread_mutex_lock(&table->philos[i]->eat_mutex);
			last_eaten = table->philos[i]->time_that_eaten;
			pthread_mutex_unlock(&table->philos[i]->eat_mutex);
			
			if (last_eaten != 0 && (current_time - last_eaten) >= table->time_to_die)
			{
				pthread_mutex_lock(&table->death);
				if (!table->is_dead)
				{
					printf("%li %d died\n", current_time - table->philos[i]->start_time, table->philos[i]->id);
					table->is_dead = 1;
				}
				pthread_mutex_unlock(&table->death);
				return (NULL);
			}
			i++;
		}
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
