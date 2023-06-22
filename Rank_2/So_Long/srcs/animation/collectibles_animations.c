/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_animations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:30:39 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/22 12:23:43 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*collectibles_image_animation(t_win *win)
{
	void	*img_collectibles;

	if (win->collect == 0)
		img_collectibles = mlx_xpm_file_to_image(win->mlx,
				"images/utils/Collectibles/soul_flame/tile000.xpm", &win->image_length, &win->image_heigth);
	if (win->collect == 1)
		img_collectibles = mlx_xpm_file_to_image(win->mlx,
				"images/utils/Collectibles/soul_flame/tile001.xpm", &win->image_length, &win->image_heigth);
	if (win->collect == 2)
		img_collectibles = mlx_xpm_file_to_image(win->mlx,
				"images/utils/Collectibles/soul_flame/tile002.xpm", &win->image_length, &win->image_heigth);
	if (win->collect == 3)
		img_collectibles = mlx_xpm_file_to_image(win->mlx,
				"images/utils/Collectibles/soul_flame/tile003.xpm", &win->image_length, &win->image_heigth);
	win->collect++;
	if (win->collect == 4)
		win->collect = 0;
	return (img_collectibles);
}

t_data	upgrade_collectibles(t_main_struct *boss)
{
	int	i;
	int	j;

	i = 0;
	if (boss->win.exit == 1)
		return (boss->img);
	boss->aux.current_image = collectibles_image(&boss->win);
	while (boss->win.mapa[i])
	{
		j = 0;
		while (boss->win.mapa[i][j])
			if (boss->win.mapa[i][j++] == 'c')
				boss->img = upgrade_main_image(boss, (i +  1), j);
		i++;
	}
	return (boss->img);
}

t_data	collect(t_main_struct *boss)
{
	boss->aux.current_image = floor_image(&boss->win);
	if (boss->win.player_look == 0)
		boss->img = upgrade_main_image(boss, (boss->win.player_y), (boss->win.player_x + 1));
	if (boss->win.player_look == 1)
		boss->img = upgrade_main_image(boss, (boss->win.player_y + 2), (boss->win.player_x + 1));
	if (boss->win.player_look == 2)
		boss->img = upgrade_main_image(boss, (boss->win.player_y + 1), (boss->win.player_x));
	if (boss->win.player_look == 3)
		boss->img = upgrade_main_image(boss, (boss->win.player_y + 1), (boss->win.player_x + 2));
	return (boss->img);
}
