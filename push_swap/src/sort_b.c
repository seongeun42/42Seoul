/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:56:56 by seongele          #+#    #+#             */
/*   Updated: 2021/06/22 20:57:10 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_b(t_stack *a, t_stack *b, int size)
{
	if (size >= 2)
	{
		if (b->stack[b->top] < b->stack[b->top - 1])
			operation("sb", a, b);
		if (size == 3)
		{
			if (!is_sort(b, size, 1))
			{
				operation("rb", a, b);
				operation("sb", a, b);
				operation("rrb", a, b);
				if (b->stack[b->top] < b->stack[b->top - 1])
					operation("sb", a, b);
			}
			operation("pa", a, b);
		}
		operation("pa", a, b);
	}
	operation("pa", a, b);
	return (1);
}

void	divide_b(t_stack *a, t_stack *b, int size, t_piv_cnt *piv_cnt)
{
	while (size-- > 0)
	{
		if (b->stack[b->top] < piv_cnt->small)
		{
			operation("rb", a, b);
			piv_cnt->rb++;
		}
		else if (b->stack[b->top] >= piv_cnt->big)
		{
			operation("pa", a, b);
			piv_cnt->pa++;
		}
		else
		{
			operation("pa", a, b);
			piv_cnt->pa++;
			operation("ra", a, b);
			piv_cnt->ra++;
		}
	}
}

int	b_to_a(t_stack *a, t_stack *b, int size)
{
	t_piv_cnt	piv_cnt;
	int			rrr_size;

	if (size <= 3)
		return (sort_b(a, b, size));
	piv_cnt = (t_piv_cnt){0, 0, 0, 0, 0, 0};
	sort_and_pivot(b, size, &piv_cnt, 1);
	divide_b(a, b, size, &piv_cnt);
	a_to_b(a, b, (piv_cnt.pa - piv_cnt.ra));
	rrr_size = piv_cnt.ra;
	while (rrr_size-- > 0)
		operation_double("rrr", a, b);
	a_to_b(a, b, piv_cnt.ra);
	b_to_a(a, b, piv_cnt.rb);
	return (1);
}
