/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:39:25 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/13 06:39:26 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_tree_arg(t_stack **list)
{
	if ((*list)->cont > (*list)->next->cont
		&& (*list)->next->cont > (*list)->next->next->cont)
	{
		rotate_a_ra(list);
		swap_a_sa(list);
	}
	else if ((*list)->cont > (*list)->next->next->cont
		&& (*list)->next->next->cont > (*list)->next->cont)
		rotate_a_ra(list);
	else if ((*list)->next->next->cont > (*list)->cont
		&& (*list)->cont > (*list)->next->cont)
		swap_a_sa(list);
	else if ((*list)->next->cont > (*list)->cont
		&& (*list)->cont > (*list)->next->next->cont)
		reverse_a_rra(list);
	else if ((*list)->next->cont > (*list)->next->next->cont
		&& (*list)->next->next->cont > (*list)->cont)
	{
		reverse_a_rra(list);
		swap_a_sa(list);
	}
}
