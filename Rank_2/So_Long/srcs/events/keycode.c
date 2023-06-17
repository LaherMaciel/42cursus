/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:39:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/17 01:58:55 by lwencesl         ###   ########.fr       */
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
	while (boss->win.mapa[++i])
		ft_printf("%s\n", boss->win.mapa[i]);
	if (keycode == 100)
		mov_right(boss, &boss->win);
	if (keycode == 97)
		mov_left(boss, &boss->win);
	if (keycode == 119)
		mov_up(boss, &boss->win);
	if (keycode == 115)
		mov_down(boss, &boss->win);
	if (keycode == 65307)
		window_destroy(boss);
	ft_printf("keycode -> %i\n", keycode);
	mlx_loop(boss->win.mlx);
	return (0);
}
