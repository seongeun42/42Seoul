/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_uilts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:07:14 by seongele          #+#    #+#             */
/*   Updated: 2021/06/22 21:07:16 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char *envp[])
{
	int		i;
	char	*tmp;
	char	**res;

	i = 0;
	while (envp[++i])
		if (ft_strnstr(envp[i], "PATH=", 5))
			tmp = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	res = ft_split(tmp, ':');
	if (!res)
		error("Error : get path fail");
	free(tmp);
	tmp = 0;
	return (res);
}

void	make_cmd(char *str, t_cmd *cmd, char **path)
{
	char	**split;

	split = ft_split_m(str);
	if (!split)
		exit(1);
	while (*path)
	{
		cmd->cmd = ft_strjoin(*path, "/", 0);
		if (!cmd->cmd)
			exit(1);
		cmd->cmd = ft_strjoin(cmd->cmd, split[0], 1);
		if (!cmd->cmd)
			exit(1);
		if (!access(cmd->cmd, 0))
			break ;
		free(cmd->cmd);
		path++;
	}
	if (!(*path))
	{
		write(2, "Error : Not exists command\n", 27);
		exit(1);
	}
	cmd->param = split;
}

void	open_outfile(int argc, char *argv[], int fd[], t_i *i)
{
	i->out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (i->out == -1)
		error("outfile open ");
	dup2(i->out, 1);
	dup2(fd[0], 0);
	close(i->out);
	close(fd[1]);
	close(fd[0]);
}

void	open_infile(char *argv[], int pfd[], t_i *i)
{
	i->in = open(argv[1], O_RDONLY);
	if (i->in == -1)
		error("infile open ");
	dup2(i->in, 0);
	dup2(pfd[1], 1);
	close(i->in);
	close(pfd[1]);
	close(pfd[0]);
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
