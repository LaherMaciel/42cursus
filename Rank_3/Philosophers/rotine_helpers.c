/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:22:50 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/07/23 16:16:27 by lahermaciel      ###   ########.fr       */
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
	if (!philo || !philo->table)
		return (-1);
	pthread_mutex_lock(&philo->table->death);
	if (philo->table->is_dead)
	{
		pthread_mutex_unlock(&philo->table->death);
		return (-1);
	}
	pthread_mutex_unlock(&philo->table->death);
	return (0);
}

t_philo	*monitoring(t_philo *philo)
{
	philo->current_time = time_in_ms();
	if (philo->time_that_eaten == 0)
		return (philo);
	if ((philo->current_time - philo->time_that_eaten)
		>= philo->table->time_to_die)
	{
		pthread_mutex_lock(&philo->table->death);
		if (!philo->table->is_dead)
		{
			printf("%li %d died\n",
				philo->current_time - philo->start_time, philo->id);
		}
		pthread_mutex_unlock(&philo->table->death);
		return (philo);
	}
	return (philo);
}

void	precise_sleep(long duration_ms, t_table *table)
{
	long	start;
	int		dead;

	start = time_in_ms();
	while (1)
	{
		pthread_mutex_lock(&table->death);
		dead = table->is_dead;
		pthread_mutex_unlock(&table->death);
		if (dead || (time_in_ms() - start >= duration_ms))
			break ;
		usleep(100);
	}
}
