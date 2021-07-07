/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:47:27 by seongele          #+#    #+#             */
/*   Updated: 2021/06/08 15:47:59 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 문자를 하나씩 출력하는 함수
void		ft_putchar(char c, int *cnt)
{
	write(1, &c, 1);
	++(*cnt);
}

// 문자열의 길이를 세는 함수
size_t		ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

// 16진수로 된 메모리 주소값를 문자열로 리턴하는 함수
char		*memory_write(t_info *info, unsigned long mem, unsigned long tmp)
{
	t_i	i;

	i = (t_i){ -1, -1, 0, 0 };
	if (!mem && (!info->dot || info->prc < 0))
		i.size = 1;
	while (tmp > 0)
	{
		tmp /= 16;
		i.size++;
	}
	if (info->prc > i.size)
		i.size = info->prc;
	i.str = (char *)malloc(sizeof(char) * (i.size + 2 + 1));
	if (!i.str)
		return (0);
	i.size += 3;
	i.str[--i.size] = '\0';
	while (mem > 0)
	{
		i.str[--i.size] = HEX_BASE_S[mem % 16];
		mem /= 16;
	}
	while (--i.size > 1)
		i.str[i.size] = '0';
	return (i.str);
}

// 10진수 문자열을 위해 사이즈 세는 함수
static int	find_size(t_info *info, long long n)
{
	// 부호는 제외하고 셌음
	int size;

	size = 0;
	// n이 0이고, precision이 0이면 아무것도 출력X니까 size는 0으로 리턴
	if (info->dot && !info->prc && n == 0)
		return (size);
	if (n == -2147483648)
		size = 10;
	if (n == 0)
		size = 1;
	if (n != -2147483648 && n < 0)
		n *= -1;
	while (n > 0)
	{
		++size;
		n /= 10;
	}
	// precision이 size보다 크면 size를 precision에 맞춤
	if (info->prc > size)
		size = info->prc;
	return (size);
}

char		*ft_itoa(t_info *info, long long n)
{
	char	*num;
	int		size;

	// 문자열 사이즈 구하기
	size = find_size(info, n);
	// 공백, + 플래그 있거나 음수면 부호 넣어야 하니까 size + 1
	if (info->space || info->plus || n < 0)
		size += 1;
	// calloc 사용해서 할당해주면서 0으로 초기화
	num = (char *)ft_calloc((size + 1), sizeof(char));
	if (!num)
		return (0);
	num[size] = '\0';
	if (n < 0)
	{
		num[0] = '-';
		num[--size] = '0' - (n % 10);
		n = -1 * (n / 10);
	}
	while (n > 0)
	{
		num[--size] = '0' + (n % 10);
		n /= 10;
	}
	// precision 때문에 주어진 정수보다 size가 크면 남은 부분을 0으로 채워줌
	// size가 0이 되거나, -부호를 만날 때까지 루프
	while (--size >= 0 && num[size] != '-')
		num[size] = '0';
	return (num);
}
