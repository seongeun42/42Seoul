/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:31:39 by seongele          #+#    #+#             */
/*   Updated: 2021/05/08 12:22:49 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char *ptr;
	unsigned char *str;

	if (!dest && !src)
		return (0);
	ptr = (unsigned char *)dest;
	str = (unsigned char *)src;
	while (size--)
		ptr[size] = str[size];
	return (dest);
}
