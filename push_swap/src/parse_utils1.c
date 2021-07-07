/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:00:32 by seongele          #+#    #+#             */
/*   Updated: 2021/06/22 21:00:36 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

long long	ft_atoi(const char *str)
{
	int			sign;
	long long	num;

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
		num += ((long long)*str++ - 48);
	}
	num *= sign;
	if (num < -2147483648 || num > 2147483647)
		return (2147483648);
	return (num);
}

int	check_dup(int *stack, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
			if (stack[i] == stack[j])
				return (0);
	}
	return (1);
}

int	malloc_tri_free(char ***str)
{
	size_t	i;
	size_t	j;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			free(str[i][j]);
			str[i][j] = 0;
		}
		free(str[i]);
		str[i] = 0;
	}
	free(str);
	str = 0;
	return (0);
}
