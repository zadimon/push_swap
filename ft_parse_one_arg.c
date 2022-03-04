/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_one_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:02:52 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/09/30 23:21:31 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(int c)
{
	unsigned char	sym;

	sym = (unsigned char)c;
	if (sym == ' ' || sym == '\t' || sym == '\n'
		|| sym == '\v' || sym == '\f' || sym == '\r')
		return (1);
	else
		return (0);
}

int	ft_isstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && !(ft_isdigit(s[i])) && s[i] != '-' && s[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atol(char *str)
{
	long int	num;
	size_t		i;
	int			minus;

	num = 0;
	i = 0;
	minus = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!(ft_isdigit(str[i])))
			ft_exit();
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if ((num * minus) > 2147483647 || (num * minus) < -2147483648
		|| ft_strlen(str) > 10)
		ft_exit();
	return (((int)num) * minus);
}

t_stack	*ft_fromonearg(int len, char **str)
{
	int		i;
	t_stack	*stack;
	t_stack	*tmp;
	int		sorted;

	sorted = 1;
	stack = ft_stacknew(ft_atol(str[0]));
	i = 1;
	while (i < len)
	{
		tmp = ft_stacknew(ft_atol(str[i]));
		stack->next = tmp;
		tmp->prev = stack;
		stack = tmp;
		i++;
	}
	while (stack->prev != 0)
		stack = stack->prev;
	ft_createindex(&stack, &sorted);
	if (sorted)
		exit(0);
	return (stack);
}
