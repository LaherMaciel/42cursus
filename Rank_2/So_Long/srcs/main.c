/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:19:10 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/07 22:37:53 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_start(t_win win)
{
	t_data	img;
	int		i;

	win.mapa = creat_map_mod();
	//win.mapa = creat_map();
	if (win.mapa == NULL)
		return ;
	if (map_base_check(win) == 0)
	{
		ft_printf("ERROR\n");
		return ;
	}
	ft_printf("%s\n\n", win.mapa[0]);
	win = window_init(win);
	img = create_image(win, player_image(&win));
	mlx_hook(win.mlx_win, 2, 1L<<0, keycode_decisions, &win);
	mlx_hook(win.mlx_win, 17, 1L, window_destroy, &win);
	win.mapa = win.mapa;
	mlx_loop(win.mlx);
	ft_printf("img: %p\n", img);
	i = -1;
	while (win.mapa[++i])
		free(win.mapa[i]);
	free(win.mapa);
}

int	main(void)
{
	t_win	win;

	win.player_look = 0;
	win.exit = 0;
	win.length_size = 1920;
	win.heigth_size = 1080;
	win.image_heigth = 64;
	win.image_length = 64;
	window_start(win);
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
