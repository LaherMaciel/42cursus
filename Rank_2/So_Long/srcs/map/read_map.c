/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:13:45 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 19:52:20 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief creat a map (array of arrays) using then string i wrote in this function.
 *
 * @return char**, the map.
 */
t_win	creat_map_mod(t_main_struct *boss, t_win win)
{
	char	*map_test;
	char	**map;

	map_test = "11111111111111111111111\n1c000000000000000c00001\n111100000111000000c0001\n1000000001e100000000011\n100c00000001000000000p1\n11111111111111111111111";
	/*map_test =
"11111111111111111111111111111\n\
1ccccccccccc1ccccccccccccccc1\n\
1c111111111c1c1c11111111111c1\n\
1c1ccccc1ccc111c1ccccccccccc1\n\
1ccc1c1ccc1c111c11c111111c111\n\
1c1ccc11111cccccccc1cccccc1c1\n\
1c11c11ccc11111111c1c111111c1\n\
111cc1cc1c1ccc1c1cc1ccccc11c1\n\
1ccc1cc1cccc1ccc1c1c11c1cc1c1\n\
1c111c11c1c1c11c1c1ccc1cc11c1\n\
1c1cccccc1cccc1c11cc1c1c1ccc1\n\
1c1c1111111111cc1cc1cc1c1c111\n\
1c1c1cccccccccc1cc11c1ep1ccc1\n\
1c1c1c1111111111c1c1c111111c1\n\
1ccc1cccccccccccccc1cccccccc1\n\
11111111111111111111111111111";*/
	map = ft_split(map_test, '\n');
	if (map == NULL)
		error_call("Mapa Not Created", boss);
	else
		for (int i = 0; map[i] != NULL; i++)
			printf("%s\n", map[i]);
	win.mapa = map;
	return (validate_map(boss, win));
}

/**
 * @brief creat a array of arrays (map) using the file introduced as parameter.
 *
 * @return char**
 */
t_win	creat_map(t_main_struct *boss, t_win win, char *file_name)
{
	int		fds;
	char	*a;
	char	**map;
	char	**tmp;
	int		i;

	i = 0;
	a = NULL;
	map = NULL;
	fds = open(file_name, O_RDONLY);
	if (fds == -1)
		error_call("Failed to read the map file", boss);
	while ((a = get_next_line(fds)) != NULL)
	{
		tmp = realloc(map, (i + 1) * sizeof(char *));
		if (tmp == NULL)
		{
			free(a);
			close(fds);
			error_call("Failed to allocate memory for the map", boss);
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
	win.mapa = map;
	return (validate_map(boss, win));
}

void	check_file_name(t_main_struct *boss, char *file_name)
{
	char	*substring;

	substring = ft_strnstr(file_name, ".ber", ft_strlen(file_name));
	if (substring == NULL || ft_strlen(substring) != 4)
		error_call("Invalid file termination", boss);
}

t_extras	store_all_maps(t_extras extras, t_win win, int i)
{
	if (i == 0)
		extras.map = win.mapa;
	else if (i == 1)
		extras.map1 = win.mapa;
	else if (i == 2)
		extras.map2 = win.mapa;
	else if (i == 3)
		extras.map3 = win.mapa;
	else if (i == 4)
		extras.map4 = win.mapa;
	else if (i == 5)
		extras.map5 = win.mapa;
	else if (i == 6)
		extras.map6 = win.mapa;
	else if (i == 7)
		extras.map7 = win.mapa;
	else if (i == 8)
		extras.map8 = win.mapa;
	else if (i == 9)
		extras.map9 = win.mapa;
	return (extras);
}

t_win	read_map(t_main_struct *boss, t_win win, char *argv[])
{
	boss->extras = extras_vals_init(boss->extras);
	boss->aux = aux_imgs_init(boss->aux);
	boss->img = img_vals_init(boss->img);
	win = win_vals_init(boss->win);
	int	i;

	i = 0;
	while (argv[++i])
	{
		check_file_name(boss, argv[i]);
		boss->extras.map_names[i] = ft_substr(argv[i], 3, 0);
		win = creat_map(boss, win, argv[i]);
		boss->extras = store_all_maps(boss->extras, win, i);
	}
	return (win);
}
