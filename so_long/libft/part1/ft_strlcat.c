/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:58:04 by seongele          #+#    #+#             */
/*   Updated: 2021/05/03 20:26:21 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	count_d;
	size_t	count_s;
	char	*ptr;

	ptr = (char *)src;
	count_d = ft_strlen(dest);
	count_s = ft_strlen(ptr);
	i = 0;
	j = count_d;
	while (*ptr != 0 && i + count_d + 1 < size)
	{
		*(dest + j) = *ptr;
		ptr++;
		j++;
		i++;
	}
	if (i + count_d < size)
		*(dest + j) = '\0';
	if (size < count_d)
		i = count_s + size;
	else
		i = count_s + count_d;
	return (i);
}
