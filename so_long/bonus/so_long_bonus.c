/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:57:31 by seongele          #+#    #+#             */
/*   Updated: 2021/08/17 00:08:34 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_move_minus(t_imap *m, t_xy *i, int *val)
{
	if (m->map->map[i->y][i->x] != '1')
	{
		if ((m->map->map[i->y][i->x] == 'E' && !m->map->c)
			|| m->map->map[i->y][i->x] == 'N')
			exit_msg(m->map->map[i->y][i->x], m->map);
		else if ((m->map->map[i->y][i->x] == 'E' && m->map->c))
			return ;
		else if (m->map->map[i->y][i->x] == 'C')
		{
			m->map->map[i->y][i->x] = 'P';
			m->map->map[m->map->player_y][m->map->player_x] = '0';
			m->map->c--;
			(*val)--;
		}
		else
		{
			m->map->map[i->y][i->x] = 'P';
			m->map->map[m->map->player_y][m->map->player_x] = '0';
			(*val)--;
		}
		m->map->cnt++;
	}
}

void	player_move_plus(t_imap *m, t_xy *i, int *val)
{
	if (m->map->map[i->y][i->x] != '1')
	{
		if ((m->map->map[i->y][i->x] == 'E' && !m->map->c)
			|| m->map->map[i->y][i->x] == 'N')
			exit_msg(m->map->map[i->y][i->x], m->map);
		else if ((m->map->map[i->y][i->x] == 'E' && m->map->c))
			return ;
		else if (m->map->map[i->y][i->x] == 'C')
		{
			m->map->map[i->y][i->x] = 'P';
			m->map->map[m->map->player_y][m->map->player_x] = '0';
			m->map->c--;
			(*val)++;
		}
		else
		{
			m->map->map[i->y][i->x] = 'P';
			m->map->map[m->map->player_y][m->map->player_x] = '0';
			(*val)++;
		}
		m->map->cnt++;
	}
}

int	key_press(int keycode, t_imap *imap)
{
	t_xy	xy;

	xy = (t_xy){imap->map->player_x, imap->map->player_y};
	if (!imap->map->flag)
	{
		if ((keycode == KEY_W || keycode == KEY_UP) && xy.y--)
			player_move_minus(imap, &xy, &(imap->map->player_y));
		else if ((keycode == KEY_S || keycode == KEY_DOWN) && xy.y++)
			player_move_plus(imap, &xy, &imap->map->player_y);
		else if ((keycode == KEY_A || keycode == KEY_LEFT) && xy.x--)
			player_move_minus(imap, &xy, &imap->map->player_x);
		else if ((keycode == KEY_D || keycode == KEY_RIGHT) && xy.x++)
			player_move_plus(imap, &xy, &imap->map->player_x);
	}
	if (keycode == KEY_ESC)
	{
		write(1, "Exit program!\n", 14);
		exit(0);
	}
	return (0);
}

int	main_loop(t_imap *imap)
{
	char	*num;

	num = ft_itoa(imap->map->cnt);
	if (!num)
		error("count print\n", 0);
	if (imap->img->flag < 20)
		imap->img->flag++;
	else if (imap->img->flag < 40)
		imap->img->flag++;
	else
		imap->img->flag = 0;
	if (!imap->map->flag)
	{
		draw_map(imap->map, imap->img);
		mlx_string_put(imap->map->mlx, imap->map->win, imap->map->player_x * 64,
			imap->map->player_y * 64, 0x008000, num);
	}
	else
		draw_end(imap->map);
	free(num);
	num = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_img	img;
	t_map	map;
	t_imap	imap;

	if (argc != 2)
		error("program needs one map argument\n", 0);
	map = (t_map){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	img = (t_img){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	imap = (t_imap){&map, &img};
	map_parsing(&map, argv[1]);
	if (map.width > 40 || map.height > 20)
		error("map size over\n", 0);
	set_enermy(&map);
	map.mlx = mlx_init();
	creat_window_and_xpm_to_image(&map, &img);
	mlx_hook(map.win, X_EVENT_KEY_PRESS, 0, &key_press, &imap);
	mlx_hook(map.win, DESTROYNOTIFY, 0, &program_close, NULL);
	mlx_loop_hook(map.mlx, &main_loop, &imap);
	mlx_loop(map.mlx);
	return (0);
}
