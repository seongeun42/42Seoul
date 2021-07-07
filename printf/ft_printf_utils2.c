/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 04:16:51 by seongele          #+#    #+#             */
/*   Updated: 2021/06/08 15:48:15 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 메모리 초기화하는 함수
void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char *)b;
	while (len)
		ptr[--len] = c;
	return (b);
}

// 동적할당하면서 0으로 초기화하는 함수
void		*ft_calloc(size_t count, size_t size)
{
	void *arr;

	arr = malloc(size * count);
	if (!arr)
		return (0);
	ft_memset(arr, 0, count * size);
	return (arr);
}

// hex_itoa 함수에 문자열 사이즈 리턴하는 함수
static int	find_size_hex(t_info *info, long long n)
{
	int size;
	int tmp;

	tmp = n;
	size = 0;
	// n이 0이고, precision이 0이면 아무것도 출력 안 하니까 size는 0으로 반환
	if (info->dot && !info->prc && n == 0)
		return (size);
	if (n == 0)
		size = 1;
	while (n > 0)
	{
		++size;
		n /= 16;
	}
	// precision이 size보다 크면 size를 precision으로 맞춤(남은 부분은 0으로 채움)
	if (info->dot && info->prc > size)
		size = info->prc;
	// # 플래그가 있고, n이 0이 아니면 0x / 0X 들어갈 자리 +2
	if (info->sharp && tmp != 0)
		size += 2;
	return (size);
}

char		*ft_hex_itoa(t_info *info, long long n, char *base)
{
	char	*num;
	int		size;
	int		tmp;

	tmp = n;
	// 할당할 문자열 사이즈 찾기
	size = find_size_hex(info, n);
	// 동적할당해주면서 0으로 초기화
	num = (char *)ft_calloc((size + 1), sizeof(char));
	if (!num)
		return (0);
	num[size] = '\0';
	while (n > 0)
	{
		num[--size] = base[n % 16];
		n /= 16;
	}
	// precision 때문에 주어진 정수보다 사이즈가 크면 남은 부분을 0으로 채움
	while (--size >= 0)
		num[size] = '0';
	// # 플래그가 있으면 base에 따라 맨 앞에 0x / 0X 넣어줌
	if (base[10] == 'a' && tmp != 0 && info->sharp)
		num[1] = 'x';
	else if (base[10] == 'A' && tmp != 0 && info->sharp)
		num[1] = 'X';
	return (num);
}
