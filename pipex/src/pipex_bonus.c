/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahans <ahans@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:55:04 by ahans             #+#    #+#             */
/*   Updated: 2024/02/13 15:23:43 by ahans            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	child_process_bonus(char *argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		ft_error("pipe");
	pid = fork();
	if (pid == -1)
		ft_error("fork");
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (argc >= 5)
	{
		fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fileout == -1)
			ft_error("open fileout");
		i = 2;
		filein = open(argv[1], O_RDONLY, 0644);
		if (filein == -1)
			ft_error("open filein");
		dup2(filein, STDIN_FILENO);
		while (i < argc - 2)
			child_process_bonus(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		close(fileout);
		execute(argv[argc - 2], envp);
	}
}
