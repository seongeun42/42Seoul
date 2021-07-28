/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:42:11 by seongele          #+#    #+#             */
/*   Updated: 2021/05/03 22:13:01 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char	*cmp_find;
	char	*cmp_str;
	char	*ptr_find;
	char	*ptr_str;
	size_t	i[2];

	ptr_find = (char *)to_find;
	ptr_str = (char *)str;
	if (*ptr_find == '\0')
		return (ptr_str);
	i[0] = -1;
	while (++i[0] < len && *ptr_str != '\0')
	{
		cmp_find = ptr_find;
		cmp_str = ptr_str;
		i[1] = i[0] - 1;
		while (++i[1] < len && *cmp_find == *cmp_str++ && *cmp_find != '\0')
			++cmp_find;
		if (*cmp_find == '\0')
			return (ptr_str);
		++ptr_str;
	}
	return (0);
}
