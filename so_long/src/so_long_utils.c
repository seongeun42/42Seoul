/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:55:05 by seongele          #+#    #+#             */
/*   Updated: 2021/07/09 17:05:03 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	write(1, "🦶🏻 count : ", 17);
	write(1, num, ft_strlen(num));
	write(1, "\n", 1);
	free(num);
	num = 0;
}

int	program_close(void)
{
	write(1, "Exit program!\n", 14);
	exit(0);
	return (0);
}
