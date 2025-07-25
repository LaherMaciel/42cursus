/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_rotine_prints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:32:00 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/07/23 16:33:21 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	eat_print_fork(t_philo *philo)
{
	printf("%li %d has taken a fork\n",
		philo->current_time - philo->start_time, philo->id);
}

void	eat_print_died(t_philo *philo)
{
	printf("%li %d died\n",
		philo->current_time - philo->start_time, philo->id);
}

void	eat_print_eating(t_philo *philo)
{
	printf("%li %d is eating\n",
		philo->current_time - philo->start_time, philo->id);
}
