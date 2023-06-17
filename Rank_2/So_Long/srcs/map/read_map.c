/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:13:45 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/17 04:02:43 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief creat a map (array of arrays) using then string i wrote in this function.
 * 
 * @return char**, the map.
 */
char	**creat_map_mod(void)
{
	char	*map_test;
	char	**map;

	map_test = "11111111111111111111111\n1p000000000000000000001\n10000000000000000000001\n100000000c0000000000001\n100000000000000000000e1\n11111111111111111111111";
	/*map_test =
"1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n\
1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001\n\
1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001\n\
1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001\n\
10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000c0000000000001\n\
1000000000000000000000000000000000000p00000000c00000000000000000000000000000000000000000000000000000000000001\n\
1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001\n\
1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001\n\
1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001\n\
1000000000000000000000000111111111111111111111111111111111111111111111100000000000000000000000000000000000001\n\
1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001\n\
1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001\n\
1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001\n\
10000000000000000000000000000000000000000c0000000000000000000000000000000000000000000000000000000000000000001\n\
1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001\n\
1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001\n\
1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001\n\
1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001\n\
1000000000000000e00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001\n\
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";*/
	map = ft_split(map_test, '\n');
	if (map == NULL)
		return (0);
	else
		for (int i = 0; map[i] != NULL; i++)
			printf("%s\n", map[i]);
	return (map);
}

/**
 * @brief creat a array of arrays (map) using the file introduced as parameter.
 * 
 * @return char** 
 */
char	**creat_map(void)
{
	int		fds;
	char	*a;
	char	**map;
	char	**tmp;
	int		i;
	//int		cont;

	//cont = 1;
	i = 0;
	a = NULL;
	map = NULL;
	fds = open("mapa2.txt", O_RDONLY);
	if (fds == -1)
	{
		ft_printf("ERROR\n");
		return (NULL);
	}
	while ((a = get_next_line(fds)) != NULL)
	{
		//ft_printf("%i - %s", cont++, a);
		tmp = realloc(map, (i + 1) * sizeof(char *));
		if (tmp == NULL)
		{
			ft_printf("ERROR\n");
			free(a);
			close(fds);
			return NULL;
		}
		map = tmp;
		if (ft_strchr(a, '\n'))
			map[i++] = ft_substr(a, 0, ft_strlen(a) - 1);
		else
			map[i++] = a;
	}
	map[i] = NULL;
	ft_printf("\n");
	close(fds);
	return (map);
}

/**
 * @brief does the basic checks to see if the map is valid like
 *  see if the map has only 1 player, only 1 exit, if it has at least
 *  1 collectible and if the map is surrounded by walls.
 * 
 * @param win 
 * @return int 
 */
int	map_base_check(t_main_struct *boss, t_win *win)
{
	int	x;
	int	y;
	int	x_max_len;
	int	y_max_len;
	int	base_max_y_len;
	int	player;
	int	exit;
	int	collectible;

	x = -1;
	player = 0;
	exit = 0;
	collectible = 0;
	x_max_len = 0;
	while (win->mapa[++x])
		x_max_len++;
	x_max_len--;
	x = -1;
	base_max_y_len = ft_strlen(win->mapa[0]) - 1;
	if ((win->mapa[0][0] != '1') || (win->mapa[x_max_len][base_max_y_len] != '1'))
		error_call("Mapa Not Surrounded by Walls", boss);
	while (++x < x_max_len)
	{
		y = -1;
		y_max_len = ft_strlen(win->mapa[x]) - 1;
		ft_printf("x_max_len -> %i\n", x_max_len);
		ft_printf("y_max_len -> %i\n", y_max_len);
		ft_printf("base_max_y_len -> %i\n", base_max_y_len);
		if (base_max_y_len != y_max_len)
			error_call("The Mapa Is Not a Rectangle", boss);
		while (win->mapa[x][++y])
		{
			ft_printf("%c", win->mapa[x][y]);
			if ((win->mapa[0][y] != '1') || (win->mapa[x][0] != '1'))
				error_call("Mapa Not Surrounded by Walls", boss);
			else if ((win->mapa[x_max_len][y] != '1')
				|| (win->mapa[x][y_max_len] != '1'))
				error_call("Mapa Not Surrounded by Walls", boss);
			else if (win->mapa[x][y] == 'p')
				player++;
			else if (win->mapa[x][y] == 'e')
				exit++;
			else if (win->mapa[x][y] == 'c')
				collectible++;
			else if (win->mapa[x][y] != '0' && win->mapa[x][y] != '1')
				error_call("Unidentified Characters on The Map", boss);
		}
		ft_printf("\n");
	}
	if (player != 1 || exit != 1 || collectible < 1)
		error_call("Number of Players Different then 1\n OR\nNumber of"\
		" exits Different then 1\nOR\nNumber of collectibles smaller then 1", boss);
	return (1);
}
