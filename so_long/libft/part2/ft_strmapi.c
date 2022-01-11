/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:51:38 by seongele          #+#    #+#             */
/*   Updated: 2021/05/06 19:09:06 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	size;
	size_t	i;

	if (!s)
		return (0);
	size = ft_strlen((char *)s);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	i = -1;
	while (++i < size)
		str[i] = f(i, s[i]);
	str[i] = '\0';
	return (str);
}
