/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lawences <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:27:39 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/01/09 14:32:00 by lawences         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*resolve_command_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_env;
	char	*full_path;
	size_t	i;

	paths = NULL;
	path_env = NULL;
	full_path = NULL;
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

void	execute_command(char *cmd, char **envp, int input_fd, int output_fd)
{
	char	**args;
	char	*cmd_path;

	if (dup2(input_fd, STDIN_FILENO) < 0)
		exit_pipex(-1, "dup2 failed for input_fd", NULL);
	if (dup2(output_fd, STDOUT_FILENO) < 0)
		exit_pipex(-1, "dup2 failed for output_fd", NULL);
	args = ft_split(cmd, ' ');
	if (!args)
		exit_pipex(-1, "Failed to parse command", NULL);
	cmd_path = resolve_command_path(args[0], envp);
	if (!cmd_path)
		exit_pipex(-1, "Command not found", NULL);
	execve(cmd_path, args, envp);
	exit_pipex(-1, "Execution failed", NULL);
}
