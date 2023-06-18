/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:30:34 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/18 11:34:25 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	correct_x(t_main_struct *boss, int stop_x)
{
	boss->aux.x = boss->aux.x + ignore_x(boss, 0);
	boss->aux.x = boss->aux.x + (include_x(boss, 0) / 2);
	stop_x = stop_x + ignore_x(boss, 0);
	stop_x = stop_x - (include_x(boss, 0) / 2);
	if (boss->aux.x < -1)
	{
		boss->aux.current_image_x = boss->aux.current_image_x + (boss->aux.x * (-1));
		boss->aux.x = -1;
	}
	return (stop_x);
}

int	correct_y(t_main_struct *boss, int stop_y)
{
	boss->aux.y = boss->aux.y + ignore_y(boss, 0);
	boss->aux.y = boss->aux.y + (include_y(boss, 0) / 2);
	stop_y = stop_y + ignore_y(boss, 0);
	stop_y = stop_y - (include_y(boss, 0) / 2);
	if (boss->aux.y < -1)
	{
		boss->aux.current_image_y = boss->aux.current_image_y + (boss->aux.y * (-1));
		boss->aux.y = -1;
	}
	return (stop_y);
}

t_data	put_walls_aux(t_main_struct *boss, int i, int j)
{
	int	stop_x;
	int	stop_y;

	stop_y = i * 64;
	stop_x = j * 64;
	boss->aux.y = stop_y - (boss->win.image_heigth + 1);
	boss->aux.current_image_y = 0;
	stop_y = correct_y(boss, stop_y);
	while(++boss->aux.y <= stop_y && boss->aux.y <= boss->win.heigth_size)
	{
		boss->aux.current_image_x = 0;
		stop_x = j * boss->win.image_length;
		boss->aux.x = stop_x - (boss->win.image_length + 1);
		stop_x = correct_x(boss, stop_x);
		while (++boss->aux.x <= stop_x && boss->aux.x <= boss->win.length_size)
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

	int	ignx0;
	int	ignx1;
	int	igny0;
	int	igny1;

if ((boss->aux.x % boss->win.image_length == 0))
			{
				boss->aux.current_image = choose_aux_image(boss);
				boss->aux.current_image_x = 0;

				
				boss->aux.x = boss->aux.x + ignore_x(boss, 0);
				boss->aux.x = boss->aux.x + include_x(boss, 0);
				stop_x = stop_x - ignore_x(boss, 1);
				stop_x = stop_x + include_x(boss, 1);
				boss->aux.y = boss->aux.y + ignore_y(boss, 0);
				boss->aux.y = boss->aux.y + include_y(boss, 0);
				stop_y = stop_y - ignore_y(boss, 1);
				stop_y = stop_y + include_y(boss, 1);

				
				boss->win.j++;
			}
			if (((boss->aux.current_image_x >= ignx0 && boss->aux.current_image_x <= ignx1)
				|| (ignx0 == 32 && ignx1 == 32))
					&& ((boss->aux.current_image_y >= igny0 && boss->aux.current_image_y <= igny1)
						|| ((igny0 == 32 && igny1 == 32))))
			{
				get_color_of_aux_image(&boss->aux);
				if (boss->aux.color && boss->aux.color != 4278190080)
					my_mlx_pixel_put(&boss->img, boss->aux.x, boss->aux.y, boss->aux.color);
			}
*/
