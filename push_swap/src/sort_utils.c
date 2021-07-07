/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:53:17 by seongele          #+#    #+#             */
/*   Updated: 2021/06/22 20:56:03 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
			}
		}
	}
}

int	is_sort(t_stack *stack, int size, int mod)
{
	int	idx;
	int	bottom;

	idx = stack->top + 1;
	bottom = stack->top - size + 1;
	if (mod == 0)
	{
		while (--idx > bottom)
			if (stack->stack[idx] > stack->stack[idx - 1])
				return (0);
	}
	else if (mod == 1)
	{
		while (--idx > bottom)
			if (stack->stack[idx] < stack->stack[idx - 1])
				return (0);
	}
	return (1);
}

// void	sort_and_pivot(t_stack *stack, int size, t_piv_cnt *pivot, int mod)
// {
// 	int	i;
// 	int	term;
// 	int	array[size];

// 	i = -1;
// 	while (++i < size)
// 		array[i] = stack->stack[stack->top - i];
// 	bubble_sort(array, size);
// 	term = size / 3;
// 	if (size % 3 == 2)
// 		term++;
// 	if (mod == 0)
// 	{
// 		pivot->small = array[(size - 1) - (term * 2)];
// 		pivot->big = array[(size - 1) - term];
// 	}
// 	else if (mod == 1)
// 	{
// 		pivot->small = array[term];
// 		pivot->big = array[term * 2];
// 	}
// }

void	sort_and_pivot(t_stack *stack, int size, t_piv_cnt *pivot, int mod)
{
	int	i;
	int	term;
	int	*array;

	i = -1;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		exit(1);
	while (++i < size)
		array[i] = stack->stack[stack->top - i];
	bubble_sort(array, size);
	term = size / 3;
	if (size % 3 == 2)
		term++;
	if (mod == 0)
	{
		pivot->small = array[(size - 1) - (term * 2)];
		pivot->big = array[(size - 1) - term];
	}
	else if (mod == 1)
	{
		pivot->small = array[term];
		pivot->big = array[term * 2];
	}
	free(array);
}
