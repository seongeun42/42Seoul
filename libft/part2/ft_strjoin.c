/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:51:28 by seongele          #+#    #+#             */
/*   Updated: 2021/05/06 21:50:51 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy(char *dest, char *src)
{
	while (*src != '\0')
		*dest++ = *src++;
	return (dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*tmp;
	size_t	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!size)
	{
		str = (char *)malloc(1);
		*str = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	tmp = copy(str, (char *)s1);
	tmp = copy(tmp, (char *)s2);
	*tmp = '\0';
	return (str);
}
