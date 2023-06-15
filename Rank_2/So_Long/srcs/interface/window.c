/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:46:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/15 01:20:30 by lwencesl         ###   ########.fr       */
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

/**
 * @brief Put a value that represent a color on the pointer located on the {x,y}
 * of the image.
 * 
 * @param data win
 * @param x final_image x
 * @param y final_image y
 * @param color the color I want to put.
 */
void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/**
 * @brief Find the pointer on the {x,y} of the current_image and return the
 * value that that pointer is storing (the color).
 
 * 
 * @param data aux
 * @param x aux_image x
 * @param y aux_image y
 * @return unsigned int 
 */
unsigned int	get_pixel(t_aux_vales *aux, int x, int y)
{
	char	*dst;

	dst = aux->current_image + (y * aux->aux_line_length + x * (aux->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

/*
unsigned int	get_pixel(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
*/

int	window_destroy(t_win *win)
{
	int	i;

	i = -1;
	mlx_destroy_window(win->mlx, win->mlx_win);
	mlx_destroy_display(win->mlx);
	while (win->mapa[++i])
		free(win->mapa[i]);
	free(win->mapa);
	free(win->mlx);
	exit(0);
}
