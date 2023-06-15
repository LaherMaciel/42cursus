/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixeis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:55:44 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/15 19:57:05 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*==============================================================\
|	  HERE WILL DEAL WITH THE FUNCTIONS THAT FOCES IN PIXEIS	|
\==============================================================*/

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
int	get_pixel(t_aux_vales *aux, int x, int y)
{
	char	*dst;

	dst = aux->current_image + (y * aux->line_length + x * (aux->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
