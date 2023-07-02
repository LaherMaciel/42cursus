/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:13:45 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/01 23:44:09 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

	a = "Hello";
	map = malloc(10000 * sizeof(char *));
	fds = open(file_name, O_RDONLY);
	if (fds == -1)
		error_call("Failed to read the map file", boss);
	i = 0;
	while (a != NULL)
	{
		a = get_next_line(fds);
		if (a == NULL)
			break ;
		if (ft_strchr(a, '\n'))
		{
			map[i++] = ft_substr(a, 0, ft_strlen(a) - 1);
			free(a);
		}
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
	boss->img = img_vals_init(boss->img);
	boss->win = win_vals_init(boss->win);
	i = 0;
	while (argv[++i])
	{
		check_file_name(boss, argv[i]);
		if (boss->extras.map_names[i - 1])
			free(boss->extras.map_names[i - 1]);
		boss->extras.map_names[i - 1] = ft_substr(argv[i], 0, 0);
	}
	boss->win.mapa = creat_map(boss,
			boss->extras.map_names[0]);
	boss->win = validate_map(boss, boss->win,
			boss->extras.map_names[0]);
	return (boss->win);
}

void	print_map(t_main_struct *boss)
{
	int	i;
	int	j;

	i = -1;
	while (boss->win.mapa[++i])
	{
		j = -1;
		while (boss->win.mapa[i][++j])
		{
			if (boss->win.mapa[i][j] == 'p')
				ft_printf("\033[1;31m%c\033[0m", boss->win.mapa[i][j]);
			else if (boss->win.mapa[i][j] == 'e')
				ft_printf("\033[1;33m%c\033[0m", boss->win.mapa[i][j]);
			else if (boss->win.mapa[i][j] == 'c')
				ft_printf("\033[1;34m%c\033[0m", boss->win.mapa[i][j]);
			else if (boss->win.mapa[i][j] == '1')
				ft_printf("\033[1m%c\033[0m", boss->win.mapa[i][j]);
			else
				ft_printf("\033[1;90m%c\033[0m", boss->win.mapa[i][j]);
		}
		ft_printf("\n");
	}
}
