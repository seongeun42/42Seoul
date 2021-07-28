/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:06:59 by seongele          #+#    #+#             */
/*   Updated: 2021/06/24 21:00:37 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *str)
{
	perror(str);
	exit(1);
}

void	make_exec(char *argv[], char **path, t_cmd *cmd, int idx)
{
	make_cmd(argv[idx], cmd, path);
	execve(cmd->cmd, cmd->param, NULL);
	exit(1);
}

void	child(char *argv[], char **path, int pfd[], int idx)
{
	t_cmd	cmd;
	t_i		i;
	int		cfd[2];

	i = (t_i){0, 0, 0, 0, 0};
	if (idx == 2)
	{
		open_infile(argv, pfd, &i);
		make_exec(argv, path, &cmd, 2);
	}
	else
	{
		if (pipe(cfd) == -1)
			error("pipe ");
		i.pid = fork();
		if (i.pid == 0)
			child(argv, path, cfd, --idx);
		else if (i.pid > 0)
		{
			cmd_pipe(cfd, pfd, &i);
			make_exec(argv, path, &cmd, idx);
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

	i = (t_i){0, 0, 0, 0, 0};
	if (pipe(fd) == -1)
		error("pipe ");
	i.pid = fork();
	if (i.pid == 0)
		child(argv, path, fd, argc - 2);
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

int	main(int argc, char *argv[], char *envp[])
{
	char	**path;
	int		pid;

	if (!(argc == 5))
	{
		write(2, "Error : Not 4 argument\n", 23);
		exit(1);
	}
	path = get_path(envp);
	if (!path)
		exit(1);
	pid = fork();
	if (pid == 0)
		pipex(argc, argv, path);
	else if (pid > 0)
		wait(NULL);
	else
		error("fork ");
	return (0);
}
