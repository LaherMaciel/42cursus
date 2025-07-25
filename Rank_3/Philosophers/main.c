/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:30:27 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/07/24 16:25:02 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_table	*main_init_table(int argc, char **argv)
{
	t_table	*table;

	table = init_table(argc, argv);
	if (!table)
	{
		ft_putstr_fd("Error: Invalid table initialization.\n", 2);
		return (NULL);
	}
	return (table);
}

static t_philo	**main_init_philos(int argc, char **argv, t_table *table)
{
	t_philo	**philos;

	philos = init_philo(argc, argv);
	if (!philos)
	{
		ft_putstr_fd("Error: Invalid philosopher initialization.\n", 2);
		free_table(table);
		return (NULL);
	}
	return (philos);
}

int	main(int argc, char **argv)
{
	t_philo	**philos;
	t_table	*table;

	philos = NULL;
	table = NULL;
	table = main_init_table(argc, argv);
	if (!table)
		return (1);
	if (table->num_of_philos == 1)
	{
		handle_one_philo(table);
		free_table(table);
		return (0);
	}
	philos = main_init_philos(argc, argv, table);
	if (!philos)
		return (1);
	threads_handler(philos, table, table->num_of_philos);
	return (0);
}
