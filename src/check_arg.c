/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:33:30 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/14 15:11:14 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft/libft.h"
#include "../inc/push_swap.h"

long	ft_atoi2(const char *str)
{
	int		sign;
	long	result;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i])
		result = result * 10 + (str[i++] - '0');
	return ((sign * result));
}

static int	number_digit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	i = 0;
	if ((str[0] == '-' || str[0] == '+') && !str[1])
		return (0);
	if (str[0] == '-' || str[0] == '+')
		str++;
	while (*str == '0')
		str++;
	while (str[i])
		i++;
	if (i > 11)
		return (0);
	return (1);
}

static int	repeat_num(int num, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi2(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

char	**argument_check(char **av, int ac)
{
	char	**tmp;
	int		i;
	long	num;

	tmp = NULL;
	i = -1;
	if (ac < 2)
		exit(0);
	else if (ac == 2)
		tmp = ft_split(av[1], ' ');
	else if (ac > 2)
		tmp = av + 1;
	if (tmp[0] == NULL)
		str_free_error(tmp, ac, 1);
	while (tmp[++i])
	{
		if (*tmp[i] == '\0' || number_digit(tmp[i]) == 0)
			str_free_error(tmp, ac, 1);
		num = ft_atoi2(tmp[i]);
		if (num > 2147483647 || num < -2147483648)
			str_free_error(tmp, ac, 1);
		if (repeat_num(num, tmp, i))
			str_free_error(tmp, ac, 1);
	}
	return (tmp);
}
