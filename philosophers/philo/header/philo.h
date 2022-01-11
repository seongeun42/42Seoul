/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 22:39:17 by seongele          #+#    #+#             */
/*   Updated: 2021/12/03 17:11:35 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define ERROR		-1
# define FORK		"\e[93mhas taken a fork\n\e[0m"
# define EAT		"\e[94mis eating\n\e[0m"
# define SLEEP		"\e[92mis sleeping\n\e[0m"
# define THINK		"\e[97mis thinking\n\e[0m"
# define DIE		"\e[91mdied\n\e[0m"

typedef struct s_info
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				some_died;
	int				full_philo;
	int				*fork_enable;
	struct timeval	start;
	pthread_mutex_t	*fork;
	pthread_mutex_t	msg_mutex;
	pthread_mutex_t	full_mutex;
	pthread_mutex_t	fork_chk_mutex;
}				t_info;

typedef struct s_philo
{
	pthread_t		thread;
	t_info			*info;
	int				name;
	int				eat_num;
	int				left;
	int				right;
	int				full;
	long long		last_eat;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}				t_philo;

/*
** utils.c
*/
int			ft_atoi(char *str);
int			check_die(t_philo *philo);
int			time_sleep(t_philo *philo, long long minus, long long time);
void		print_msg(t_philo *p, char *msg, int die);
long long	get_time(t_philo *philo);

/*
** action.c
*/
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
void		pick_fork(t_philo *philo);
int			one_philo(t_philo *philo);

/*
** philo.c
*/
void		*philo(void *arg);
int			start_thread(t_philo *philo);
int			check_arg_num(int argc, char *argv[]);
int			program_over(t_info *info, t_philo *philo);

/*
** setting.c
*/
t_philo		*set_philo_and_fork(t_info *info);
int			make_info(int argc, char *argv[], t_info *info);

#endif
