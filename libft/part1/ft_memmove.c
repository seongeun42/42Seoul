/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:25:58 by seongele          #+#    #+#             */
/*   Updated: 2021/05/08 11:29:11 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*ptr;
	unsigned char	*dst;
	size_t			i;

	ptr = (unsigned char *)src;
	dst = (unsigned char *)dest;
	i = -1;
	if (dest < src)
		while (++i < len)
			dst[i] = ptr[i];
	if (dest > src)
		while (len--)
			dst[len] = ptr[len];
	return (dest);
}
