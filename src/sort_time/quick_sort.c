/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:33:40 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/13 07:35:19 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	push(t_box **box, int len, int operation)
{
	if (operation == 0)
		push_b_pb(&(*box)->a, &(*box)->b);
	else
		push_a_pa(&(*box)->a, &(*box)->b);
	len--;
	return (len);
}

void	sort_small_b(t_box **box, int len)
{
	if (len == 1)
		push_a_pa(&(*box)->a, &(*box)->b);
	else if (len == 2)
	{
		if ((*box)->b->cont < (*box)->b->next->cont)
			swap_b_sb(&(*box)->b);
		while (len--)
			push_a_pa(&(*box)->a, &(*box)->b);
	}
	else if (len == 3)
	{
		while (len || !((*box)->a->cont < (*box)->a->next->cont
				&& (*box)->a->next->cont < (*box)->a->next->next->cont))
		{
			if (len == 1 && (*box)->a->cont > (*box)->a->next->cont)
				swap_a_sa(&(*box)->a);
			else if (len == 1 || (len >= 2
					&& (*box)->b->cont > (*box)->b->next->cont)
				|| (len == 3
					&& (*box)->b->cont > (*box)->b->next->next->cont))
				len = push(box, len, 1);
			else
				swap_b_sb(&(*box)->b);
		}
	}
}

void	quicksort_3(t_box **box, int len)
{
	if (len == 3 && list_size((*box)->a) == 3)
		sort_tree_arg(&(*box)->a);
	else if (len == 2)
	{
		if ((*box)->a->cont > (*box)->a->next->cont)
			swap_a_sa(&(*box)->a);
	}
	else if (len == 3)
	{
		while (len != 3 || !((*box)->a->cont < (*box)->a->next->cont
				&& (*box)->a->next->cont < (*box)->a->next->next->cont))
		{
			if (len == 3 && (*box)->a->cont > (*box)->a->next->cont
				&& (*box)->a->next->next->cont)
				swap_a_sa(&(*box)->a);
			else if (len == 3 && !((*box)->a->next->next->cont > (*box)->a->cont
					&& (*box)->a->next->next->cont > (*box)->a->next->cont))
				len = push(box, len, 0);
			else if ((*box)->a->cont > (*box)->a->next->cont)
				swap_a_sa(&(*box)->a);
			else if (len++)
				push_a_pa(&(*box)->a, &(*box)->b);
		}
	}
}

int	quicksort_a(t_box **box, int len, int count)
{
	int	pivot;
	int	items;

	if (check_sort((*box)->a) == 0)
		return (1);
	items = len;
	if (len <= 3)
	{
		quicksort_3(box, len);
		return (1);
	}
	sort_int_pivot(&(*box)->a, &pivot, len);
	while (len != items / 2 + items % 2)
	{
		if ((*box)->a->cont < pivot && (len--))
			push_b_pb(&(*box)->a, &(*box)->b);
		else if (++count)
			rotate_a_ra(&(*box)->a);
	}
	while (items / 2 + items % 2 != list_size((*box)->a) && count--)
		reverse_a_rra(&(*box)->a);
	return (quicksort_a(box, items / 2 + items % 2, 0) && quicksort_b(box, items
			/ 2, 0));
	return (1);
}

int	quicksort_b(t_box **box, int len, int count)
{
	int	pivot;
	int	items;

	if (!count && check_sort_stack_b((*box)->b) == 0)
		while (len--)
			push_a_pa(&(*box)->a, &(*box)->b);
	if (len <= 3)
	{
		sort_small_b(box, len);
		return (1);
	}
	items = len;
	sort_int_pivot(&(*box)->b, &pivot, len);
	while (len != items / 2)
	{
		if ((*box)->b->cont >= pivot && len--)
			push_a_pa(&(*box)->a, &(*box)->b);
		else if (++count)
			rotate_b_rb(&(*box)->b);
	}
	while (items / 2 != list_size((*box)->b) && count--)
		reverse_b_rrb(&(*box)->b);
	return (quicksort_a(box, items / 2 + items % 2, 0) && quicksort_b(box, items
			/ 2, 0));
}
