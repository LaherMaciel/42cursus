/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:22:50 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/04/22 15:27:03 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	time_in_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		ft_putstr_fd("Error getting time\n", 2);
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	is_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death);
	if (philo->table->is_dead)
	{
		pthread_mutex_unlock(&philo->table->death);
		return (-1);
	}
	pthread_mutex_unlock(&philo->table->death);
	return (0);
}

static void	autopsy(t_philo *philo)
{
	printf(BOLD_RED"AUTOPSY:\nCurrent time: %li\nLast time that eaten: "
		"%li\ntime without it: %li\ntime to die: %d\n"DEFAULT_COLOR,
		philo->current_time - philo->start_time,
		philo->time_that_eaten - philo->start_time,
		philo->current_time - philo->time_that_eaten,
		philo->table->time_to_die);
}

t_philo	*monitoring(t_philo *philo)
{
	philo->current_time = time_in_ms();
	if (philo->time_that_eaten == 0)
		return (philo);
	if (philo->current_time - philo->time_that_eaten
		>= philo->table->time_to_die)
	{
		pthread_mutex_lock(&philo->table->death);
		if (!philo->table->is_dead)
		{
			printf(RED"%li Philosopher %d died...\n"DEFAULT_COLOR,
				philo->current_time - philo->start_time, philo->id);
			autopsy(philo);
			philo->is_dead = 1;
			philo->table->is_dead = 1;
		}
		pthread_mutex_unlock(&philo->table->death);
		return (philo);
	}
	return (philo);
}
