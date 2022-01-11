/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 22:37:46 by seongele          #+#    #+#             */
/*   Updated: 2021/12/03 16:50:09 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	make_info(int argc, char *argv[], t_info *info)
{
	int	i;

	i = -1;
	info->philo_num = ft_atoi(argv[1]);
	if (info->philo_num < 1)
		return (ERROR);
	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info->philo_num);
	if (!info->fork)
		return (ERROR);
	info->fork_enable = (int *)malloc(sizeof(int) * info->philo_num);
	if (!info->fork_enable)
	{
		free(info->fork);
		return (ERROR);
	}
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	pthread_mutex_init(&info->msg_mutex, NULL);
	pthread_mutex_init(&info->full_mutex, NULL);
	pthread_mutex_init(&info->fork_chk_mutex, NULL);
	return (0);
}

t_philo	*set_philo_and_fork(t_info *info)
{
	t_philo	*philo;
	int		i;
	int		right;
	int		left;

	philo = (t_philo *)malloc(sizeof(t_philo) * info->philo_num);
	if (!philo)
		return (0);
	i = 0;
	while (++i < info->philo_num)
		pthread_mutex_init(&info->fork[i], NULL);
	i = 0;
	while (++i <= info->philo_num)
	{
		right = i - 1;
		if (i == info->philo_num)
			left = 0;
		else
			left = i;
		philo[i - 1] = (t_philo){0, info, i, 0, left, right, 0, 0,
			&info->fork[right], &info->fork[left]};
		info->fork_enable[i - 1] = 1;
	}
	return (philo);
}
