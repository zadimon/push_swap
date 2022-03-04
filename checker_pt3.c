/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_pt3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:07:50 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/01 18:07:55 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_canswapb(t_stack **b)
{
	t_stack	*bt;

	bt = *b;
	if (bt != 0 && bt->next != 0)
		ft_swap(bt, bt->next, &bt, 'c');
	*b = bt;
}

void	ft_parsereverserotate(t_stack **a, t_stack **b)
{
	t_stack	*at;
	t_stack	*bt;

	at = *a;
	bt = *b;
	ft_revrot(&at, 'c');
	ft_revrot(&bt, 'c');
	*a = at;
	*b = bt;
}

void	ft_parserotate(char *s, t_stack **a, t_stack **b)
{
	t_stack	*at;
	t_stack	*bt;

	at = *a;
	bt = *b;
	if (!(ft_strncmp("ra\n", s, 3)))
		ft_rotate(&at, 'c');
	else if (!(ft_strncmp("rb\n", s, 3)))
		ft_rotate(&bt, 'c');
	else if (!(ft_strncmp("rr\n", s, 3)))
	{
		ft_rotate(&at, 'c');
		ft_rotate(&bt, 'c');
	}
	else if (!(ft_strncmp("rra\n", s, 4)))
		ft_revrot(&at, 'c');
	else if (!(ft_strncmp("rrb\n", s, 4)))
		ft_revrot(&bt, 'c');
	else if (!(ft_strncmp("rrr\n", s, 4)))
		ft_parsereverserotate(&at, &bt);
	else
		ft_exit();
	*a = at;
	*b = bt;
}

void	ft_parsecom(char *s, t_stack **a, t_stack **b)
{
	t_stack	*at;
	t_stack	*bt;

	at = *a;
	bt = *b;
	if (!(ft_strncmp("sa\n", s, 3)))
		ft_swap(at, at->next, &at, 'c');
	else if (!(ft_strncmp("sb\n", s, 3)))
		ft_canswapb(&bt);
	else if (!(ft_strncmp("ss\n", s, 3)))
	{
		ft_swap(at, at->next, &at, 'c');
		ft_canswapb(&bt);
	}
	else if (!(ft_strncmp("r", s, 1)))
		ft_parserotate(s, &at, &bt);
	else if (!(ft_strncmp("pb\n", s, 3)))
		ft_push(&at, &bt, 'c');
	else if (!(ft_strncmp("pa\n", s, 3)))
		ft_push(&bt, &at, 'c');
	else
		ft_exit();
	*a = at;
	*b = bt;
}
