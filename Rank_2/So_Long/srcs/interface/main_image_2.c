/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_image_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:30:45 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/17 23:43:43 by lwencesl         ###   ########.fr       */
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
	if (boss->win.image_heigth < 64)
	{
		if (i == 0)
			return ((64 - (boss->win.image_heigth)));
		return ((64 - (boss->win.image_heigth)) * (-1));
	}
	return (0);
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
	if (boss->win.image_length < 64)
	{
		if (i == 0)
			return ((64 - (boss->win.image_length)));
		return ((64 - (boss->win.image_length)) * (-1));
	}
	return (0);
}

int	include_x(t_main_struct *boss, int i)
{
	if (boss->win.image_length > 64)
	{
		if (i == 0)
			return (64 - (boss->win.image_length));
		return ((64 - (boss->win.image_length)) * (-1));
	}
	return (0);
}

int	include_y(t_main_struct *boss, int i)
{
	if (boss->win.image_heigth > 64)
	{
		if (i == 0)
			return (64 - (boss->win.image_heigth));
		return ((64 - (boss->win.image_heigth)) * (- 1));
	}
	return (0);
}
