/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:19:10 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/15 00:57:30 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief creat the map, initialize the window, put
 * the first image on the window.
 *
 * @param win
 */
void	window_start(t_main_struct boss)
{
	int	i;
	boss.win.mapa = creat_map_mod();
	//boss.win.mapa = creat_map();
	if (boss.win.mapa == NULL)
		return ;
	if (map_base_check(boss.win) == 0)
	{
		ft_printf("ERROR\n");
		return ;
	}
	ft_printf("%s\n\n", boss.win.mapa[0]);
	boss.win = window_init(boss.win);
	boss.img = create_image(&boss, player_image(&boss));
	mlx_hook(boss.win.mlx_win, 2, 1L<<0, keycode_decisions, &boss);
	mlx_hook(boss.win.mlx_win, 17, 1L, window_destroy, &boss);
	boss.win.mapa = boss.win.mapa;
	mlx_loop(boss.win.mlx);
	ft_printf("img: %p\n", boss.img);
	i = -1;
	while (boss.win.mapa[++i])
		free(boss.win.mapa[i]);
	free(boss.win.mapa);
}

int	main(void)
{
	t_main_struct	boss;

	boss.win.player_look = 0;
	boss.win.exit = 0;
	boss.win.length_size = 1920;
	boss.win.heigth_size = 1080;
	boss.win.image_heigth = 64;
	boss.win.image_length = 64;
	window_start(boss);
	return (0);
}

/*
int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world");
	mlx_loop(mlx);
	return (0);
}*/


/*
typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
*/
