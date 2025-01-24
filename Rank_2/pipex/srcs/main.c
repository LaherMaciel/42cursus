/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:52:25 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/01/23 23:54:44 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	send_to_outfile(int prev_fd, char **argv, char **envp, int i)
{
	pid_t	pid;
	int		outfile;

	outfile = open(argv[ft_strstrlen(argv) - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		exit_pipex(-1, "Failed to open outfile");
	pid = fork();
	if (pid < 0)
		exit_pipex(-1, "Fork failed for last command");
	if (pid == 0)
		execute_command(argv[i], envp, prev_fd, outfile);
	close(prev_fd);
	close(outfile);
	while (wait(NULL) > 0)
		;
}

int	fork_it(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit_pipex(-1, "Fork failed");
	return (pid);
}

void	pipex(int argc, char **argv, char **envp, int infile)
{
	int		i;
	int		prev_fd;
	int		pipe_fd[2];

	prev_fd = infile;
	i = 1;
	while (++i < argc - 2)
	{
		if (pipe(pipe_fd) < 0)
			exit_pipex(-1, "Pipe creation failed");
		if (fork_it() == 0)
		{
			close(pipe_fd[0]);
			execute_command(argv[i], envp, prev_fd, pipe_fd[1]);
		}
		close(pipe_fd[1]);
		if (prev_fd != infile)
			close(prev_fd);
		else
			close(infile);
		prev_fd = pipe_fd[0];
	}
	send_to_outfile(prev_fd, argv, envp, i);
}

int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;

	if (argc < 5)
		exit_pipex(-2, "Error: incorrect input: Try ./pipex "
			"file1 cmd1 cmd2 ... cmdN file2");
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		ft_fdprintf(STDERR_FILENO, "pipex: %s: %s\n",
			strerror(errno), argv[1]);
	outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		exit_pipex(-3, argv[argc - 1]);
	close(outfile);
	pipex(argc, argv, envp, infile);
	return (0);
}
