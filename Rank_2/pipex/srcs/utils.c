/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:27:39 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/01/23 18:04:25 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_args(char **args, int fd1, int fd2)
{
	int	i;

	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
	if (fd1)
		close(fd1);
	if (fd2)
		close(fd2);
}

char	*find_the_command(char *cmd, char *path_env)
{
	size_t	i;
	char	**paths;
	char	*full_path;

	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		full_path = ft_strjoin(paths[i], "/");
		if (!full_path)
			break ;
		full_path = ft_strjoin2(full_path, cmd);
		if (!full_path)
			break ;
		if (access(full_path, X_OK) == 0)
			break ;
		free(full_path);
		full_path = NULL;
	}
	free_args(paths, 0, 0);
	return (full_path);
}

char	*get_command_path(char *cmd, char **envp)
{
	char	*path_env;
	char	*full_path;
	size_t	i;

	path_env =  getenv("PATH");
	if (!path_env)
		return (NULL);
	full_path = find_the_command(cmd, path_env);
	if (!full_path)
		ft_fdprintf(2, "pipex: command not found: %s\n", cmd);
	return (full_path);
}

void	execute_command(char *cmd, char **envp, int input_fd, int output_fd)
{
	char	**args;
	char	*cmd_path;

	if (dup2(input_fd, STDIN_FILENO) < 0)
	{
		if (errno == 9 && input_fd == -1)
			exit_pipex(0, "dup2 failed for input_fd");
		else
			exit_pipex(-1, "dup2 failed for input_fd");
	}
	if (dup2(output_fd, STDOUT_FILENO) < 0)
		exit_pipex(-1, "dup2 failed for output_fd");
	args = ft_split(cmd, ' ');
	if (!args)
		exit_pipex(-1, "Failed to parse command");
	cmd_path = get_command_path(args[0], envp);
	if (!cmd_path)
	{
		free_args(args, input_fd, output_fd);
		exit_pipex(0, "");
	}
	close(input_fd);
	close(output_fd);
	execve(cmd_path, args, envp);
	exit_pipex(-1, "Execution failed");
}
