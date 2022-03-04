/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:04:08 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/09/30 19:04:09 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

t_stack	*ft_createlist(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	t_stack	*tmp;

	stack = ft_stacknew(ft_atol(argv[1]));
	i = 2;
	while (i < argc)
	{
		tmp = ft_stacknew(ft_atol(argv[i]));
		stack->next = tmp;
		tmp->prev = stack;
		stack = tmp;
		i++;
	}
	while (stack->prev != 0)
		stack = stack->prev;
	return (stack);
}

void	ft_createindex(t_stack **stack, int *sorted)
{
	int		tmp;
	t_stack	*s1;
	t_stack	*s2;

	s1 = *stack;
	while (s1 != 0)
	{
		s2 = *stack;
		tmp = 1;
		if (s1->next != 0 && s1->num > s1->next->num)
			*sorted = 0;
		while (s2 != 0)
		{
			if (s1->num == s2->num && s1 != s2)
				ft_exit();
			if (s2->num < s1->num)
				tmp++;
			s2 = s2->next;
		}
		s1->index = tmp;
		s1 = s1->next;
	}
}

t_stack	*ft_parsearg(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	int		sorted;

	i = 1;
	sorted = 1;
	stack = ft_createlist(argc, argv);
	ft_createindex(&stack, &sorted);
	if (sorted)
		exit(0);
	return (stack);
}
