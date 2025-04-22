/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printinfo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:46:47 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/04/22 15:22:53 by lahermaciel      ###   ########.fr       */
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

/**
 * @brief Writes a string to a file descriptor.
 *
 * This function writes the string 's' to the specified file descriptor 'fd'
 * using the `write` system call. It iterates through the characters in the
 * string and writes each character individually to the file descriptor.
 *
 * @param s The string to be written.
 * @param fd The file descriptor to which the string will be written.
 */
void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(s))
		write (fd, &s[i], 1);
}

t_philo	*printphilosactions(t_philo *philo, int flag)
{
	philo = monitoring(philo);
	if (is_death(philo))
		return (philo);
	pthread_mutex_lock(&philo->table->print_mutex);
	philo->current_time = time_in_ms();
	if (is_death(philo))
		return (philo);
	if (flag == 1)
	{
		printf("%li Philosopher %d"CYAN" is sleeping...\n"DEFAULT_COLOR,
			philo->current_time - philo->start_time, philo->id);
	}
	else if (flag == 2)
	{
		printf("%li Philosopher "MAGENTA"%d is eating...\n"DEFAULT_COLOR,
			philo->current_time - philo->start_time, philo->id);
	}
	else if (flag == 3)
	{
		printf("%li Philosopher %d"YELLOW" is thinking...\n"DEFAULT_COLOR,
			philo->current_time - philo->start_time, philo->id);
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
	return (philo);
}
