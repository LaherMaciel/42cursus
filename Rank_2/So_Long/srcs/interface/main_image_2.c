/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_image_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:30:45 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 19:05:56 by lwencesl         ###   ########.fr       */
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

/**
 * @brief This function upgrades the main image by iterating over the
 * specified region defined by the coordinates (i, j) and the image length
 * and height. It retrieves the color from the corresponding auxiliary image
 * using the get_color_of_aux_image() function and sets the color in the main
 * image using the my_mlx_pixel_put() function.
 * 
 * @param boss Pointer to the main game structure.
 * @param i The row index of the current position.
 * @param j The column index of the current position.
 * @return t_data (boss->img) The modified main image data structure.
*/
t_data	upgrade_main_image(t_main_struct *boss, int i, int j)
{
	int	stop_x;
	int	stop_y;

	stop_y = i * boss->win.image_heigth;
	stop_x = j * boss->win.image_length;
	boss->aux.y = stop_y - (boss->win.image_heigth + 1);
	boss->aux.current_image_y = 0;
	while (++boss->aux.y <= stop_y)
	{
		boss->aux.current_image_x = 0;
		boss->aux.x = stop_x - (boss->win.image_length + 1);
		while (++boss->aux.x <= stop_x)
		{
			get_color_of_aux_image(&boss->aux);
			if (boss->aux.color && boss->aux.color != 4278190080)
				my_mlx_pixel_put(&boss->img, boss->aux.x, boss->aux.y,
					boss->aux.color);
			boss->aux.current_image_x++;
		}
		boss->aux.current_image_y++;
	}
	return (boss->img);
}
