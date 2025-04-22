/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_rotine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:43:50 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/04/22 15:34:15 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*to_sleep(t_philo *philo)
{
	philo = printphilosactions(philo, 1);
	philo->time_that_eaten = time_in_ms();
	usleep(philo->table->time_to_sleep * philo->time_multiplier);
	return (philo);
}

/**
 * !MONITORING/TESTING PRINTS
 * 
	printf(RED"%li Philosopher %d locked the forks %d and"
		" %d%s\n",
		philo->current_time.tv_sec - philo->start_time.tv_sec, philo->id,
		philo->left_fork + 1, philo->right_fork + 1, DEFAULT_COLOR);
 * 
	printf(GREEN"%li Philosopher %d unlocked the forks %d and"
		" %d%s\n",
		philo->current_time.tv_sec - philo->start_time.tv_sec, philo->id,
		philo->left_fork + 1, philo->right_fork + 1, DEFAULT_COLOR);

	pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->table->forks[philo->right_fork]);

	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
	}
 */
static t_philo	*eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
	}
	philo->current_time = time_in_ms();
	printf(RED"%li Philosopher %d locked the forks %d and"
		" %d%s\n",
		philo->current_time - philo->start_time, philo->id,
		philo->left_fork + 1, philo->right_fork + 1, DEFAULT_COLOR);
	printphilosactions(philo, 2);
	if (is_death(philo))
	{
		printf(GREEN"%li Philosopher %d unlocked the forks %d and"
			" %d%s\n",
			philo->current_time - philo->start_time, philo->id,
			philo->left_fork + 1, philo->right_fork + 1, DEFAULT_COLOR);
		pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
		return (philo);
	}
	usleep(philo->table->time_to_eat * philo->time_multiplier);
	printf(GREEN"%li Philosopher %d unlocked the forks %d and"
		" %d%s\n",
		philo->current_time - philo->start_time, philo->id,
		philo->left_fork + 1, philo->right_fork + 1, DEFAULT_COLOR);
	philo->time_that_eaten = time_in_ms();
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
	philo->num_of_times_eaten++;
	return (philo);
}

static t_philo	*think(t_philo *philo)
{
	philo->time_that_eaten = time_in_ms();
	return (printphilosactions(philo, 3));
}

/* 
static t_philo	*lonely_thinker(t_philo *philo)
{
	
	return (philo);
}
 */
void	*start_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *) args;
	while (1)
	{
		if (philo->num_of_times_eaten
			== philo->table->num_of_times_to_eat)
			break ;
		philo = monitoring(philo);
		if (is_death(philo))
			return (NULL);
		philo = eat(philo);
		if (is_death(philo))
			return (NULL);
		philo = to_sleep(philo);
		if (is_death(philo))
			return (NULL);
		philo = think(philo);
		if (is_death(philo))
			return (NULL);
	}
	return (NULL);
}
