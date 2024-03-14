/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:57:37 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/13 06:57:37 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	free_box(t_box *box)
{
	t_stack	*tmp;

	while (box->a)
	{
		tmp = box->a;
		box->a = box->a->next;
		free(tmp);
	}
	while (box->b)
	{
		tmp = box->b;
		box->b = box->b->next;
		free(tmp);
	}
	free(box);
}

void	str_free_error(char **tmp, int ac, int i)
{
	int	j;

	if (ac == 2)
	{
		j = 0;
		while (tmp[j])
			free(tmp[j++]);
		free(tmp);
	}
	if (i)
		ft_error();
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
