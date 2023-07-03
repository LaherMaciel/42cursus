/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vals_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:15:06 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/03 18:42:32 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_map_names(char ***mapNames)
{
	*mapNames = (char **)malloc(10 * sizeof(char *));
	(*mapNames)[0] = strdup("Map 1");
	(*mapNames)[1] = strdup("Map 2");
	(*mapNames)[2] = strdup("Map 3");
	(*mapNames)[3] = strdup("Map 4");
	(*mapNames)[4] = strdup("Map 5");
	(*mapNames)[5] = strdup("Map 6");
	(*mapNames)[6] = strdup("Map 7");
	(*mapNames)[7] = strdup("Map 8");
	(*mapNames)[8] = strdup("Map 9");
	(*mapNames)[9] = NULL;
}

t_extras	extras_vals_init(t_extras extras)
{
	initialize_map_names(&extras.map_names);
	return (extras);
}

t_data	img_vals_init(t_data img)
{
	img.main_image = NULL;
	return (img);
}

t_win	win_vals_init(t_win win)
{
	win.collect = 0;
	win.collected = 0;
	win.collectibles = 0;
	win.player_walk = 0;
	win.image_heigth = 64;
	win.image_length = 64;
	win.mlx = NULL;
	win.mlx_win = NULL;
	return (win);
}
