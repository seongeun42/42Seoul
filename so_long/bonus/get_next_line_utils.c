/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:14:35 by seongele          #+#    #+#             */
/*   Updated: 2021/06/13 00:15:34 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_g(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

char	*ft_strdup_g(const char *src)
{
	int		len;
	char	*dest;

	len = 0;
	while (src[len])
		len++;
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (0);
	dest[len] = '\0';
	while (--len >= 0)
		dest[len] = src[len];
	return (dest);
}

int	str_free(char **str)
{
	free(*str);
	*str = 0;
	return (-1);
}

char	*free_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*tmp;
	size_t	size[2];

	if (!s1)
		return (ft_strdup_g(s2));
	size[0] = ft_strlen_g(s1) + ft_strlen_g(s2);
	if (!size[0])
	{
		free(s1);
		return (ft_strdup_g(""));
	}
	str = (char *)malloc(sizeof(char) * (size[0] + 1));
	if (str != 0)
	{
		size[1] = -1;
		tmp = str;
		while (s1[++size[1]] != '\0')
			*tmp++ = s1[size[1]];
		while (*s2 != '\0')
			*tmp++ = *s2++;
		*tmp = '\0';
	}
	free(s1);
	return (str);
}

char	*ft_substr_g(char *s, unsigned int start, int len)
{
	char	*str;
	int		i;
	int		size;

	if (!s)
		return (0);
	size = ft_strlen_g(s);
	if (size < (int)start)
		return (ft_strdup_g(""));
	if (size < (int)start + len)
		len = size - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = -1;
	while (++i < len)
	{
		str[i] = s[start];
		if (!s[start++])
			break ;
	}
	str[i] = '\0';
	return (str);
}
