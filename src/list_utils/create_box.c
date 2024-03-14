/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:33:48 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/13 06:33:49 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdlib.h>

int	create_box(t_box **box, char **str)
{
	t_stack	*new;
	int		i;

	i = -1;
	*box = (t_box *)malloc(sizeof(t_box));
	if (!*box)
		return (0);
	(*box)->a = NULL;
	(*box)->b = NULL;
	(*box)->size = 0;
	while (str[++i])
	{
		new = new_list(ft_atoi2(str[i]));
		add_back_list(&(*box)->a, new);
		(*box)->size++;
	}
	return (0);
}
