/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lawences <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:27:39 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/01/10 21:10:17 by lawences         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		full_path = ft_strjoin(full_path, cmd);
		if (!full_path)
			break ;
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		full_path = NULL;
	}
	return (NULL);
}

char	*get_command_path(char *cmd, char **envp)
{
	char	*path_env;
	size_t	i;

	path_env = NULL;
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_env = envp[i] + 5;
			break ;
		}
	}
	if (!path_env)
		return (NULL);
	return (find_the_command(cmd, path_env));
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
		ft_fdprintf(2, "pipex: command not found: %s\n", args[0]);
		exit_pipex(0, "");
	}
	close(input_fd);
	close(output_fd);
	execve(cmd_path, args, envp);
	exit_pipex(-1, "Execution failed");
}
