/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_image_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:30:45 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/16 22:00:12 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief retunr the number of pixeis on the x line that should be ignored
 *
 * @param boss
 * @param i
 * @return int
 */
int	ignore_y(t_main_struct *boss, int i)
{
	if (i == 0)
		return (32 - (32 - (boss->win.image_heigth / 2)));
	return (32 + (32 - (boss->win.image_heigth / 2)));
}

/**
 * @brief retunr the number of pixeis on the y line that should be ignored
 *
 * @param boss
 * @param i
 * @return int
 */
int	ignore_x(t_main_struct *boss, int i)
{
	if (i == 0)
		return (32 - (32 - (boss->win.image_length / 2)));
	return (32 + (32 - (boss->win.image_length / 2)));
}
