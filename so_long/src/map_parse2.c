/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:54:27 by seongele          #+#    #+#             */
/*   Updated: 2021/07/09 16:54:36 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_line_valid_f_l(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != '1')
			error("Map Error\n", 0);
}

void	is_line_valid_mid(char *line, t_map *map)
{
	int	i;

	i = -1;
	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
		error("Map Error\n", 0);
	while (line[++i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P')
			error("Map Error\n", 0);
		if (line[i] == 'P' && map->p == 0)
			map->p = 1;
		else if (line[i] == 'P' && map->p == 1)
			error("Multi Player Error\n", 0);
		else if (line[i] == 'C')
			map->c++;
		else if (line[i] == 'E')
			map->e++;
	}
}

void	gnl_last(int gnl, char *line, t_map *map)
{
	if (gnl < 0)
		error("get_next_line Error\n", 0);
	else if (!gnl && *line && (int)ft_strlen(line) == map->width)
	{
		is_line_valid_f_l(line);
		map->height++;
	}
	else if (!gnl && *line && (int)ft_strlen(line) != map->width)
		error("Map Width Error\n", 0);
}

int	is_valid_map(t_map *map, int fd)
{
	char	*line;
	int		gnl;

	gnl = get_next_line(fd, &line);
	is_line_valid_f_l(line);
	map->width = ft_strlen(line);
	if (*line)
	{
		while (gnl > 0)
		{
			if (map->width != (int)ft_strlen(line))
				error("Map Width Error\n", 0);
			map->height++;
			free(line);
			gnl = get_next_line(fd, &line);
			if (gnl)
				is_line_valid_mid(line, map);
		}
		gnl_last(gnl, line, map);
	}
	if (map->c < 1 || map->e < 1 || map->p < 1)
		error("exit, player and collectible need at least one\n", 0);
	free(line);
	return (1);
}
