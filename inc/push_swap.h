/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:36:09 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/13 06:36:09 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_stack
{
	int				cont;
	struct s_stack	*next;
}				t_stack;

typedef struct s_box
{
	int		size;
	t_stack	*a;
	t_stack	*b;
}				t_box;

char	**argument_check(char **str, int ac);
void	str_free_error(char **tmp, int ac, int i);
void	free_box(t_box *box);
void	ft_error(void);
void	sort(t_box **box);
long	ft_atoi2(const char *str);
int		check_sort(t_stack *list);
int		check_sort_stack_b(t_stack *list);
int		quicksort_a(t_box **box, int len, int count);
int		quicksort_b(t_box **box, int len, int count);
int		sort_int_pivot(t_stack **stack, int *pivot, int len);
void	sort_tree_arg(t_stack **list);
int		create_box(t_box **box, char **str);
void	add_back_list(t_stack **stack, t_stack *new);
t_stack	*new_list(int cont);
t_stack	*list_last(t_stack *begin);
int		list_size(t_stack *lst);
void	swap_a_sa(t_stack **a);
void	swap_b_sb(t_stack **b);
void	swap_ab_ss(t_stack **a, t_stack **b);
void	push_a_pa(t_stack **a, t_stack **b);
void	push_b_pb(t_stack **a, t_stack **b);
void	rotate_a_ra(t_stack **a);
void	rotate_b_rb(t_stack **b);
void	rotate_ab_rr(t_stack **a, t_stack **b);
void	reverse_a_rra(t_stack **a);
void	reverse_b_rrb(t_stack **b);
void	reverse_ab_rrr(t_stack **a, t_stack **b);
#endif