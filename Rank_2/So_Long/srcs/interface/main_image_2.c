/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_image_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:30:45 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/25 18:23:43 by lwencesl         ###   ########.fr       */
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
		return ((64 - (boss->win.image_heigth)) * (-1));
	}
	return (0);
}

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
