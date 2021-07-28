/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:51:53 by seongele          #+#    #+#             */
/*   Updated: 2021/05/06 21:17:40 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	front;
	size_t	back;

	if (!s1 || !set)
		return ((char *)s1);
	if (!*s1)
		return (ft_strdup(""));
	front = 0;
	back = ft_strlen((char *)s1) - 1;
	while (s1[front] != 0 && ft_strchr((char *)set, s1[front]))
		++front;
	while (back > 0 && ft_strchr((char *)set, s1[back]))
		--back;
	if (front > back)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (back - front + 2));
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + front, back - front + 2);
	return (str);
}
