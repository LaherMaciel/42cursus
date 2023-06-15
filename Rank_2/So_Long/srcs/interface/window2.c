/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:36:13 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/15 01:11:19 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*=============================================
include the 'mlx.h' on your '.h' project file
mlx_init() -> used to inicialize the library. It returns a (void *)
mlx_new_window(pointer_returned_by_mlx_init(),
	width, heigth, "the_name_of_the_window") -> used to initialize a window.
	return the (void *) to the new window created.  
mlx_new_image() -> 
mlx_loop() -> initiate the window rendering.
==============================================*/

t_data	floor_on_window(t_win *win, t_data img)
{
	int	x;
	int	y;

	y = -1;
	win->i = 0;
	while (++y < win->heigth_size && win->mapa[win->i])
	{
		x = -1;
		win->j = 0;
		while (++x < win->length_size && win->mapa[win->i][win->j])
		{
			if ((x % win->image_length == 0 && y % win->image_heigth == 0))
			{
				mlx_put_image_to_window(win->mlx, win->mlx_win, img.img_floor, x, y);
				win->j++;
			}
		}
		if (!win->mapa[win->i][win->j])
				win->i++;
	}
	return (img);
}

void	*color_win(t_main_struct *boss, t_data *img)
{
	if (boss->win.mapa[boss->win.i][boss->win.j] == '1')
		return (img.img_wall);
	else if (boss->win.mapa[boss->win.i][boss->win.j] == 'p')
		return (img.img_player);
	else if (boss->win.mapa[boss->win.i][boss->win.j] == 'c')
		return (img.img_collectibles);
	else if (boss->win.mapa[boss->win.i][boss->win.j] == 'e')
		return (img.img_exit);
	return (img.img_floor);
}

t_data	images_on_window(t_main_struct *boss)
{
	boss->aux.y = -1;
	boss->win.i = 0;
	while (++boss->aux.y < boss->win.heigth_size && boss->win.mapa[boss->win.i])
	{
		boss->aux.x = -1;
		boss->win.j = 0;
		while (++boss->aux.x < boss->win.length_size && boss->win.mapa[boss->win.i][boss->win.j])
		{
			if ((boss->aux.x % boss->win.image_length == 0 && boss->aux.y % boss->win.image_heigth == 0))
			{
				boss->aux.current_image = color_win(boss, &boss->img);
				boss->win.j++;
			}
			boss->aux.color = get_pixel(boss->aux.current_image, boss->aux.current_image_x, boss->aux.current_image_y);
			if (boss->aux.color)
				my_mlx_pixel_put(&boss->img, boss->aux.x, boss->aux.y, boss->aux.color);
			boss->aux.current_image_x++;
			if (boss->aux.current_image_x % 64 == 0)
				boss->aux.current_image_x = 0;
		}
		if (!boss->win.mapa[boss->win.i][boss->win.j])
				boss->win.i++;
		boss->aux.current_image_y++;
		if (boss->aux.current_image_y % 64 == 0)
			boss->aux.current_image_y = 0;
	}
	return (boss->img);
}

void	create_image(t_main_struct *boss, void *img_player)
{
	boss->img.img_wall = wall_image(&boss->win);
	boss->img.img_player = img_player;
	boss->img.img_floor = floor_image(&boss->win);
	boss->img.img_collectibles = collectibles_image(&boss->win);
	boss->img.img_exit = exit_image(&boss->win);
	boss->img = floor_on_window(boss);
	boss->img = images_on_window(boss);
	boss->win.mapa_length = ft_strlen(boss->win.mapa[0]);
	//win->mapa_heigth = 0;
	//while (win->mapa[0][win->mapa_heigth])
	//	win->mapa_heigth++;
	ft_printf("IMAGE CREATED\n");
}
