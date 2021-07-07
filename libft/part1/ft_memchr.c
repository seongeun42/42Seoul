/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:09:50 by seongele          #+#    #+#             */
/*   Updated: 2021/05/05 13:41:07 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	val;
	size_t			i;

	if (!n)
		return (0);
	ptr = (unsigned char *)s;
	val = (unsigned char)c;
	i = -1;
	while (++i < n)
		if (ptr[i] == val)
			return ((void *)(ptr + i));
	return (0);
}
