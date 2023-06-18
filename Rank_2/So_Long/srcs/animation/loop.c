/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 04:26:17 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/17 21:39:50 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_data	upgrade_main_image(t_main_struct *boss, int i, int j)
{
	int	stop_x;
	int	stop_y;

	stop_y = i * boss->win.image_heigth;
	stop_x = j * boss->win.image_length;
	boss->aux.y = stop_y - (boss->win.image_heigth + 1);
	boss->aux.current_image_y = 0;
	while(++boss->aux.y <= stop_y)
	{
		boss->aux.current_image_x = 0;
		boss->aux.x = stop_x - (boss->win.image_length + 1);
		while (++boss->aux.x <= stop_x)
		{
			get_color_of_aux_image(&boss->aux);
			if (boss->aux.color && boss->aux.color != 4278190080)
				my_mlx_pixel_put(&boss->img, boss->aux.x, boss->aux.y, boss->aux.color);
			boss->aux.current_image_x++;
		}
		boss->aux.current_image_y++;
	}
	return (boss->img);
}

/*
void	main_loop(t_main_struct *boss)
{
	int	repeat;

	repeat = 0;
	while (repeat < 5)
	{
		if (repeat != 4)

		else
			repeat = 0;
		reapet++;
	}
}
*/
