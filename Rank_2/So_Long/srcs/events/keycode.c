/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:39:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 00:23:07 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Closes the window and terminates the program.
 *
 * @param win The window structure to be closed.
 * @return 0
 */

int	keycode_int(int keycode)
{
	return (keycode);
}

/**
 * @brief Handles the keypress events and performs corresponding actions.
 *
 * @param keycode The keycode of the pressed key.
 * @param win The window structure.
 * @return 0
 */
int	keycode_decisions(int keycode, t_main_struct *boss)
{
	int		i;

	i = -1;
	if (keycode == 100 || keycode == 65363)
		mov_right(boss, &boss->win);
	if (keycode == 97 || keycode ==  65361)
		mov_left(boss, &boss->win);
	if (keycode == 119 || keycode == 65362)
		mov_up(boss, &boss->win);
	if (keycode == 115 || keycode ==  65364)
		mov_down(boss, &boss->win);
	if (keycode == 65307)
		window_destroy(boss);
	while (boss->win.mapa[++i])
		ft_printf("%s\n", boss->win.mapa[i]);
	ft_printf("keycode -> %i\n", keycode);
	if (boss->win.collectibles == boss->win.collected)
		boss->win.exit = 1;
	boss->img = upgrade_collectibles(boss);
	mlx_put_image_to_window(boss->win.mlx, boss->win.mlx_win, boss->img.main_image, 0, 0);
	return (0);
}
