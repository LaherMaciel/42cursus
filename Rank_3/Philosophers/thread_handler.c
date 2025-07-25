/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:24:05 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/07/24 16:24:25 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	threads_handler(t_philo **philos, t_table *table,
	int numb_of_philos)
{
	pthread_t	monitor;

	table->philos = philos;
	create_philo_threads(philos, table, numb_of_philos);
	pthread_create(&monitor, NULL, monitor_routine, (void *)table);
	pthread_join(monitor, NULL);
	usleep(10000);
	join_philos_threads(table, numb_of_philos);
	free_all(philos, table);
}
