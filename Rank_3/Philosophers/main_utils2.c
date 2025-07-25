/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:10:00 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/07/23 16:11:34 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	free_all(t_philo **philos, t_table *table)
{
	int		number_of_philos;

	number_of_philos = table->num_of_philos;
	free_table(table);
	free_philos(philos, number_of_philos);
}

int	handle_one_philo(t_table *table)
{
	pthread_mutex_lock(&table->forks[0]);
	printf("0 1 has taken a fork\n");
	usleep(table->time_to_die * 1000);
	printf("%d 1 died\n", table->time_to_die);
	pthread_mutex_unlock(&table->forks[0]);
	return (0);
}
