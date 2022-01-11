/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:12:41 by seongele          #+#    #+#             */
/*   Updated: 2021/07/09 16:56:48 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	creat_window_and_xpm_to_image(t_map *map, t_img *img)
{
	map->win = mlx_new_window(map->mlx, 64 * map->width,
			64 * map->height, "so_long");
	img->wall = mlx_xpm_file_to_image(map->mlx, "img/wall.xpm",
			&img->width, &img->height);
	img->space = mlx_xpm_file_to_image(map->mlx, "img/space.xpm",
			&img->width, &img->height);
	img->collect = mlx_xpm_file_to_image(map->mlx, "img/collectible.xpm",
			&img->width, &img->height);
	img->exit = mlx_xpm_file_to_image(map->mlx, "img/exit.xpm",
			&img->width, &img->height);
	img->player = mlx_xpm_file_to_image(map->mlx, "img/cookie_2.xpm",
			&img->width, &img->height);
	img->enermy_1 = mlx_xpm_file_to_image(map->mlx, "img/enermy1.xpm",
			&img->width, &img->height);
	img->enermy_2 = mlx_xpm_file_to_image(map->mlx, "img/enermy2.xpm",
			&img->width, &img->height);
	if (!map->win || !img->wall || !img->space || !img->collect || !img->exit
		|| !img->player || !img->enermy_1 || !img->enermy_2)
		error("Image not found\n", 0);
}

void	p_i_to_w(t_map *map, t_img *img, t_xy *xy, void *texture)
{
	mlx_put_image_to_window(map->mlx, map->win, texture,
		xy->x * img->width, xy->y * img->height);
}

void	draw_map(t_map *map, t_img *img)
{
	t_xy	xy;

	xy = (t_xy){-1, -1};
	while (++xy.y < map->height)
	{
		xy.x = -1;
		while (++xy.x < map->width)
		{
			if (map->map[xy.y][xy.x] == '1')
				p_i_to_w(map, img, &xy, img->wall);
			else if (map->map[xy.y][xy.x] == '0')
				p_i_to_w(map, img, &xy, img->space);
			else if (map->map[xy.y][xy.x] == 'C')
				p_i_to_w(map, img, &xy, img->collect);
			else if (map->map[xy.y][xy.x] == 'E')
				p_i_to_w(map, img, &xy, img->exit);
			else if (map->map[xy.y][xy.x] == 'P')
				p_i_to_w(map, img, &xy, img->player);
			else if (map->map[xy.y][xy.x] == 'N' && img->flag < 20)
				p_i_to_w(map, img, &xy, img->enermy_1);
			else if (map->map[xy.y][xy.x] == 'N' && img->flag < 40)
				p_i_to_w(map, img, &xy, img->enermy_2);
		}
	}
}

void	draw_end(t_map *map)
{
	void	*img;
	int		width;
	int		height;

	width = 0;
	height = 0;
	if (map->flag == 1)
	{
		img = mlx_xpm_file_to_image(map->mlx, "img/clear.xpm",
				&width, &height);
		mlx_clear_window(map->mlx, map->win);
		mlx_put_image_to_window(map->mlx, map->win, img,
			(64 * map->width) / 2 - 100, (64 * map->height) / 2 - 30);
	}
	else if (map->flag == 2)
	{
		img = mlx_xpm_file_to_image(map->mlx, "img/game_over.xpm",
				&width, &height);
		mlx_clear_window(map->mlx, map->win);
		mlx_put_image_to_window(map->mlx, map->win, img,
			(64 * map->width) / 2 - 100, (64 * map->height) / 2 - 60);
	}
}
