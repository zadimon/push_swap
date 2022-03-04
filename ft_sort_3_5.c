/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:04:03 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/09/30 19:04:04 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_revorrot(t_stack *stack, int index, char c)
{
	t_stack	*tmp;

	tmp = stack;
	if (ft_stackfind(tmp, index) <= (ft_stacksize(tmp) / 2 + 1))
	{
		while (tmp != 0 && tmp->index != index)
			ft_rotate(&tmp, c);
	}
	else
	{
		while (tmp != 0 && tmp->index != index)
			ft_revrot(&tmp, c);
	}
	return (tmp);
}

t_stack	*ft_sort3(t_stack *stack, char c)
{
	t_stack	*tmp;

	tmp = stack;
	if (ft_stacksize(tmp) == 2)
	{
		if (tmp->index > tmp->next->index)
			ft_swap(tmp, tmp->next, &tmp, c);
	}
	if (ft_stacksize(tmp) == 3)
	{
		if (ft_findmax(tmp) == tmp->index)
			ft_rotate(&tmp, c);
		if (ft_findmax(tmp) == tmp->next->index)
			ft_revrot(&tmp, c);
		if (tmp->index > tmp->next->index)
			ft_swap(tmp, tmp->next, &tmp, c);
	}
	return (tmp);
}

t_stack	*ft_sort5(t_stack *stack)
{
	t_stack	*a;
	t_stack	*b;

	a = stack;
	b = 0;
	a = ft_revorrot(a, 1, 'a');
	ft_push(&a, &b, 'b');
	a = ft_revorrot(a, 2, 'a');
	ft_push(&a, &b, 'b');
	a = ft_sort3(a, 'a');
	ft_push(&b, &a, 'a');
	ft_push(&b, &a, 'a');
	return (a);
}
