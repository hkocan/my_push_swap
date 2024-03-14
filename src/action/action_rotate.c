/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:33:57 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/13 06:33:58 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <unistd.h>

void	rotate_a_ra(t_stack **a)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	list_last(tmp)->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rotate_b_rb(t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	list_last(tmp)->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	rotate_ab_rr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	list_last(tmp)->next = tmp;
	tmp->next = NULL;
	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	list_last(tmp)->next = tmp;
	tmp->next = NULL;
	write(1, "rr\n", 3);
}
