/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:53:53 by seongele          #+#    #+#             */
/*   Updated: 2021/07/09 16:54:04 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_map_copy(t_map *map, int i, char *line)
{
	int	j;

	j = -1;
	while (++j < map->width)
	{
		map->map[i][j] = line[j];
		if (line[j] == 'P')
		{
			map->player_x = j;
			map->player_y = i;
		}
	}
	map->map[i][j] = 0;
}

void	make_map_array(t_map *map, int fd)
{
	int		i;
	char	*line;

	map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		error("map malloc error\n", 0);
	i = -1;
	while (++i < map->height)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!map->map[i])
			error("map malloc error\n", 0);
		get_next_line(fd, &line);
		if (!line)
			error("get_next_line Error\n", 0);
		make_map_copy(map, i, line);
		free(line);
		line = 0;
	}
	map->map[i] = 0;
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		++str1;
		++str2;
	}
	return (*str1 - *str2);
}

void	map_parsing(t_map *map, char *mapname)
{
	int	fd;

	if (ft_strcmp(".ber", &mapname[ft_strlen(mapname) - 4]))
		error("Map file extension error\n", 0);
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		error("Map open\n", 1);
	if (is_valid_map(map, fd))
	{
		close(fd);
		fd = open(mapname, O_RDONLY);
		make_map_array(map, fd);
	}
	close(fd);
}
