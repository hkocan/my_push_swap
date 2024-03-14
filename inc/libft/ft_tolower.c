/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:16:44 by hkocan            #+#    #+#             */
/*   Updated: 2023/10/24 14:04:34 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int i)
{
	while ('A' <= i && 'Z' >= i)
		return (i + 32);
	return (i);
}