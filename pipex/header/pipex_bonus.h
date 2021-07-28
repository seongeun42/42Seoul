/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:19:13 by seongele          #+#    #+#             */
/*   Updated: 2021/07/26 02:44:13 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_cmd
{
	char	*cmd;
	char	**param;
}				t_cmd;

typedef struct s_i
{
	int	pid;
	int	in;
	int	out;
	int	status;
	int	idx;
	int	stop;
}				t_i;

typedef struct s_param
{
	char	**words;
	char	*word;
	int		flag;
	int		i;
	int		j;
}				t_param;

char			**ft_split_m(char *s);
char			**get_path(char *envp[]);
void			make_cmd(char *str, t_cmd *cmd, char **path);
void			child(char *argv[], char **path, int pfd[], t_i *idx);
void			pipex(int argc, char *argv[], char **path);
void			heredoc(char *argv[]);
void			open_outfile(int argc, char *argv[], int fd[], t_i *i);
void			open_infile(char *argv[], int pfd[], t_i *i);
void			cmd_pipe(int cfd[], int pfd[], t_i *i);
void			make_exec(char *argv[], char **path, t_cmd *cmd, int idx);
void			error(char *str);

#endif
