/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:15:15 by seongele          #+#    #+#             */
/*   Updated: 2021/06/08 16:18:22 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 포맷 파싱하는 함
void	format(char *s, int *i, int *cnt, va_list ap)
{
	t_info	info;	// 플래그 등을 담을 구조체
	int		valid;	// 유효한 포맷인지 확인

	info = (t_info){ 0, 0, 0, 0, 0, 0, 0, 0 };	// 구조체 초기화
	valid = is_valid(s[++(*i)]);	// %다음 문자가 유효한지 확인
	// "-0# +*123456789."라면 반복문 돎
	while (valid >= 0 && valid <= 15)
	{
		// "-0# +" 플래그인지 확인하고 구조체에 저장
		while (valid >= 0 && valid <= 4)
		{
			flag_save(s[*i], &info);
			valid = is_valid(s[++(*i)]);
		}
		// 플래그 끝났으면 width 확인
		wid_save(s, i, &info, ap);
		// width가 음수이면 - 플래그 하나 증가시키고 양수로 만들기
		if (info.width < 0)
		{
			info.minus += 1;
			info.width *= -1;
		}
		// 정밀도 확인
		pre_save(s, i, &info, ap);
		// 다음 문자가 유효한지 확인
		valid = is_valid(s[*i]);
	}
	// "%cspdiuxX"이면 서식지정자 처리 함수 콜
	if (valid >= 16 && valid <= 24)
		specifier(s[*i], cnt, ap, &info);
	else
		--(*i);	// 아니라면 인덱스 하나 줄여서 printf에서 출력되도록 함
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;		// 가변인자 리스트
	int		i;		// 문자열 인덱스
	int		cnt;	// 출력된 문자 개수

	va_start(ap, str);	// 리스트가 첫 번째 가변인수를 가리키도록 초기화
	i = -1;
	cnt = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
			format((char *)str, &i, &cnt, ap);	// 서식지정자 처리
		else
			ft_putchar(str[i], &cnt);	// 서식지정자가 아니면 출력
	}
	va_end(ap);	// 가변 인자 사용이 끝났으므로 포인터를 NULL로 만듦
	return (cnt);
}
