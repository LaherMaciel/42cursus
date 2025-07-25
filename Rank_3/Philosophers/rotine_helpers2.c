/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine_helpers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:15:00 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/07/23 16:17:53 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	clean_up(t_philo *philo, int unlock_left, int unlock_right)
{
	if (unlock_left)
		pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
	if (unlock_right)
		pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
}

int	should_exit(t_philo *philo)
{
	return (philo->table->is_dead);
}
