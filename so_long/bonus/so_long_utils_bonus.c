/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:55:51 by seongele          #+#    #+#             */
/*   Updated: 2021/07/09 16:56:05 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error(char *str, int mod)
{
	if (mod == 0)
	{
		write(1, "Error\n", 6);
		write(1, str, ft_strlen(str));
		exit(1);
	}
	else if (mod == 1)
	{
		write(1, "Error\n", 6);
		perror(str);
		exit(1);
	}
}

void	exit_msg(char c, t_map *map)
{
	if (c == 'E')
		map->flag = 1;
	else if (c == 'N')
		map->flag = 2;
}

void	print_count(int cnt)
{
	char	*num;

	num = ft_itoa(cnt);
	if (!num)
		error("count print\n", 0);
	write(1, "count : ", 8);
	write(1, num, ft_strlen(num));
	write(1, "\n", 1);
	free(num);
	num = 0;
}

void	set_enermy(t_map *map)
{
	int	x;
	int	y;

	y = 1;
	srand(time(NULL));
	while (y < map->height - 1)
	{
		x = 1 + rand() % (map->width - 1);
		while (x < map->width - 1)
		{
			if (map->map[y][x] != 'E' && map->map[y][x] != 'P'
				&& map->map[y][x] != 'C')
				map->map[y][x] = 'N';
			x += rand() % (map->width - 1) + 1;
		}
		y += rand() % (map->height - 1) + 1;
	}
}

int	program_close(void)
{
	write(1, "Exit program!\n", 14);
	exit(0);
	return (0);
}
