/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:09:50 by seongele          #+#    #+#             */
/*   Updated: 2021/05/05 13:58:23 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	i = -1;
	ptr = (char *)s;
	len = ft_strlen((char *)s) + 1;
	while (++i < len)
	{
		if (ptr[i] == (char)c)
			return (ptr + i);
	}
	return (0);
}
