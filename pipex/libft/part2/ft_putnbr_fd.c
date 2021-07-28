/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:50:57 by seongele          #+#    #+#             */
/*   Updated: 2021/05/08 11:48:17 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	nbr_div(int nb, int fd)
{
	char	num;

	if (nb == 0)
		return ;
	nbr_div(nb / 10, fd);
	num = '0' + (nb % 10);
	write(fd, &num, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr_div(-(n / 10), fd);
		num = '0' - (n % 10);
	}
	else
	{
		nbr_div(n / 10, fd);
		num = '0' + (n % 10);
	}
	write(fd, &num, 1);
}
