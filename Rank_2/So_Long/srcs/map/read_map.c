/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:13:45 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/23 00:15:38 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief creat a map (array of arrays) using then string i wrote in this function.
 *
 * @return char**, the map.
 */
/*
char	**creat_map_mod(t_main_struct *boss)
{
	char	*map_test;
	char	**map;

	map_test = "11111111111111111111111\n1c000000000000000c00001\n111100000111000000c0001\n1000000001e100000000011\n100c00000001000000000p1\n11111111111111111111111";
// 	map_test =
// "11111111111111111111111111111\n\
// 1ccccccccccc1ccccccccccccccc1\n\
// 1c111111111c1c1c11111111111c1\n\
// 1c1ccccc1ccc111c1ccccccccccc1\n\
// 1ccc1c1ccc1c111c11c111111c111\n\
// 1c1ccc11111cccccccc1cccccc1c1\n\
// 1c11c11ccc11111111c1c111111c1\n\
// 111cc1cc1c1ccc1c1cc1ccccc11c1\n\
// 1ccc1cc1cccc1ccc1c1c11c1cc1c1\n\
// 1c111c11c1c1c11c1c1ccc1cc11c1\n\
// 1c1cccccc1cccc1c11cc1c1c1ccc1\n\
// 1c1c1111111111cc1cc1cc1c1c111\n\
// 1c1c1cccccccccc1cc11c1ep1ccc1\n\
// 1c1c1c1111111111c1c1c111111c1\n\
// 1ccc1cccccccccccccc1cccccccc1\n\
// 11111111111111111111111111111";
	map = ft_split(map_test, '\n');
	if (map == NULL)
		error_call("Mapa Not Created", boss);
	else
		for (int i = 0; map[i] != NULL; i++)
			printf("%s\n", map[i]);
	return (map);
}
*/
/**
 * @brief creat a array of arrays (map) using the file introduced as parameter.
 *
 * @return char**
 */
char	**creat_map(t_main_struct *boss, char *file_name)
{
	int		fds;
	char	*a;
	char	**map;
	int		i;

	a = NULL;
	map = malloc(10000 * sizeof(char*));
	fds = open(file_name, O_RDONLY);
	if (fds == -1)
		error_call("Failed to read the map file", boss);
	i = 0;
	while ((a = get_next_line(fds)) != NULL)
	{
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

void	check_file_name(t_main_struct *boss, char *file_name)
{
	char	*substring;

	substring = ft_strnstr(file_name, ".ber", ft_strlen(file_name));
	if (substring == NULL || ft_strlen(substring) != 4)
		error_call("Invalid file termination", boss);
}

t_win	read_map(t_main_struct *boss, char *argv[])
{
	int	i;

	boss->extras = extras_vals_init(boss->extras);
	boss->aux = aux_imgs_init(boss->aux);
	boss->img = img_vals_init(boss->img);
	boss->win = win_vals_init(boss->win);
	i = 0;
	while (argv[++i])
	{
		check_file_name(boss, argv[i]);
		free(boss->extras.map_names[i - 1]);
		boss->extras.map_names[i - 1] = ft_substr(argv[i], 0, 0);
	}
	i = -1;
	while (boss->extras.map_names[++i])
		ft_printf("\n%s\n", boss->extras.map_names[i]);
	boss->win.mapa = creat_map(boss,
		boss->extras.map_names[0]);
	boss->win = validate_map(boss, boss->win,
		boss->extras.map_names[0]);
	i = -1;
	ft_printf("\n");
	while (boss->win.mapa[++i])
		ft_printf("%s\n", boss->win.mapa[i]);
	ft_printf("\n");
	return (boss->win);
}
