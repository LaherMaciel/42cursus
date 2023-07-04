/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:13:45 by lwencesl          #+#    #+#             */
/*   Updated: 2023/07/04 23:18:46 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**add_to_map(char *a, char **map, int i)
{
	if (ft_strchr(a, '\n'))
	{
		map[i] = ft_substr(a, 0, ft_strlen(a) - 1);
		free(a);
	}
	else
		map[i] = a;
	return (map);
}

/**
 * @brief Create a map array from the file specified.
 * 
 * This function reads the map file line by line and stores each line in the
 * map array. The map array is dynamically allocated and terminated with a
 * NULL pointer. The file descriptor is closed after reading.
 * 
 * @param boss The main game structure.
 * @param file_name The name of the map file.
 * @return char** The map array.
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
		map = add_to_map(a, map, i);
		i++;
	}
	map[i] = NULL;
	close(fds);
	return (map);
}

/**
 * @brief Check the file name for validity.
 * 
 * This function verifies if the file name has a valid termination.
 * It checks if the file name ends with ".ber" and has exactly 4 characters.
 * If the file name is invalid, an error is raised using the error_call function.
 * 
 * @param boss The main game structure.
 * @param file_name The name of the file to be checked.
*/
void	check_file_name(t_main_struct *boss, char *file_name)
{
	char	*substring;

	substring = ft_strnstr(file_name, ".ber", ft_strlen(file_name));
	if (substring == NULL || ft_strlen(substring) != 4)
		error_call("Invalid file termination", boss);
}

/**
 * @brief Read the map from the file names provided as arguments.
 * 
 * This function initializes the necessary structures and reads the map data
 * from the files specified in the command line arguments. It iterates over
 * the file names, checks their validity, and stores them in the map_names
 * array of the extras structure. It then calls the creat_map function to
 * create the map based on the first file. Finally, it validates the map
 * using the validate_map function and returns the updated win structure.
 * 
 * @param boss The main game structure.
 * @param argv The command line arguments containing the file names.
 * @return The updated win structure.
*/
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
