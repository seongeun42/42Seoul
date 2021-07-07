/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:02:10 by seongele          #+#    #+#             */
/*   Updated: 2021/06/22 21:02:12 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		*stack;
	int		top;
}				t_stack;

typedef struct s_piv_cnt
{
	int		big;
	int		small;
	int		ra;
	int		rb;
	int		pa;
	int		pb;
}				t_piv_cnt;

void			error(void);
int				ft_strcmp(char *s1, char *s2);
char			**ft_split(char const *s);
int				check_dup(int *stack, int size);
int				malloc_tri_free(char ***str);
int				count(char ***arg);
int				*make_stack(char ***arg, int size);
char			***parsing_arg(char **argv, int argc);
long long		ft_atoi(const char *str);

int				s(t_stack *stack);
int				p(t_stack *pop, t_stack *push);
int				r_rr(int i, t_stack *stack);
void			operation(char *str, t_stack *a, t_stack *b);
void			operation_double(char *str, t_stack *a, t_stack *b);

int				is_sort(t_stack *stack, int size, int mod);
void			sort_arg3(t_stack *a, t_stack *b);
void			sort_arg4(t_stack *a, t_stack *b);
void			sort_arg5(t_stack *a, t_stack *b);
void			bubble_sort(int *array, int size);
int				sort_b(t_stack *a, t_stack *b, int size);
int				sort_a(t_stack *a, t_stack *b, int size);
void			sort_and_pivot(t_stack *s, int size, t_piv_cnt *piv, int mod);
int				a_to_b(t_stack *a, t_stack *b, int size);
void			divide_a(t_stack *a, t_stack *b, int size, t_piv_cnt *piv);
int				b_to_a(t_stack *a, t_stack *b, int size);
void			divide_b(t_stack *a, t_stack *b, int size, t_piv_cnt *piv);

int				init_stack(t_stack *a, t_stack *b, int size, char ***arg);
void			push_swap(t_stack *a, t_stack *b, int size);

#endif
