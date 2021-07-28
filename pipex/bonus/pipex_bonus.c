/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:06:59 by seongele          #+#    #+#             */
/*   Updated: 2021/07/26 02:55:44 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error(char *str)
{
	perror(str);
	exit(1);
}

void	cmd_pipe(int cfd[], int pfd[], t_i *i)
{
	waitpid(i->pid, &i->status, WCONTINUED);
	dup2(cfd[0], 0);
	dup2(pfd[1], 1);
	close(cfd[1]);
	close(cfd[0]);
	close(pfd[1]);
	close(pfd[0]);
}

void	make_exec(char *argv[], char **path, t_cmd *cmd, int idx)
{
	make_cmd(argv[idx], cmd, path);
	execve(cmd->cmd, cmd->param, NULL);
	exit(1);
}

void	child(char *argv[], char **path, int pfd[], t_i *idx)
{
	t_cmd	cmd;
	t_i		i;
	int		cfd[2];

	i = (t_i){0, 0, 0, 0, 0, 0};
	if (idx->idx == idx->stop)
	{
		open_infile(argv, pfd, &i);
		make_exec(argv, path, &cmd, idx->idx);
	}
	else
	{
		if (pipe(cfd) == -1)
			error("pipe ");
		i.pid = fork();
		if (i.pid == 0 && (idx->idx)--)
			child(argv, path, cfd, idx);
		else if (i.pid > 0)
		{
			cmd_pipe(cfd, pfd, &i);
			make_exec(argv, path, &cmd, idx->idx);
		}
		else
			error("fork");
	}
}

void	pipex(int argc, char *argv[], char **path)
{
	t_cmd	cmd;
	t_i		i;
	int		fd[2];

	i = (t_i){0, 0, 0, 0, argc - 2, 2};
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
		i.stop = 3;
	if (pipe(fd) == -1)
		error("pipe ");
	i.pid = fork();
	if (i.pid == 0)
		child(argv, path, fd, &i);
	else if (i.pid > 0)
	{
		waitpid(i.pid, &i.status, WCONTINUED);
		open_outfile(argc, argv, fd, &i);
		make_cmd("cat", &cmd, path);
		execve(cmd.cmd, cmd.param, NULL);
		exit(1);
	}
	else
		error("fork ");
}
