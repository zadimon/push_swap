/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:03:52 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/09/30 19:03:53 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int num)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!(stack))
		return (0);
	stack->num = num;
	stack->index = -1;
	stack->flag = 0;
	stack->prev = 0;
	stack->next = 0;
	return (stack);
}

void	ft_stackclear(t_stack *stack)
{
	t_stack	*tmp;

	while (stack != 0)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

int	ft_stacksize(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp != 0)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_stackfind(t_stack *stack, int index)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	tmp = stack;
	while (tmp != 0 && tmp->index != index)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_findmax(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	tmp = stack;
	max = 0;
	if (tmp != 0)
		max = tmp->index;
	while (tmp != 0)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}
