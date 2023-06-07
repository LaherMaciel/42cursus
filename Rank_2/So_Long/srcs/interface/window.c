/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:46:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/06 20:56:04 by lwencesl         ###   ########.fr       */
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
	win.mlx_win = mlx_new_window(win.mlx, win.length_size, win.heigth_size, "Hello world");
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
	if (win->mapa[win->cont_heigth][win->cont_length] == '1')
		my_mlx_pixel_put(&img, x, y, 0x00005AFF);
	else if (win->mapa[win->cont_heigth][win->cont_length] == '0')
		my_mlx_pixel_put(&img, x, y, 0x00DDDDFF);
	else if (win->mapa[win->cont_heigth][win->cont_length] == 'p')
		my_mlx_pixel_put(&img, x, y, 0x0000FF00);
	else if (win->mapa[win->cont_heigth][win->cont_length] == 'c')
		my_mlx_pixel_put(&img, x, y, 0x00DDCC5F);
	else if (win->mapa[win->cont_heigth][win->cont_length] == 'e')
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	return (img);
}

t_data	pain_block(t_win *win, t_data img)
{
	int	x;
	int	y;
	int	lgen;
	int	hegn;

	lgen = win->block_length;
	hegn = win->block_heigth;
	ft_printf("block_length->%i\nblock_heigth->%i\n",
		win->block_length, win->block_heigth);
	y = -1;
	while (++y < win->heigth_size && win->cont_heigth < win->heigth)
	{
		x = -1;
		win->cont_length = 0;
		win->block_length = win->length_size / win->length;
		while (++x < win->length_size && win->cont_length < win->length)
		{
			color_win(img, win, x, y);
			if (x >= win->block_length)
			{
				win->block_length += lgen;
				win->cont_length++;
				//ft_printf("x = %i, y = %i\n", x, y);
			}
			if (y >= win->block_heigth)
			{
				win->block_heigth += hegn;
				win->cont_heigth++;
				//ft_printf("cont_length -> %i\ncont_heigth -> %i\n",
				//	win->cont_length, win->cont_heigth);
				//ft_printf("x = %i, y = %i\n", x, y);
			}
			if (win->cont_heigth >= win->heigth)
				break ;
		}
	}
	ft_printf("length->%i\nheigth->%i\n", win->length, win->heigth);
	ft_printf("block_length->%i\nblock_heigth->%i\n", lgen, hegn);
	ft_printf("x = %i, y = %i\n", x, y);
	return (img);
}

t_data	paint_wind(t_win *win, t_data img)
{
	win->length = ft_strlen(win->mapa[0]);
	win->heigth = 0;
	while (win->mapa[win->heigth])
		win->heigth++;
	win->block_length = win->length_size / win->length;
	win->block_heigth = win->heigth_size / win->heigth;
	win->cont_heigth = 0;
	img = pain_block(win, img);
	mlx_put_image_to_window(win->mlx, win->mlx_win, img.img, 0, 0);
	return (img);
}

t_data	create_image(t_win win)
{
	t_data	img;

	img.img = mlx_new_image(win.mlx, win.length_size, win.heigth_size);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	img = paint_wind(&win, img);
	ft_printf("IMAGE CREATED\n");
	return (img);
}

void	destroy_map(t_win *win)
{
	int	i;

	i = 0;
	while (win->mapa[i])
	{
		free(win->mapa[i]);
		i++;
	}
	free(win->mapa);
}

int	window_destroy(t_win *win)
{
	mlx_destroy_window(win->mlx, win->mlx_win);
	mlx_destroy_display(win->mlx);
	destroy_map(win);
	free(win->mlx);
	exit(0);
}
