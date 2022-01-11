/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:14:29 by seongele          #+#    #+#             */
/*   Updated: 2021/12/05 18:46:47 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	num;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-')
	{
		sign *= -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += ((int)*str++ - 48);
	}
	num *= sign;
	return (num);
}

long long	get_time(t_philo *philo)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return ((current.tv_sec - philo->info->start.tv_sec) * 1000
		+ (current.tv_usec - philo->info->start.tv_usec) / 1000);
}

void	print_msg(t_philo *p, char *msg, int die)
{
	pthread_mutex_lock(&p->info->msg_mutex);
	if (p->info->some_died
		|| p->info->full_philo >= p->info->philo_num)
	{
		pthread_mutex_unlock(&p->info->msg_mutex);
		return ;
	}
	printf("%lldms\t%d\t%s", get_time(p), p->name, msg);
	if (die)
		p->info->some_died = 1;
	pthread_mutex_unlock(&p->info->msg_mutex);
}

int	check_die(t_philo *philo)
{
	if (get_time(philo) - philo->last_eat > philo->info->time_to_die)
	{
		print_msg(philo, DIE, 1);
		return (1);
	}
	return (0);
}

int	time_sleep(t_philo *philo, long long minus, long long time)
{
	while (get_time(philo) - minus < time)
	{
		if (check_die(philo))
			return (0);
		usleep(100);
	}
	return (1);
}
