/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:17:43 by seongele          #+#    #+#             */
/*   Updated: 2021/05/18 20:32:08 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define HEX_BASE_S "0123456789abcdef"
# define HEX_BASE_B "0123456789ABCDEF"

typedef struct	s_info
{
	int minus;
	int zero;
	int width;
	int dot;
	int prc;
	int sharp;
	int space;
	int plus;
}				t_info;

typedef struct	s_i
{
	int		align_i;
	int		str_i;
	int		size;
	char	*str;
}				t_i;

int				ft_printf(const char *str, ...);

void			format(char *s, int *i, int *cnt, va_list ap);
void			specifier(char c, int *cnt, va_list ap, t_info *info);
void			wid_save(char *s, int *i, t_info *info, va_list ap);
void			pre_save(char *s, int *i, t_info *info, va_list ap);
void			flag_save(char c, t_info *info);
int				is_valid(char c);

void			percent(t_info *info, int *cnt);
void			print_c(t_info *info, va_list ap, int *cnt);
void			print_s(t_info *info, va_list ap, int *cnt);
void			print_p(t_info *info, va_list ap, int *cnt);
void			print_di(t_info *info, va_list ap, int *cnt);
void			print_u(t_info *info, va_list ap, int *cnt);
void			print_x(t_info *info, va_list ap, int *cnt, char *base);

size_t			ft_strlen(const char *str);
void			ft_putchar(char c, int *cnt);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_calloc(size_t count, size_t size);
char			*memory_write(t_info *info, unsigned long m, unsigned long t);
char			*ft_itoa(t_info *info, long long n);
char			*ft_hex_itoa(t_info *info, long long n, char *base);

#endif
