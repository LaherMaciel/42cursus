/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_animations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:30:39 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/17 07:08:14 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*collectibles_image_animation(t_win *win)
{
	void	*img_collectibles;

	if (win->collect == 0)
		img_collectibles = mlx_xpm_file_to_image(win->mlx,
				"../../images/utils/Collectibles/soul_flame/tile000.xpm", &win->image_length, &win->image_heigth);
	if (win->collect == 1)
		img_collectibles = mlx_xpm_file_to_image(win->mlx,
				"../../images/utils/Collectibles/soul_flame/tile001.xpm", &win->image_length, &win->image_heigth);
	if (win->collect == 2)
		img_collectibles = mlx_xpm_file_to_image(win->mlx,
				"../../images/utils/Collectibles/soul_flame/tile002.xpm", &win->image_length, &win->image_heigth);
	if (win->collect == 3 || win->collect == 4)
		img_collectibles = mlx_xpm_file_to_image(win->mlx,
				"../../images/utils/Collectibles/soul_flame/tile003.xpm", &win->image_length, &win->image_heigth);
	win->collect++;
	if (win->collect == 5)
		win->collect = 0;
	return (img_collectibles);
}

t_data	upgrade_collectibles(t_main_struct *boss)
{
	int	i;
	int	j;

	i = 0;
	while (boss->win.mapa[i])
	{
		j = 0;
		while (boss->win.mapa[i][j])
		{
			if (boss->win.mapa[i][j++] == 'c')
			{
				boss->aux.current_image = collectibles_image(&boss->win);
				boss->img = upgrade_main_image(boss, (i +  1), j, 1);
				mlx_put_image_to_window(boss->win.mlx, boss->win.mlx_win, boss->img.main_image, 0, 0);
			}
		}
		i++;
	}
	return (boss->img);
}
