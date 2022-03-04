/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_pt2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 17:34:19 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/01 17:36:47 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_fromoneargforchecker(int len, char **str)
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
	return (stack);
}

t_stack	*ft_oneargforchecker(char *s)
{
	char	**str;
	int		i;
	t_stack	*stack;
	int		k;

	if (!(ft_isstr(s)))
		ft_exit();
	str = ft_split(s, ' ');
	i = 0;
	while (str[i] != 0)
		i++;
	if (i < 2)
		exit(0);
	stack = ft_fromoneargforchecker(i, str);
	k = 0;
	while (k <= i)
	{
		free(str[k]);
		k++;
	}
	free(str);
	return (stack);
}

t_stack	*ft_parseargforchecker(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	int		sorted;

	i = 1;
	sorted = 1;
	stack = ft_createlist(argc, argv);
	ft_createindex(&stack, &sorted);
	return (stack);
}
