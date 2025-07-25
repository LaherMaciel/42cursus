/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:46:47 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/07/23 13:28:29 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_allinfo(t_philo *philo)
{
	printf("Number of philosophers: %d\n", philo->table->num_of_philos);
	printf("Philosopher ID: %d\n", philo->id);
	printf("Left fork: %d\n", philo->left_fork);
	printf("Right fork: %d\n", philo->right_fork);
	printf("Time to die: %d ms\n", philo->table->time_to_die);
	printf("Time to eat: %d ms\n", philo->table->time_to_eat);
	printf("Time to sleep: %d ms\n", philo->table->time_to_sleep);
	if (philo->is_dead == 0)
		printf("Is dead: yes is dead\n");
	else
		printf("Is dead: is alive\n");
	if (philo->table->num_of_times_to_eat > 0)
		printf("Number of times each philosopher must eat: %d\n",
			philo->table->num_of_times_to_eat);
	printf("Number of times eaten: %d\n", philo->num_of_times_eaten);
	printf("Current time: %ld\n", philo->current_time);
	printf("Start time: %ld\n", philo->start_time);
	printf("\n");
}

void	print_philoinfo(t_philo *philo)
{
	printf("Number of philosophers: %d\n", philo->table->num_of_philos);
	printf("Philosopher ID: %d\n", philo->id);
	printf("Left fork: %d\n", philo->left_fork);
	printf("Right fork: %d\n", philo->right_fork);
	printf("Time to die: %d ms\n", philo->table->time_to_die);
	printf("Time to eat: %d ms\n", philo->table->time_to_eat);
	printf("Time to sleep: %d ms\n", philo->table->time_to_sleep);
	if (philo->is_dead == 0)
		printf("Is dead: yes is dead\n");
	else
		printf("Is dead: is alive\n");
	if (philo->table->num_of_times_to_eat > 0)
		printf("Number of times each philosopher must eat: %d\n",
			philo->table->num_of_times_to_eat);
	printf("Number of times eaten: %d\n", philo->num_of_times_eaten);
	printf("Current time: %ld\n", philo->current_time);
	printf("Start time: %ld\n", philo->start_time);
	printf("\n");
}

void	print_tableinfo(t_table *table)
{
	printf("Number of philosophers: %d\n", table->num_of_philos);
	printf("Time to die: %d ms\n", table->time_to_die);
	printf("Time to eat: %d ms\n", table->time_to_eat);
	printf("Time to sleep: %d ms\n", table->time_to_sleep);
	if (table->num_of_times_to_eat > 0)
		printf("Number of times each philosopher must eat: %d\n",
			table->num_of_times_to_eat);
	printf("\n");
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(s))
		write(fd, &s[i], 1);
}

t_philo	*printphilosactions(t_philo *philo, int flag)
{
	(void)flag;
	return (philo);
}
