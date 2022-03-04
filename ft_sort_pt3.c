/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_pt3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:01:55 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/09/30 19:01:56 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sortpt2(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*at;
	t_stack	*bt;

	at = *a;
	bt = *b;
	ft_fullbandsort(&at, &bt, data);
	ft_sortb(&at, &bt, data);
	*a = at;
	*b = bt;
}

void	ft_reversea(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*at;
	t_stack	*bt;
	t_stack	*tmp;

	at = *a;
	bt = *b;
	tmp = at;
	while (tmp != 0 && tmp->flag == -1)
		tmp = tmp->next;
	while (tmp != 0 && at->index != tmp->index)
	{
		if (bt->index != data->next)
		{
			ft_revrot(&at, 'r');
			ft_revrot(&bt, 'c');
		}
		else
			ft_revrot(&at, 'a');
	}
	*a = at;
	*b = bt;
}
