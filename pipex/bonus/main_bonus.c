/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:14:00 by seongele          #+#    #+#             */
/*   Updated: 2021/06/28 17:14:01 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	**path;
	char	*rm_param[3];
	int		pid;

	if (argc < 4)
		error("Argments atleast 3 ");
	rm_param[0] = "-f";
	rm_param[1] = "here_doc";
	rm_param[2] = NULL;
	path = get_path(envp);
	if (!path)
		exit(1);
	pid = fork();
	if (pid == 0)
		pipex(argc, argv, path);
	else if (pid > 0)
	{
		wait(NULL);
		if (!access("here_doc", 0))
			execve("/bin/rm", rm_param, NULL);
		exit(1);
	}
	else
		error("fork ");
	return (0);
}
