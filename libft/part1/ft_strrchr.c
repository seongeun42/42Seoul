/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:09:50 by seongele          #+#    #+#             */
/*   Updated: 2021/05/05 14:45:44 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	len;

	ptr = (char *)s;
	len = ft_strlen((char *)s) + 1;
	while (--len)
	{
		if (ptr[len] == (char)c)
			return (ptr + len);
	}
	if (ptr[0] == (char)c)
		return (ptr);
	return (0);
}
