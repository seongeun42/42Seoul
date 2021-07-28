/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:48:44 by seongele          #+#    #+#             */
/*   Updated: 2021/05/08 12:06:17 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_size(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		++size;
		n *= -1;
	}
	while (n > 0)
	{
		++size;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		size;

	size = find_size(n);
	num = (char *)malloc(sizeof(char) * (size + 1));
	if (!num)
		return (0);
	num[size] = '\0';
	if (n == 0)
		num[0] = '0';
	if (n < 0)
	{
		num[0] = '-';
		num[--size] = '0' - (n % 10);
		n = -1 * (n / 10);
	}
	while (n > 0)
	{
		num[--size] = '0' + (n % 10);
		n /= 10;
	}
	return (num);
}
