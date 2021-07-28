/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_modify_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:51:14 by seongele          #+#    #+#             */
/*   Updated: 2021/06/28 17:15:12 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	cnt_word(char *str)
{
	char	*tmp;
	int		flag;
	int		cnt;

	cnt = 0;
	tmp = str;
	flag = 0;
	while (*tmp != 0)
	{
		while (*tmp != 0 && is_space(*tmp))
			++tmp;
		if (*tmp != 0 && !is_space(*tmp))
		{
			++cnt;
			if (*tmp == '\'' || *tmp == '"')
				flag = 1;
			while (*tmp != 0 && (!is_space(*tmp) || flag))
			{
				++tmp;
				if (flag && (*tmp == '\'' || *tmp == '"'))
					flag = 0;
			}
		}
	}
	return (cnt);
}

static char	*save_word(char *str)
{
	t_param	par;

	par = (t_param){0, 0, 0, 0, -1};
	if (str[par.i] == '\'' || str[par.i] == '"')
		par.flag = 1;
	while (str[par.i] && (!is_space(str[par.i]) || par.flag) && ++par.i)
		if (par.flag && (str[par.i] == '\'' || str[par.i] == '"'))
			par.flag = 0;
	if (str[0] == '\'' || str[0] == '"')
		par.i -= 2;
	par.word = (char *)calloc(par.i + 1, sizeof(char));
	if (!par.word)
		return (0);
	par.i = -1;
	while (str[++par.i] && (!is_space(str[par.i]) || par.flag))
	{
		if (!par.flag && (str[par.i] == '\'' || str[par.i] == '"'))
			par.flag = 1;
		else if (par.flag && (str[par.i] == '\'' || str[par.i] == '"'))
			par.flag = 0;
		else
			par.word[++par.j] = str[par.i];
	}
	return (par.word);
}

static char	**malloc_free(char **str)
{
	int	i;

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

char	**ft_split_m(char *s)
{
	t_param	par;

	par = (t_param){0, 0, 0, 0, 0};
	if (!s || !cnt_word(s))
		return (0);
	par.words = (char **)calloc(cnt_word(s) + 1, sizeof(char *));
	if (!par.words)
		return (0);
	while (*s != 0)
	{
		while (*s != 0 && is_space(*s))
			++s;
		if (*s != 0 && !is_space(*s))
		{
			par.words[par.i] = save_word(s);
			if (!par.words[par.i++])
				return (malloc_free(par.words));
			if (*s == '\'' || *s == '"')
				par.flag = 1;
			while (*s != 0 && (!is_space(*s) || par.flag) && ++s)
				if (par.flag && (*s == '\'' || *s == '"'))
					par.flag = 0;
		}
	}
	return (par.words);
}
