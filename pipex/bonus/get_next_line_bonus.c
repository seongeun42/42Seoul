/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:15:17 by seongele          #+#    #+#             */
/*   Updated: 2021/06/15 19:38:21 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_nl(char *str)
{
	size_t	i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

int	one_line(char **str, char **line, int idx)
{
	char	*tmp;

	if ((*str)[0] == '\n')
		*line = ft_strdup("");
	else
		*line = ft_substr(*str, 0, idx);
	if (!line)
		return (str_free(str));
	tmp = ft_strdup(*str);
	if (!tmp)
		return (str_free(str));
	free(*str);
	*str = 0;
	*str = ft_substr(tmp, idx + 1, ft_strlen(tmp) - idx - 1);
	if (!*str)
		return (str_free(str));
	if (!**str)
		str_free(str);
	free(tmp);
	tmp = 0;
	return (1);
}

int	line_return(char **str, char **line, int idx, int read_size)
{
	if (read_size < 0)
		return (str_free(str));
	else if (!read_size && idx == -1)
	{
		*line = ft_strdup(*str);
		if (!*line)
			return (str_free(str));
		str_free(str);
		return (0);
	}
	return (one_line(str, line, idx));
}

int	get_next_line(int fd, char **line)
{
	static char	*backup[256];
	char		buff[BUFFER_SIZE + 1];
	int			read_size;
	int			check;

	if (!line || fd < 0 || fd > 255 || BUFFER_SIZE < 1)
		return (-1);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	if (!backup[fd])
		return (-1);
	read_size = read(fd, buff, BUFFER_SIZE);
	while (read_size > 0)
	{
		buff[read_size] = '\0';
		backup[fd] = free_strjoin(backup[fd], buff);
		if (!backup[fd])
			return (-1);
		check = find_nl(backup[fd]);
		if (check != -1)
			return (line_return(&backup[fd], line, check, read_size));
		read_size = read(fd, buff, BUFFER_SIZE);
	}
	check = find_nl(backup[fd]);
	return (line_return(&backup[fd], line, check, read_size));
}
