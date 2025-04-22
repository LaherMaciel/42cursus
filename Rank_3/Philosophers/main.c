/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:30:27 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/04/22 14:53:08 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_all(t_philo **philos, t_table *table)
{
	int	number_of_philos;

	number_of_philos = table->num_of_philos;
	free_table(table);
	free_philos(philos, number_of_philos);
}

static void	threads_handler(t_philo **philos, t_table *table,
	int numb_of_philos)
{
	int	i;

	i = -1;
	while (++i < numb_of_philos)
	{
		philos[i] = init_philo_values(i, table);
		pthread_create(&table->philosopher[i], NULL,
			start_routine, (void *) philos[i]);
	}
	i = -1;
	while (++i < numb_of_philos)
		pthread_join(table->philosopher[i], NULL);
	free_all(philos, table);
}

int	main(int argc, char **argv)
{
	t_philo	**philos;
	t_table	*table;

	table = init_table(argc, argv);
	if (!table)
	{
		free_all(NULL, table);
		return (ft_putstr_fd("Error: Invalid table initialization.\n", 2), 1);
	}
	philos = init_philo(argc, argv);
	if (!philos)
	{
		ft_putstr_fd("Error: Invalid philosopher"
			" initialization.\n", 2);
		return (1);
	}
	threads_handler(philos, table, table->num_of_philos);
	return (0);
}
