/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:33:37 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/13 16:37:47 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdlib.h>

static void	sort_int_tmp(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	sort_int_pivot(t_stack **stack, int *pivot, int len)
{
	int		*mylist;
	t_stack	*tmp;
	int		i;

	i = -1;
	mylist = (int *)malloc(list_size(*stack) * sizeof(int));
	if (!mylist)
		return (0);
	tmp = *stack;
	while (++i < len && tmp != NULL)
	{
		mylist[i] = tmp->cont;
		tmp = tmp->next;
	}
	sort_int_tmp(mylist, i);
	i--;
	*pivot = mylist[(i / 2) + (i % 2)];
	free(mylist);
	return (0);
}

int	check_sort(t_stack *list)
{
	t_stack	*tmp;

	tmp = list;
	if (!list)
		return (0);
	while (tmp->next)
	{
		if (tmp->cont > tmp->next->cont)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_sort_stack_b(t_stack *list)
{
	t_stack	*tmp;

	tmp = list;
	while (tmp->next)
	{
		if (tmp->cont < tmp->next->cont)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	sort(t_box **box)
{
	if (check_sort((*box)->a))
	{
		if ((*box)->size == 2)
			swap_a_sa(&((*box)->a));
		else if ((*box)->size == 3)
			sort_tree_arg(&((*box)->a));
		else
			quicksort_a(box, (*box)->size, 0);
	}
}
