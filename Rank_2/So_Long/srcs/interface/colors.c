/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:12:35 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/06 16:16:55 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Since each byte contains 2^8 = 256 values (1 byte = 8 bits),
and RGB values range from 0 to 255, we can perfectly fit a integer
(as an int is 4 bytes). In order to set the values programatically
we use bitshifting. Let’s create a function which does precisely
that for us, shall we?
*/

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
Because ints are stored from right to left,
we need to bitshift each value the according
amount of bits backwards. We can also do the
exact opposite and retrieve integer values
from a encoded TRGB integer.
*/

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

/*t_data	color_win(t_data img, t_win *win, int x, int y)
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
}*/
