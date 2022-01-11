/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 22:37:23 by seongele          #+#    #+#             */
/*   Updated: 2021/12/03 17:21:45 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->name % 2 == 0)
		if (!time_sleep(philo, 0, philo->info->time_to_eat))
			return (0);
	while (!philo->info->some_died
		&& philo->info->full_philo < philo->info->philo_num)
	{
		pick_fork(philo);
		eating(philo);
		if (philo->info->must_eat && !philo->full
			&& philo->eat_num >= philo->info->must_eat)
		{
			pthread_mutex_lock(&philo->info->full_mutex);
			philo->info->full_philo++;
			pthread_mutex_unlock(&philo->info->full_mutex);
			philo->full = 1;
		}
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}

int	start_thread(t_philo *p)
{
	int	i;

	i = -1;
	gettimeofday(&(p->info->start), NULL);
	while (++i < p[0].info->philo_num)
		if (pthread_create(&(p[i].thread), NULL, philo, (void *)&p[i]))
			return (ERROR);
	return (0);
}

int	program_over(t_info *info, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < info->philo_num)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (ERROR);
		pthread_mutex_destroy(&info->fork[i]);
	}
	pthread_mutex_destroy(&(info->msg_mutex));
	pthread_mutex_destroy(&(info->full_mutex));
	pthread_mutex_destroy(&(info->fork_chk_mutex));
	free(philo);
	free(info->fork);
	free(info->fork_enable);
	return (0);
}

int	check_arg_num(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (ERROR);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philo;

	memset(&info, 0, sizeof(t_info));
	if ((argc == 5 || argc == 6) && !check_arg_num(argc, argv))
	{
		if (make_info(argc, argv, &info))
			return (ERROR);
		philo = set_philo_and_fork(&info);
		if (!philo || start_thread(philo))
			return (ERROR);
		while (!info.some_died && info.full_philo < info.philo_num)
			continue ;
		if (program_over(&info, philo))
			return (ERROR);
		if (!info.some_died && info.full_philo >= info.philo_num)
			printf("\e[107m\e[30mAll philosophers are full!\n\e[0m");
	}
	else
		return (ERROR);
	return (0);
}
