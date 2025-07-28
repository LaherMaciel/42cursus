/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_rotine_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:30:00 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/07/27 15:08:53 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

t_philo	*think(t_philo *philo)
{
	if (is_death(philo))
		return (philo);
	pthread_mutex_lock(&philo->table->print_mutex);
	if (is_death(philo))
	{
		pthread_mutex_unlock(&philo->table->print_mutex);
		return (philo);
	}
	printf("%li %d is thinking\n",
		philo->current_time - philo->start_time, philo->id);
	pthread_mutex_unlock(&philo->table->print_mutex);
	usleep(2000);
	return (philo);
}

static int lock_forks(t_philo *philo)
{
	// Use different fork locking order for even/odd philosophers to prevent deadlock
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
		if (is_death(philo))
		{
			pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
			return (1);
		}
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
		if (is_death(philo))
		{
			pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
			pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
			return (1);
		}
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
		if (is_death(philo))
		{
			pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
			return (1);
		}
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
		if (is_death(philo))
		{
			pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
			pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
			return (1);
		}
	}
	return (0);
}

int	should_break(t_philo *philo, int eaten)
{
	if (philo->table->num_of_times_to_eat > 0 && eaten >= philo->table->num_of_times_to_eat)
		return (1);
	if (is_death(philo))
		return (1);
	return (0);
}

static t_philo *eat(t_philo *philo)
{
	if (is_death(philo))
		return (philo);

	if (lock_forks(philo))
		return (philo);

	pthread_mutex_lock(&philo->table->print_mutex);
	if (!is_death(philo))
		printf("%li %d is eating\n", philo->current_time - philo->start_time, philo->id);
	pthread_mutex_unlock(&philo->table->print_mutex);

	pthread_mutex_lock(&philo->eat_mutex);
	philo->num_of_times_eaten++;
	pthread_mutex_unlock(&philo->eat_mutex);

	usleep(philo->table->time_to_eat * 1000);

	pthread_mutex_lock(&philo->eat_mutex);
	philo->time_that_eaten = time_in_ms();
	pthread_mutex_unlock(&philo->eat_mutex);

	clean_up(philo, 1, 1);
	return (philo);
}

static t_philo *to_sleep(t_philo *philo)
{
	if (is_death(philo))
		return (philo);

	pthread_mutex_lock(&philo->table->print_mutex);
	if (!is_death(philo))
		printf("%li %d is sleeping\n", philo->current_time - philo->start_time, philo->id);
	pthread_mutex_unlock(&philo->table->print_mutex);

	usleep(philo->table->time_to_sleep * 1000);
	usleep(500);
	return (philo);
}

void	routine_loop(t_philo *philo)
{
	int		eaten;

	while (1)
	{
		pthread_mutex_lock(&philo->eat_mutex);
		eaten = philo->num_of_times_eaten;
		pthread_mutex_unlock(&philo->eat_mutex);
		if (should_break(philo, eaten))
			break ;
		philo = monitoring(philo);
		if (is_death(philo))
			break ;
		philo = eat(philo);
		if (is_death(philo))
			break ;
		philo = to_sleep(philo);
		if (is_death(philo))
			break ;
		philo = think(philo);
		if (is_death(philo))
			break ;
	}
}
