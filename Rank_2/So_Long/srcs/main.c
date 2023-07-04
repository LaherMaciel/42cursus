/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:19:10 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 20:33:37 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Start the game initializing the game structures, validating the map
 * and creating the game window and game image.
 * This function initializes the game by setting up the initial values of
 * game structures, reading the map file, initializing the game window, and
 * starting the game image. The updated game structure is returned.
 * 
 * @param boss The main game structure.
 * @param argv The command-line arguments containing the map file names.
 * @return t_main_struct The updated game structure.
*/
t_main_struct	load_game(t_main_struct boss, char *argv[])
{
	boss.win.total_collected = 0;
	boss.aux.total_mov = 0;
	boss.win.current_map = 0;
	boss.win.new_map = 0;
	boss.win.mapa = NULL;
	boss.win = read_map(&boss, argv);
	boss.win = window_init(&boss, boss.win);
	boss.img = start_image(&boss);
	return (boss);
}

/**
 * @brief Check the number of command-line arguments.
 * This function checks the number of command-line arguments passed to the
 * program. It ensures that at least one map file is received and that the
 * number of map files does not exceed the maximum limit of 10. If the
 * conditions are not met, appropriate error messages are displayed. The
 * function returns 1 if the check fails, indicating an error, and returns 0
 * if the check passes.
 * 
 * @param argc The number of command-line arguments.
 * @return int Returns 1 if the check passes, 0 otherwise.
*/
int	check_argc_size(int argc)
{
	if (argc <= 1)
	{
		ft_printf("\033[1;31mERROR:\033[0m No map file received"\
			"\033[1;31m!!\033[0m\n");
		return (1);
	}
	else if (argc > 10)
	{
		ft_printf("\033[1;31mERROR:\033[0m To many map file (max 10)"\
			"\033[1;31m!!\033[0m\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_main_struct	boss;

	if (check_argc_size(argc) == 1)
		return (0);
	boss.aux.argc_size = argc - 1;
	boss = load_game(boss, argv);
	mlx_hook(boss.win.mlx_win, 2, 1L << 0, keycode_decisions, &boss);
	boss.img = upgrade_player(&boss, 0);
	mlx_hook(boss.win.mlx_win, 17, 1L, end_game, &boss);
	boss.img = upgrade_player(&boss, 0);
	mlx_loop(boss.win.mlx);
	window_destroy(&boss);
	return (0);
}
