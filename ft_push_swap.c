/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:34:58 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/01 18:09:29 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_pushswaponearg(char *s)
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
	stack = ft_fromonearg(i, str);
	k = 0;
	while (k <= i)
	{
		free(str[k]);
		k++;
	}
	free(str);
	return (stack);
}

t_stack	*ft_pushswap(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (ft_stacksize(tmp) <= 3)
		tmp = ft_sort3(tmp, 'a');
	if (ft_stacksize(tmp) <= 5 && ft_stacksize(tmp) > 3)
		tmp = ft_sort5(tmp);
	if (ft_stacksize(tmp) > 5)
		tmp = ft_sort(tmp);
	return (tmp);
}
