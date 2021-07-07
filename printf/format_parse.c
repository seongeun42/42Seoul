/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:29:40 by seongele          #+#    #+#             */
/*   Updated: 2021/06/08 15:53:38 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 포맷 문자열이 유효한 것들로만 이루어졌는지 확인하는 함수
int		is_valid(char c)
{
	char	*arr;
	int		i;

	arr = "-0# +*123456789.\%cspdiuxX";
	i = -1;
	while (arr[++i])
		if (arr[i] == c)
			return (i);
	return (-1);
}

// 구조체에 있는 플래그 정보 업데이트하는 함수
void	flag_save(char c, t_info *info)
{
	if (c == '-')
		info->minus += 1;
	if (c == '0')
		info->zero += 1;
	if (c == '#')
		info->sharp += 1;
	if (c == ' ')
		info->space += 1;
	if (c == '+')
		info->plus += 1;
}

// width 확인 함수
void	wid_save(char *s, int *i, t_info *info, va_list ap)
{
	// 만약 와일드 카드가 있다면 가변인자 받아와서 넣기
	if (s[(*i)++] == '*')
		info->width = va_arg(ap, int);
	else if (s[--(*i)] >= '0' && s[*i] <= '9')	// 그냥 숫자라면
		while (s[*i] >= '0' && s[*i] <= '9') // 숫자가 끝날 때까지 루프
			// int형으로 변환해서 width 업데이트
			info->width = (info->width * 10) + (int)(s[(*i)++] - '0');
}

// precision 확인 함수
void	pre_save(char *s, int *i, t_info *info, va_list ap)
{
	// .이 있을 때만 처리
	if (s[(*i)++] == '.')
	{
		info->dot += 1;
		// 만약 와일드 카드가 있다면 가변인자 받아와서 넣기
		if (s[(*i)++] == '*')
			info->prc = va_arg(ap, int);
		// 와일드 카드가 아니면 늘려놓은 인덱스를 하나 줄이고 숫자인지 확인
		else if (s[--(*i)] >= '0' && s[*i] <= '9')
			// 숫자가 끝날 때까리 루프
			while (s[*i] >= '0' && s[*i] <= '9')
				// int형으로 변환해서 precision 업데이트
				info->prc = (info->prc * 10) + (int)(s[(*i)++] - '0');
	}
	else	// .이 없다면 위에서 늘려놓은 인덱스를 하나 줄임
		--(*i);
	// 만약 와일드 카드로 들어온 정밀도 값이 음수라면 -1로 설정
	if (info->prc < 0)
		info->prc = -1;
}

// 서식지정자 처리 함수 콜하는 함수
void	specifier(char c, int *cnt, va_list ap, t_info *info)
{
	if (c == '%')
		percent(info, cnt);
	if (c == 'c')
		print_c(info, ap, cnt);
	if (c == 's')
		print_s(info, ap, cnt);
	if (c == 'p')
		print_p(info, ap, cnt);
	if (c == 'd')
		print_di(info, ap, cnt);
	if (c == 'i')
		print_di(info, ap, cnt);
	if (c == 'u')
		print_u(info, ap, cnt);
	if (c == 'x')
		print_x(info, ap, cnt, HEX_BASE_S);
	if (c == 'X')
		print_x(info, ap, cnt, HEX_BASE_B);
}
