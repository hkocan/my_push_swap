/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/03/13 06:33:20 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/13 06:33:20 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	char	**arg;
	t_box	*box;

	box = NULL;
	arg = argument_check(av, ac);
	create_box(&box, arg);
	sort(&box);
	free_box(box);
	str_free_error(arg, ac, 0);
	return (0);
}
