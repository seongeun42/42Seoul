/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:07:14 by seongele          #+#    #+#             */
/*   Updated: 2021/07/26 02:47:06 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_path(char *envp[])
{
	int		i;
	char	*tmp;
	char	**res;

	i = -1;
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

void	heredoc(char *argv[])
{
	int		fd;
	int		gnl;
	char	*line;

	fd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(1, "heredoc> ", 9);
	gnl = get_next_line(0, &line);
	while (gnl > 0 && ft_strncmp(line, argv[2], ft_strlen(line)))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		write(1, "heredoc> ", 9);
		free(line);
		gnl = get_next_line(0, &line);
	}
	free(line);
	close(fd);
}

void	open_outfile(int argc, char *argv[], int fd[], t_i *i)
{
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
		i->out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		i->out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
		heredoc(argv);
	i->in = open(argv[1], O_RDONLY);
	if (i->in == -1)
		error("infile open ");
	dup2(i->in, 0);
	dup2(pfd[1], 1);
	close(i->in);
	close(pfd[1]);
	close(pfd[0]);
}
