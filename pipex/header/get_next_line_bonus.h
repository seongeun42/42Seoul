/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:06:18 by seongele          #+#    #+#             */
/*   Updated: 2021/05/11 20:43:42 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 10

size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*free_strjoin(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			line_return(char **str, char **line, int idx, int read_size);
int			one_line(char **str, char **line, int idx);
int			get_next_line(int fd, char **line);
int			str_free(char **str);
int			find_nl(char *str);

#endif
