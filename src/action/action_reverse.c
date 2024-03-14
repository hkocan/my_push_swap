/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:34:00 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/13 06:34:01 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <unistd.h>

void	reverse_a_rra(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
	write(1, "rra\n", 4);
}

void	reverse_b_rrb(t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *b;
	*b = tmp->next;
	tmp->next = NULL;
	write(1, "rrb\n", 4);
}

void	reverse_ab_rrr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
	tmp = *b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *b;
	*b = tmp->next;
	tmp->next = NULL;
	write(1, "rrr\n", 4);
}
