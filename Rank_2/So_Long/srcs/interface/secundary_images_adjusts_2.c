/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_image_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:30:45 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 22:24:43 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief This function calculates the Y offset for image placement based on
 * the image height and a fixed value of 64. If the image height is less than
 * 64, it returns the difference between 64 and the image height. If the
 * image height is greater than or equal to 64, it returns 0.
 *
 * @param boss The main game structure.
 * @param i The iteration variable.
 * @return int The calculated Y offset.
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
 * @brief This function calculates the X offset for image placement based on
 * the image length and a fixed value of 64. If the image length is LESS THAN
 * 64, it returns the difference between 64 and the image length. If the image
 * length is greater than or equal to 64, it returns 0.
 *
 * @param boss The main game structure.
 * @param i The iteration variable.
 * @return int The calculated X offset.
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

/**
 * @brief This function calculates the X offset for image placement based on
 * the image length and a fixed value of 64. If the image length is GREATER
 * than 64, it returns the difference between 64 and the image length. If
 * the image length is less than or equal to 64, it returns 0.
 *
 * @param boss The main game structure.
 * @param i The iteration variable.
 * @return int The calculated X offset.
 */
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

/**
 * @brief This function calculates the Y offset for image placement based on
 * the image height and a fixed value of 64. If the image height is GREATER
 * than 64, it returns the difference between 64 and the image height. If
 * the image height is less than or equal to 64, it returns 0.
 *
 * @param boss The main game structure.
 * @param i The iteration variable.
 * @return int The calculated Y offset.
*/
int	include_y(t_main_struct *boss, int i)
{
	if (boss->win.image_heigth > 64)
	{
		if (i == 0)
			return (64 - (boss->win.image_heigth));
		return ((64 - (boss->win.image_heigth)) * (-1));
	}
	return (0);
}
