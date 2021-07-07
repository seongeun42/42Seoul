/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 03:17:53 by seongele          #+#    #+#             */
/*   Updated: 2021/06/08 15:54:48 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %u : 부호 없는 10진수 정수
void		print_u(t_info *info, va_list ap, int *cnt)
{
	unsigned int	n;
	t_i				i;

	i = (t_i){ -1, -1, 0, 0 };
	n = va_arg(ap, unsigned int);	// 정수값 받아오기
	// %u는 +, 공백 플래그가 정의되지 않았으니까 0으로 만들어줌
	info->plus = 0;
	info->space = 0;
	// itoa를 사용해 정수를 문자열로 변환
	i.str = ft_itoa(info, (long long)n);
	// - 플래그 없으면
	if (!info->minus)
	{
		// 0 플래그가 있고, precision이 없거나 음수일 때
		if (info->zero > 0 && (!info->dot || info->prc < 0))
			// (width - size)만큼 0 출력
			while (++i.align_i < (int)(info->width - ft_strlen(i.str)))
				ft_putchar('0', cnt);
		else
			// (width - size)만큼 공백 출력
			while (++i.align_i < (int)(info->width - ft_strlen(i.str)))
				ft_putchar(' ', cnt);
	}
	// 문자열 출력
	while (i.str[++i.str_i] != 0)
		ft_putchar(i.str[i.str_i], cnt);
	// - 플래그 있으면 왼쪽 정렬을 위해 (width - size)만큼 공백 출력
	if (info->minus > 0)
		while (++i.align_i < (int)(info->width - ft_strlen(i.str)))
			ft_putchar(' ', cnt);
	// 문자열 프리
	free(i.str);
}

// %x, %X 문자열 왼쪽을 위한 함수
static void	left_print(t_info *info, t_i *i, int num, int *cnt)
{
	// - 플래그가 없으면
	if (!info->minus)
	{
		// 0 플래그가 있고, precision이 없거나 음수면
		if (info->zero > 0 && (!info->dot || info->prc < 0))
		{
			// # 플래그가 있고, n이 0이 아닐 때
			if (info->sharp && num != 0)
			{
				// 16진수를 의미하는 0x 혹은 0X를 미리 출력
				ft_putchar(i->str[++i->str_i], cnt);
				ft_putchar(i->str[++i->str_i], cnt);
			}
			// (width - size)만큼 0 출력
			while (++i->align_i < (int)(info->width - ft_strlen(i->str)))
				ft_putchar('0', cnt);
		}
		else
			// 0플래그 없거나 precision이 양수면 그냥 공백 출력
			while (++i->align_i < (int)(info->width - ft_strlen(i->str)))
				ft_putchar(' ', cnt);
	}
}

// %x, %X : 부호 없는 16진수 정수
void		print_x(t_info *info, va_list ap, int *cnt, char *base)
{
	unsigned int	num;
	t_i				i;

	i = (t_i){ -1, -1, 0, 0 };
	num = va_arg(ap, unsigned int);	// 정수를 받아옴
	// 정수를 16진수 문자열로 변환(base에 따라 소문자, 대문자 나뉨)
	i.str = ft_hex_itoa(info, (long long)num, base);
	// 문자열 왼쪽을 위한 함수 호출
	left_print(info, &i, num, cnt);
	// 문자열 출력
	while (i.str[++i.str_i] != 0)
		ft_putchar(i.str[i.str_i], cnt);
	// - 플래그 있으면 (width - size)만큼 공백 출력
	if (info->minus > 0)
		while (++i.align_i < (int)(info->width - ft_strlen(i.str)))
			ft_putchar(' ', cnt);
	// 문자열 프리
	free(i.str);
}

// %% : %출력
void		percent(t_info *info, int *cnt)
{
	int i;

	i = -1;
	// - 플래그 없으면
	if (!info->minus)
	{
		// 0 플래그 있으면
		if (info->zero > 0)
			// (width - 1)만큼 0 출력
			while (++i < info->width - 1)
				ft_putchar('0', cnt);
		else
			// 아니면 공백 출력
			while (++i < info->width - 1)
				ft_putchar(' ', cnt);
	}
	// % 출력
	ft_putchar('%', cnt);
	// - 플래그 있으면 공백 출력
	if (info->minus > 0)
		while (++i < info->width - 1)
			ft_putchar(' ', cnt);
}
