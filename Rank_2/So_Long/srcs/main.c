/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:19:10 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/17 19:22:42 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Entry point of the program.
 *
 * It initializes the game window and sets up event hooks for keyboard input and window close.
 * The main game loop is then started using `mlx_loop`, which continuously handles events
 * and updates the window display.
 *
 * @return int The exit status of the program.
 */
int	main(void)
{
	t_main_struct	boss;

	boss.win = creat_mapa(&boss);
	boss.aux = aux_imgs_init(boss.aux);
	boss.win = win_vals_init(boss.win);
	if (boss.win.mapa == NULL)
		window_destroy(&boss);
	boss.win = window_init(boss.win);
	boss.img = start_image(&boss);
	mlx_hook(boss.win.mlx_win, 2, 1L<<0, keycode_decisions, &boss);
	boss.img = upgrade_player(&boss, 0);
	mlx_hook(boss.win.mlx_win, 17, 1L, window_destroy, &boss);
	boss.img = upgrade_player(&boss, 0);
	mlx_loop(boss.win.mlx);
	window_destroy(&boss);
	return (0);
}
