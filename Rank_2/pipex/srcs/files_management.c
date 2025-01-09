/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lawences <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:11:51 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/01/09 14:59:54 by lawences         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
int	open_files(char **argv, int i, t_pipex *piper)
{
	int	fd;

	fd = -1;
	if (i == 1)
	{
		if (access(argv[i], R_OK) == 0)
			fd = open(argv[i], O_RDONLY);
		else
			exit_pipex(-1, "\n", piper);
	}
	else
	{
		if (access(argv[i], W_OK == 0)
			|| (access(argv[i], R_OK) == 0 && access(argv[i], W_OK) == 0))
			fd = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			exit_pipex(-1, "\n", piper);
	}
	if (fd < 0)
		exit_pipex(-2, "\nError opening file", piper);
	ft_printf("File %s is ready to use\n", argv[i]);
	return (fd);
}

t_pipex	*openning(int argc, char **argv, t_pipex *piper)
{
	piper->infile = open_files(argv, 1, piper);
	piper->infile_name = argv[1];
	ft_printf("\n");
	piper->outfile = open_files(argv, argc - 1, piper);
	piper->outfile_name = argv[argc - 1];
	return (piper);
}
*/