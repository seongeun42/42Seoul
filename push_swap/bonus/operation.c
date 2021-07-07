/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:01:24 by seongele          #+#    #+#             */
/*   Updated: 2021/06/22 21:01:26 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	s(t_stack *stack)
{
	int	tmp;

	if (stack->top < 1)
		return (0);
	else
	{
		tmp = stack->stack[stack->top];
		stack->stack[stack->top] = stack->stack[stack->top - 1];
		stack->stack[stack->top - 1] = tmp;
	}
	return (1);
}

int	p(t_stack *pop, t_stack *push)
{
	if (pop->top == -1)
		return (0);
	else
	{
		push->top++;
		push->stack[push->top] = pop->stack[pop->top];
		pop->top--;
	}
	return (1);
}

int	r_rr(int i, t_stack *stack)
{
	int	tmp;
	int	idx;

	if (stack->top < 1)
		return (0);
	else if (i == 0)
	{
		tmp = stack->stack[stack->top];
		idx = stack->top + 1;
		while (--idx > 0)
			stack->stack[idx] = stack->stack[idx - 1];
		stack->stack[0] = tmp;
	}
	else if (i == 1)
	{
		tmp = stack->stack[0];
		idx = -1;
		while (++idx < stack->top)
			stack->stack[idx] = stack->stack[idx + 1];
		stack->stack[stack->top] = tmp;
	}
	return (1);
}

void	operation(char *str, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(str, "sa"))
		s(a);
	else if (!ft_strcmp(str, "sb"))
		s(b);
	else if (!ft_strcmp(str, "ss") && s(a))
		s(b);
	else if (!ft_strcmp(str, "pa"))
		p(b, a);
	else if (!ft_strcmp(str, "pb"))
		p(a, b);
	else if (!ft_strcmp(str, "ra"))
		r_rr(0, a);
	else if (!ft_strcmp(str, "rb"))
		r_rr(0, b);
	else if (!ft_strcmp(str, "rr") && r_rr(0, a))
		r_rr(0, b);
	else if (!ft_strcmp(str, "rra"))
		r_rr(1, a);
	else if (!ft_strcmp(str, "rrb"))
		r_rr(1, b);
	else if (!ft_strcmp(str, "rrr") && r_rr(1, a))
		r_rr(1, b);
	else
		error();
}

void	operation_double(char *str, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(str, "ss") && a->top >= 1 && b->top < 1)
		operation("sa", a, b);
	else if (!ft_strcmp(str, "ss") && a->top < 1 && b->top >= 1)
		operation("sb", a, b);
	else if (!ft_strcmp(str, "ss") && a->top >= 1 && b->top >= 1)
		operation("ss", a, b);
	if (!ft_strcmp(str, "rr") && a->top >= 1 && b->top < 1)
		operation("ra", a, b);
	else if (!ft_strcmp(str, "rr") && a->top < 1 && b->top >= 1)
		operation("rb", a, b);
	else if (!ft_strcmp(str, "rr") && a->top >= 1 && b->top >= 1)
		operation("rr", a, b);
	if (!ft_strcmp(str, "rrr") && a->top >= 1 && b->top < 1)
		operation("rra", a, b);
	else if (!ft_strcmp(str, "rrr") && a->top < 1 && b->top >= 1)
		operation("rrb", a, b);
	else if (!ft_strcmp(str, "rrr") && a->top >= 1 && b->top >= 1)
		operation("rrr", a, b);
	else
		error();
}
