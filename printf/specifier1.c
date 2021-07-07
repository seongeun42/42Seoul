/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:30:27 by seongele          #+#    #+#             */
/*   Updated: 2021/06/08 15:55:48 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %c : 문자
void		print_c(t_info *info, va_list ap, int *cnt)
{
	int i;

	i = -1;
	// - 플래그가 없으면 오른쪽 정렬을 하기 위해 (width - 1)만큼 공백 출력
	if (!info->minus)
		while (++i < info->width - 1)
			ft_putchar(' ', cnt);
	// 인자값 받아와서 문자 하나 출력
	ft_putchar((char)va_arg(ap, int), cnt);
	// - 플래그가 있으면 왼쪽 정렬을 하기 위해 (width - 1)만큼 공백 출력
	if (info->minus > 0)
		while (++i < info->width - 1)
			ft_putchar(' ', cnt);
}

// %s : 문자열
void		print_s(t_info *info, va_list ap, int *cnt)
{
	// 인덱스 등을 위해 만든 구조체
	t_i		i;

	i = (t_i){ -1, -1, 0, 0 };	// 구조체 초기화
	i.str = va_arg(ap, char *);	// 문자열 인자 받아옴
	// 문자열이 NULL이면 (null) 대입
	if (!i.str)
		i.str = "(null)";
	// precision값이 음수가 아니고, 문자열 길이보다 작으면 size를 precision값으로 설정 
	if (info->dot && info->prc != -1 && info->prc < (int)ft_strlen(i.str))
		i.size = info->prc;
	// 그 외에는 사이즈를 문자열의 길이만큼 설정
	else
		i.size = ft_strlen(i.str);
	// 만약 - 플래그가 없다면
	if (!info->minus)
	{
		// 0 플래그가 있고, precision이 없다면(원본은 s에 0플래그X)
		if (info->zero > 0 && !info->dot)
			// 문자열의 왼쪽을 (width - size)만큼 0으로 채움
			while (++i.align_i < info->width - i.size)
				ft_putchar('0', cnt);
		else
			// 아니라면 오른쪽 정렬을 위해 공백으로 채움
			while (++i.align_i < info->width - i.size)
				ft_putchar(' ', cnt);
	}
	// 문자열이 끝나거나, precision값이 0이 될 때까지 출력 
	while (i.str[++i.str_i] != 0 && (!info->dot || info->prc--))
		ft_putchar(i.str[i.str_i], cnt);
	// - 플래그가 있다면
	if (info->minus > 0)
		// 왼쪽 정렬을 위해 (width - size)만큼 공백 출력
		while (++i.align_i < info->width - i.size)
			ft_putchar(' ', cnt);
}

// %p : 메모리 주소
void		print_p(t_info *info, va_list ap, int *cnt)
{
	char	*memory;
	void	*ptr;
	t_i		i;

	i = (t_i){ -1, -1, 0, 0 };
	ptr = va_arg(ap, void *);	// 주소 인자 받아옴
	// 메모리 주소를 16진수로 된 문자열로 받음
	memory = memory_write(info, (long long)ptr, (long long)ptr);
	// 주소 맨 앞에 0x 넣기
	memory[0] = '0';
	memory[1] = 'x';
	// 문자열 사이즈
	i.size = ft_strlen(memory);
	// - 플래그가 없다면
	if (!info->minus)
		// 오른쪽 정렬을 위해 (width - size)만큼 공백으로 채움
		while (++i.align_i < info->width - i.size)
			ft_putchar(' ', cnt);
	// 메모리 문자열 출력
	while (memory[++i.str_i] != 0)
		ft_putchar(memory[i.str_i], cnt);
	// - 플래그가 있다면
	if (info->minus > 0)
		// 왼쪽 정렬을 위해 (width - size)만큼 공백 출력
		while (++i.align_i < info->width - i.size)
			ft_putchar(' ', cnt);
	// 메모리 프리
	free(memory);
}

// %d, %i에서 문자열 왼쪽을 위한함수
static void	left_print(t_info *info, t_i *i, int n, int *cnt)
{
	// - 플래그가 없으면
	if (!info->minus)
	{
		// 0 플래그가 있고, precision이 없거나 음수일 때
		if (info->zero > 0 && (!info->dot || info->prc < 0))
		{
			// 음수거나, 공백 플래그, + 플래그가 있으면 부호 먼저 출력
			if (n < 0 || info->space || info->plus)
				ft_putchar(i->str[++i->str_i], cnt);
			// width - size만큼 0 출력 
			while (++i->align_i < (int)(info->width - ft_strlen(i->str)))
				ft_putchar('0', cnt);
		}
		else	// 0 플래그가 없거나 precision이 양수면
			// width - size만큼 공백 출력
			while (++i->align_i < (int)(info->width - ft_strlen(i->str)))
				ft_putchar(' ', cnt);
	}
}

// %d, %i : 부호 있는 10진수 정수
void		print_di(t_info *info, va_list ap, int *cnt)
{
	int		n;
	t_i		i;

	i = (t_i){ -1, -1, 0, 0 };
	n = va_arg(ap, int);	// 정수 인자 받아옴
	// itoa로 정수를 문자열로 변환
	i.str = ft_itoa(info, (long long)n);
	// n이 양수이고, + 플래그 있으면 문자열 제일 앞에 + 대입(+가 우선시 됨)
	if (n >= 0 && info->plus)
		i.str[0] = '+';
	// n이 양수이고, 공백 플래그 있으면 문자열 제일 앞에 공백 대입
	else if (n >= 0 && info->space)
		i.str[0] = ' ';
	// 문자열의 왼쪽 확인 및 출력
	left_print(info, &i, n, cnt);
	// 문자열 출력
	while (i.str[++i.str_i] != 0)
		ft_putchar(i.str[i.str_i], cnt);
	// - 플래그 있으면
	if (info->minus > 0)
		// 왼쪽 정렬을 위해 (width - size)만큼 공백 출력
		while (++i.align_i < (int)(info->width - ft_strlen(i.str)))
			ft_putchar(' ', cnt);
	// 문자열 free
	free(i.str);
}
