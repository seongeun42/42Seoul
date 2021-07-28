/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:51:14 by seongele          #+#    #+#             */
/*   Updated: 2021/05/08 11:58:35 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_deli(char c, char deli)
{
	if (c == deli)
		return (1);
	return (0);
}

static int	cnt_word(char *str, char deli)
{
	char	*tmp;
	size_t	cnt;

	cnt = 0;
	tmp = str;
	while (*tmp != 0)
	{
		while (*tmp != 0 && is_deli(*tmp, deli))
			++tmp;
		if (*tmp != 0 && !is_deli(*tmp, deli))
			++cnt;
		while (*tmp != 0 && !is_deli(*tmp, deli))
			++tmp;
	}
	return (cnt);
}

static char	*save_word(char *str, char deli)
{
	char	*word;
	size_t	i;

	i = 0;
	while (str[i] && !is_deli(str[i], deli))
		++i;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	i = -1;
	while (str[++i] != 0 && !is_deli(str[i], deli))
		word[i] = str[i];
	word[i] = '\0';
	return (word);
}

static char	**malloc_free(char **str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	i;

	if (!s)
		return (0);
	words = (char **)malloc(sizeof(char *) * (cnt_word((char *)s, c) + 1));
	if (!words)
		return (0);
	i = 0;
	while (*s != 0)
	{
		while (*s != 0 && is_deli(*s, c))
			++s;
		if (*s != 0 && !is_deli(*s, c))
		{
			words[i] = save_word((char *)s, c);
			if (!words[i++])
				return (malloc_free(words));
		}
		while (*s != 0 && !is_deli(*s, c))
			++s;
	}
	words[i] = 0;
	return (words);
}
