/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 22:37:31 by seongele          #+#    #+#             */
/*   Updated: 2021/12/03 17:15:57 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_msg(philo, FORK, 0);
	while (1)
	{
		if (check_die(philo))
		{
			pthread_mutex_unlock(philo->l_fork);
			return (1);
		}
		usleep(100);
	}
	return (1);
}

void	pick_fork(t_philo *philo)
{
	if (philo->info->philo_num == 1)
		if (one_philo(philo))
			return ;
	while (1)
	{
		pthread_mutex_lock(&(philo->info->fork_chk_mutex));
		if (philo->info->fork_enable[philo->left]
			&& philo->info->fork_enable[philo->right])
		{
			philo->info->fork_enable[philo->left] = 0;
			philo->info->fork_enable[philo->right] = 0;
			pthread_mutex_lock(philo->r_fork);
			print_msg(philo, FORK, 0);
			pthread_mutex_lock(philo->l_fork);
			print_msg(philo, FORK, 0);
			pthread_mutex_unlock(&(philo->info->fork_chk_mutex));
			break ;
		}
		else
		{
			pthread_mutex_unlock(&(philo->info->fork_chk_mutex));
			if (check_die(philo))
				return ;
		}
	}
}

void	eating(t_philo *philo)
{
	long long	eat_start_time;

	if (philo->info->some_died
		|| philo->info->full_philo >= philo->info->philo_num)
		return ;
	print_msg(philo, EAT, 0);
	philo->eat_num += 1;
	eat_start_time = get_time(philo);
	if (!time_sleep(philo, eat_start_time, philo->info->time_to_eat))
		return ;
	philo->last_eat = get_time(philo);
	philo->info->fork_enable[philo->left] = 1;
	philo->info->fork_enable[philo->right] = 1;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo)
{
	long long	sleep_start_time;

	if (philo->info->some_died
		|| philo->info->full_philo >= philo->info->philo_num)
		return ;
	print_msg(philo, SLEEP, 0);
	philo->last_eat = get_time(philo) - philo->info->time_to_eat - 1;
	sleep_start_time = get_time(philo);
	if (!time_sleep(philo, sleep_start_time, philo->info->time_to_sleep))
		return ;
}

void	thinking(t_philo *philo)
{
	if (philo->info->some_died
		|| philo->info->full_philo >= philo->info->philo_num)
		return ;
	philo->last_eat = get_time(philo) - philo->info->time_to_sleep;
	print_msg(philo, THINK, 0);
}
