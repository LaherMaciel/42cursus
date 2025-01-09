/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:36:35 by lwencesl          #+#    #+#             */
/*   Updated: 2023/10/02 16:37:50 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

// COLOR CODES
# define CLEAR "\033c"
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define GRAY "\033[1;90m"
# define DEFAULT_COLOR "\033[0m"
# define BOLTED_DEFAULT_COLOR "\033[1;0m"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	int		prev_fd;
	pid_t	pid;
}			t_pipex;

t_pipex	*openning(int argc, char **argv, t_pipex *piper);
int		open_files(char **argv, int i, t_pipex *piper);
void	printfile(int fd, char *filename);
void	create_child(t_pipex *piper);
void	exit_pipex(int error, char *message, t_pipex *piper);
void	my_pipex(char **argv, char **envp);
char	*resolve_command_path(char *cmd, char **envp);
//void	execute_command(char *cmd, char **envp);
void	execute_first_command(char *cmd, char **envp, int infile, int *pipe_fd);
void	execute_second_command(char *cmd, char **envp,
			int outfile, int *pipe_fd);
void	execute_command(char *cmd, char **envp, int input_fd, int output_fd);

#endif