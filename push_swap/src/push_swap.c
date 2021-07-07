/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:53:08 by seongele          #+#    #+#             */
/*   Updated: 2021/06/28 20:42:01 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arg3(t_stack *a, t_stack *b)
{
	int	i;
	int	*stack;

	i = a->top;
	stack = a->stack;
	if (stack[i] < stack[i - 2] && stack[i - 1] > stack[i - 2])
	{
		operation("sa", a, b);
		operation("ra", a, b);
	}
	else if (stack[i] > stack[i - 1] && stack[i] < stack[i - 2])
		operation("sa", a, b);
	else if (stack[i] < stack[i - 1] && stack[i] > stack[i - 2])
		operation("rra", a, b);
	else if (stack[i] > stack[i - 1] && stack[i - 1] < stack[i - 2])
		operation("ra", a, b);
	else if (stack[i] > stack[i - 1] && stack[i - 1] > stack[i - 2])
	{
		operation("ra", a, b);
		operation("sa", a, b);
	}
}

void	sort_arg4(t_stack *a, t_stack *b)
{
	if (!is_sort(a, 4, 0))
	{
		if (a->stack[a->top] > a->stack[a->top - 1])
			operation("sa", a, b);
		operation("pb", a, b);
		if (a->stack[a->top] > a->stack[a->top - 1])
			operation("sa", a, b);
		operation("pb", a, b);
		if (a->stack[a->top] > a->stack[a->top - 1] && \
			b->stack[b->top] < b->stack[b->top - 1])
			operation("ss", a, b);
		else if (a->stack[a->top] > a->stack[a->top - 1])
			operation("sa", a, b);
		else if (b->stack[b->top] < b->stack[b->top - 1])
			operation("sb", a, b);
		operation("pa", a, b);
		if (a->stack[a->top] > a->stack[a->top - 1])
			operation("sa", a, b);
		operation("pa", a, b);
		if (a->stack[a->top] > a->stack[a->top - 1])
			operation("sa", a, b);
	}
}

void	sort_arg5(t_stack *a, t_stack *b)
{
	int	i;
	int	array[5];

	if (!is_sort(a, 5, 0))
	{
		i = -1;
		while (++i < 5)
			array[i] = a->stack[a->top - i];
		bubble_sort(array, 5);
		while (i-- > 0)
		{
			if (a->stack[a->top] <= array[1])
				operation("pb", a, b);
			else
				operation("ra", a, b);
		}
		sort_arg3(a, b);
		if (b->stack[b->top] < b->stack[b->top - 1])
			operation("sb", a, b);
		operation("pa", a, b);
		operation("pa", a, b);
	}
}

void	push_swap(t_stack *a, t_stack *b, int size)
{
	if (is_sort(a, size, 0))
		return ;
	if (size == 2)
	{
		if (a->stack[a->top] > a->stack[a->top - 1])
			operation("sa", a, b);
	}
	else if (size == 3)
		sort_arg3(a, b);
	else if (size == 4)
		sort_arg4(a, b);
	else if (size == 5)
		sort_arg5(a, b);
	else
		a_to_b(a, b, size);
	free(a->stack);
	a->stack = 0;
	free(b->stack);
	b->stack = 0;
}

int	main(int argc, char **argv)
{
	char	***arg;
	int		size;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		exit(1);
	arg = parsing_arg(argv, argc);
	if (!arg)
		error();
	size = count(arg);
	init_stack(&a, &b, size, arg);
	push_swap(&a, &b, size);
	return (0);
}
