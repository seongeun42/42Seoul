/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:51:14 by seongele          #+#    #+#             */
/*   Updated: 2021/06/22 20:57:25 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	cnt_word(char *str)
{
	char	*tmp;
	size_t	cnt;

	cnt = 0;
	tmp = str;
	while (*tmp != 0)
	{
		while (*tmp != 0 && is_space(*tmp))
			++tmp;
		if (*tmp != 0 && !is_space(*tmp))
			++cnt;
		while (*tmp != 0 && !is_space(*tmp))
		{
			if ((*tmp >= '0' && *tmp <= '9') || *tmp == '+' || *tmp == '-')
				++tmp;
			else
				return (0);
		}
	}
	return (cnt);
}

static char	*save_word(char *str)
{
	char	*word;
	size_t	i;

	i = 0;
	while (str[i] && !is_space(str[i]))
		++i;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	i = -1;
	while (str[++i] != 0 && !is_space(str[i]))
		word[i] = str[i];
	word[i] = '\0';
	return (word);
}

static char	**malloc_free(char **str)
{
	size_t	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		free(str[i]);
		str[i] = 0;
	}
	free(str);
	str = 0;
	return (0);
}

char	**ft_split(char const *s)
{
	char	**words;
	size_t	i;

	if (!s || !cnt_word((char *)s))
		return (0);
	words = (char **)malloc(sizeof(char *) * (cnt_word((char *)s) + 1));
	if (!words)
		return (0);
	i = 0;
	while (*s != 0)
	{
		while (*s != 0 && is_space(*s))
			++s;
		if (*s != 0 && !is_space(*s))
		{
			words[i] = save_word((char *)s);
			if (!words[i++])
				return (malloc_free(words));
		}
		while (*s != 0 && !is_space(*s))
			++s;
	}
	words[i] = 0;
	return (words);
}
