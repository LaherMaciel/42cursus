/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:36:13 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/07 22:54:10 by lwencesl         ###   ########.fr       */
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

t_win	window_init(t_win win)
{
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx,
			win.length_size, win.heigth_size, "Hello world");
	ft_printf("WINDOOW CREATED\n");
	return (win);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_data	color_win(t_data img, t_win *win, int x, int y)
{
	if (win->mapa[win->i][win->j] == '1')
		mlx_put_image_to_window(win->mlx, win->mlx_win, img.img_wall, x, y);
	else if (win->mapa[win->i][win->j] == '0')
		mlx_put_image_to_window(win->mlx, win->mlx_win, img.img_floor, x, y);
	else if (win->mapa[win->i][win->j] == 'p')
		mlx_put_image_to_window(win->mlx, win->mlx_win, img.img_player, x, y);
	else if (win->mapa[win->i][win->j] == 'c')
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			img.img_collectibles, x, y);
	else if (win->mapa[win->i][win->j] == 'e')
		mlx_put_image_to_window(win->mlx, win->mlx_win, img.img_exit, x, y);
	win->j++;
	return (img);
}

t_data	images_on_window(t_win *win, t_data img)
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
				color_win(img, win, x, y);
		}
		if (!win->mapa[win->i][win->j])
				win->i++;
	}
	return (img);
}

t_data	create_image(t_win win, void *img_player)
{
	t_data	img;

	img.img_wall = wall_image(&win);
	img.img_player = img_player;
	img.img_floor = floor_image(&win);
	img.img_collectibles = collectibles_image(&win);
	img.img_exit = exit_image(&win);
	img = images_on_window(&win, img);
	win.mapa_length = ft_strlen(win.mapa[0]);
	//win.mapa_heigth = 0;
	//while (win.mapa[0][win.mapa_heigth])
	//	win.mapa_heigth++;
	ft_printf("IMAGE CREATED\n");
	return (img);
}
