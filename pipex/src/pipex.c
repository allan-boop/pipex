/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:55:04 by ahans             #+#    #+#             */
/*   Updated: 2024/02/13 16:32:32 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	child_process(char *argv[], char **envp, int *pipefd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0644);
	if (filein == -1)
		ft_error("open filein");
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(pipefd[0]);
	close(filein);
	execute(argv[2], envp);
}

static void	parent_process(char *argv[], char **envp, int *pipefd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
		ft_error("open fileout");
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(pipefd[1]);
	close(fileout);
	execute(argv[3], envp);
}

int	main(int argc, char *argv[], char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(pipefd) == -1)
			ft_error("pipe");
		pid = fork();
		if (pid == -1)
			ft_error("fork");
		if (pid == 0)
			child_process(argv, envp, pipefd);
		parent_process(argv, envp, pipefd);
	}
}
