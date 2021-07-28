/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:31:39 by seongele          #+#    #+#             */
/*   Updated: 2021/05/03 18:40:37 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*str;
	unsigned char	val;
	size_t			i;

	ptr = (unsigned char *)d;
	str = (unsigned char *)s;
	val = (unsigned char)c;
	i = -1;
	while (++i < n)
	{
		ptr[i] = str[i];
		if (str[i] == val)
			return (d + i + 1);
	}
	return (0);
}
