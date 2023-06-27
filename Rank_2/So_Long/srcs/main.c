/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:19:10 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/25 19:52:32 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_main_struct	start_game(t_main_struct boss, char *argv[])
{
	boss.win.current_map = 0;
	boss.win.new_map = 0;
	boss.win = read_map(&boss, argv);
	boss.win = window_init(&boss, boss.win);
	boss.img = start_image(&boss);
	return (boss);
}

int	check_argc_size(int argc)
{
	if (argc <= 1)
	{
		ft_printf("No map file received!\n");
		return (0);
	}
	else if (argc > 10)
	{
		ft_printf("To many map file!\n");
		return (0);
	}
	return (1);
}

/**
 * @brief Entry point of the program.
 *
 * It initializes the game window and sets up event hooks for keyboard input
 *  and window close.
 * The main game loop is then started using `mlx_loop`, which continuously
 *  handles events
 * and updates the window display.
 *
 * @return int The exit status of the program.
 */
int	main(int argc, char *argv[])
{
	t_main_struct	boss;

	if (check_argc_size(argc) == 0)
		return (0);
	boss.aux.argc_size = argc - 1;
	boss = start_game(boss, argv);
	mlx_hook(boss.win.mlx_win, 2, 1L << 0, keycode_decisions, &boss);
	boss.img = upgrade_player(&boss, 0);
	mlx_hook(boss.win.mlx_win, 17, 1L, end_game, &boss);
	boss.img = upgrade_player(&boss, 0);
	mlx_loop(boss.win.mlx);
	window_destroy(&boss);
	return (0);
}
