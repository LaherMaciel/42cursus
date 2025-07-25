/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:00:00 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/07/23 16:36:17 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	get_eaten_count(t_table *table, int i)
{
	int		eaten;

	pthread_mutex_lock(&table->philos[i]->eat_mutex);
	eaten = table->philos[i]->num_of_times_eaten;
	pthread_mutex_unlock(&table->philos[i]->eat_mutex);
	return (eaten);
}

int	all_philos_ate_enough(t_table *table)
{
	int		i;
	int		eaten;

	if (table->num_of_times_to_eat <= 0)
		return (0);
	i = 0;
	while (i < table->num_of_philos)
	{
		eaten = get_eaten_count(table, i);
		if (eaten < table->num_of_times_to_eat)
			return (0);
		i++;
	}
	return (1);
}

int	check_all_philos_death(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->num_of_philos)
	{
		if (is_death(table->philos[i]))
			return (1);
		i++;
	}
	return (0);
}

void	create_philo_threads(
	t_philo **philos,
	t_table *table,
	int numb_of_philos
)
{
	int		i;

	i = -1;
	while (++i < numb_of_philos)
	{
		philos[i] = init_philo_values(i, table);
		pthread_create(&table->philosopher[i], NULL,
			start_routine, (void *)philos[i]);
	}
}

void	join_philos_threads(t_table *table, int numb_of_philos)
{
	int		i;

	i = -1;
	while (++i < numb_of_philos)
		pthread_join(table->philosopher[i], NULL);
}
