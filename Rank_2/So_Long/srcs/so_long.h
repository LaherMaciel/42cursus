/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:19:36 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/15 19:27:41 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef struct s_data{
	void	*img_wall;
	void	*img_floor;
	void	*img_exit;
	void	*img_player;
	void	*img_collectibles;
	void	*main_image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	int		mapa_length;
	int		mapa_heigth;
	int		length_size;
	int		heigth_size;
	int		colors;
	char	**mapa;
	int		player;
	int		player_x;
	int		player_y;
	int		player_walk;
	int		player_look;
	int		walls;
	int		floor;
	int		collectibles;
	int		exit;
	int		image_length;
	int		image_heigth;
	int		i;
	int		j;
	int		x;
	int		y;
}		t_win;

typedef struct S_aux_vales
{
	unsigned int	color;
	void			*current_image;
	int				current_image_x;
	int				current_image_y;
	char			*address;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				x;
	int				y;

}		t_aux_vales;

typedef struct s_extras
{
	int		boss_x;
	int		boss_y;
	int		boss_walk;
	int		boss_look;
	int		boss_zone;
	int		boss_slash;
	int		boss_health;
	int		boss_changes;
	int		summon1_x;
	int		summon2_x;
	int		summon3_x;
	int		summon1_y;
	int		summon2_y;
	int		summon3_y;
	int		summon1_helth;
	int		summon2_helth;
	int		summon3_helth;
	int		enemy_x;
	int		enemy_y;
	int		enemy_attack;
	float	enemy_attack_delay;
	float	enemy_attack_delay2;
	int		enemy_attack_damage;
	int		enemy_attack_damage2;
	int		enemy_attack_direction;
	int		enemy_attack_number_of_blocks_moved;
	int		enemy_attack_number_of_blocks_moved2;
	int		teleport;
	int		last_attack;
	int		player_health;
}		t_extras;

typedef struct s_main_struct
{
	t_data			img;
	t_win			win;
	t_aux_vales 	aux;
	t_extras		extras;
}				t_main_struct;

//EVENTS
int		keycode_decisions(int keycode, t_win *win);
int		my_close(t_win *win);
void	mov_left(t_win *win);
void	mov_right(t_win *win);
void	mov_up(t_win *win);
void	mov_down(t_win *win);
int		mouse_handler(int mousekey, int x, int y, t_win *win);
int		window_destroy(t_win *win);

//CREAT_MAP
char	**creat_map(void);
char	**read_file(void);
int		map_base_check(t_win map);

//WINDOWS
char			**creat_map_mod(void);
t_win			window_init(t_win win);
void			create_main_image(t_main_struct *boss, void *img_player);
int				window_destroy(t_win *win);
void			window_start(t_main_struct boss);

//MAIN IMAGE

//SECONDARY IMAGE
void	*wall_image(t_win *win);
void	*player_image(t_win *win);
void	*floor_image(t_win *win);
void	*collectibles_image(t_win *win);
void	*exit_image(t_win *win);
void	get_color_of_aux_image(t_aux_vales *aux);

//COLORS
void	*choose_aux_image(t_main_struct *boss, t_data *img);

//ANIMATIONS
void	*walk_up(t_win *win);
void	*walk_down(t_win *win);
void	*walk_left(t_win *win);
void	*walk_right(t_win *win);
void	*look_up(t_win *win);
void	*look_down(t_win *win);
void	*look_left(t_win *win);
void	*look_right(t_win *win);

// PIXEIS
void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);
int		get_pixel(t_aux_vales *aux, int x, int y);
int		aux_get_pixel(t_aux_vales *aux, int x, int y);


#endif // !SO_LONG_H
