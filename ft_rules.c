/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:03:39 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/01 17:31:42 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *first, t_stack *second, t_stack **stack, char c)
{
	t_stack	*prev;
	t_stack	*next;

	if (ft_stacksize(*stack) < 2)
		return ;
	next = second->next;
	second->next = first;
	first->next = next;
	prev = first->prev;
	first->prev = second;
	second->prev = prev;
	if (first->next != 0)
	{
		next = first->next;
		next->prev = first;
	}
	*stack = second;
	if (c == 'a')
		ft_putendl_fd("sa", 1);
	else if (c == 'b')
		ft_putendl_fd("sb", 1);
	else if (c == 's')
		ft_putendl_fd("ss", 1);
}

void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*tail;
	t_stack	*head;
	t_stack	*tmp;

	if (ft_stacksize(*stack) < 2)
		return ;
	head = *stack;
	tail = *stack;
	while (tail->next != 0)
		tail = tail->next;
	tmp = head->next;
	tmp->prev = 0;
	tail->next = head;
	head->next = 0;
	head->prev = tail;
	*stack = tmp;
	if (c == 'a')
		ft_putendl_fd("ra", 1);
	else if (c == 'b')
		ft_putendl_fd("rb", 1);
	else if (c == 'r')
		ft_putendl_fd("rr", 1);
}

void	ft_revrot(t_stack **stack, char c)
{
	t_stack	*tail;
	t_stack	*head;
	t_stack	*tmp;

	if (ft_stacksize(*stack) < 2)
		return ;
	head = *stack;
	tmp = *stack;
	while (tmp->next->next != 0)
		tmp = tmp->next;
	tail = tmp->next;
	tmp->next = 0;
	tail->next = head;
	tail->prev = 0;
	tmp = tail->next;
	tmp->prev = tail;
	*stack = tail;
	if (c == 'a')
		ft_putendl_fd("rra", 1);
	else if (c == 'b')
		ft_putendl_fd("rrb", 1);
	else if (c == 'r')
		ft_putendl_fd("rrr", 1);
}

t_stack	*ft_push2(t_stack **a, t_stack **b)
{
	t_stack	*at;
	t_stack	*bt;

	at = *a;
	bt = *b;
	if (bt == 0)
	{
		bt = at;
		bt->next = 0;
		*b = bt;
	}
	else
	{
		bt->prev = at;
		at->next = bt;
		at->prev = 0;
		*b = bt->prev;
	}
	return (*b);
}

void	ft_push(t_stack **a, t_stack **b, char c)
{
	t_stack	*at;
	t_stack	*bt;

	if (ft_stacksize(*a) < 1)
		return ;
	at = *a;
	bt = *b;
	if ((*a)->next != 0)
	{
		*a = at->next;
		(*a)->prev = 0;
	}
	else
		*a = 0;
	*b = ft_push2(&at, &bt);
	if (c == 'a')
		ft_putendl_fd("pa", 1);
	else if (c == 'b')
		ft_putendl_fd("pb", 1);
}
