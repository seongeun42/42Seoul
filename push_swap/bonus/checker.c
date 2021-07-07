/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <eongele@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:01:29 by seongele          #+#    #+#             */
/*   Updated: 2021/06/22 21:01:35 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	checker(t_stack *a, t_stack *b, int size)
{
	char	*line;
	int		gnl;

	gnl = get_next_line(0, &line);
	if (*line)
	{
		while (gnl > 0)
		{
			if (!ft_strcmp(line, "Error"))
				error();
			operation(line, a, b);
			free(line);
			gnl = get_next_line(0, &line);
		}
		if (gnl < 0)
			error();
	}
	free(line);
	return (is_sort(a, size, 0));
}

int	main(int argc, char *argv[])
{
	char	***arg;
	int		size;
	int		result;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		exit(1);
	arg = parsing_arg(argv, argc);
	if (!arg)
		error();
	size = count(arg);
	init_stack(&a, &b, size, arg);
	result = checker(&a, &b, size);
	if (result == 0)
		write(1, "KO\n", 3);
	else if (result == 1 && b.top == -1)
		write(1, "OK\n", 3);
	else if (result == 1 && b.top != -1)
		write(1, "KO\n", 3);
	free(a.stack);
	a.stack = 0;
	free(b.stack);
	b.stack = 0;
	return (0);
}
