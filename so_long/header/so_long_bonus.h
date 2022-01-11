/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:48:06 by seongele          #+#    #+#             */
/*   Updated: 2021/07/09 17:43:42 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>
# include "../libft/libft.h"
# include "get_next_line.h"

# define X_EVENT_KEY_PRESS 2
# define DESTROYNOTIFY 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_ESC 53

typedef struct s_map
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**map;
	int		player_x;
	int		player_y;
	int		cnt;
	int		p;
	int		e;
	int		c;
	int		flag;
}				t_map;

typedef struct s_img
{
	int		width;
	int		height;
	int		flag;
	void	*wall;
	void	*space;
	void	*collect;
	void	*exit;
	void	*player;
	void	*enermy_1;
	void	*enermy_2;
}				t_img;

typedef struct s_valid
{
	int	p;
	int	e;
	int	c;
}				t_valid;

typedef struct s_imap
{
	t_map	*map;
	t_img	*img;
}				t_imap;

typedef struct s_xy
{
	int	x;
	int	y;
}			t_xy;

void	error(char *str, int mod);

int		ft_strcmp(char *s1, char *s2);
int		is_valid_map(t_map *map, int fd);
void	is_line_valid_f_l(char *line);
void	is_line_valid_mid(char *line, t_map *map);
void	gnl_last(int gnl, char *line, t_map *map);
void	make_map_copy(t_map *map, int i, char *line);
void	make_map_array(t_map *map, int fd);
void	map_parsing(t_map *map, char *mapname);

void	creat_window_and_xpm_to_image(t_map *map, t_img *img);
void	p_i_to_w(t_map *map, t_img *img, t_xy *xy, void *texture);
void	draw_map(t_map *map, t_img *img);
void	draw_end(t_map *map);

void	exit_msg(char c, t_map *map);
void	print_count(int cnt);
void	set_enermy(t_map *map);
int		program_close(void);

void	player_move_minus(t_imap *m, t_xy *i, int *val);
void	player_move_plus(t_imap *m, t_xy *i, int *val);
int		key_press(int keycode, t_imap *imap);
int		main_loop(t_imap *imap);

#endif
