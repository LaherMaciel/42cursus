/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vals_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:15:06 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/22 15:05:46 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void initializeMapNames(char ***mapNames)
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
	initializeMapNames(&extras.map_names);
	return (extras);
}

t_data	img_vals_init(t_data img)
{
	img.main_image = NULL;
	return (img);
}

t_aux_vales	aux_imgs_init(t_aux_vales aux)
{
	aux.img_wall = NULL;
	aux.img_player = NULL;
	aux.img_collectibles = NULL;
	aux.img_exit = NULL;
	aux.img_floor = NULL;
	aux.current_image = NULL;
	aux.address = NULL;
	return (aux);
}

t_win	win_vals_init(t_win win)
{
	win.player_look = 1;
	win.exit = 0;
	win.collect = 0;
	win.collected = 0;
	win.image_heigth = 64;
	win.image_length = 64;
	return (win);
}
