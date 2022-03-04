/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_pt2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:02:05 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/09/30 19:02:06 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checkfirstina(t_stack **a, t_data *data)
{
	t_stack	*at;

	at = *a;
	at->flag = -1;
	data->next++;
	ft_rotate(&at, 'a');
	*a = at;
}

void	ft_checksecondina(t_stack **a, t_data *data)
{
	t_stack	*at;

	at = *a;
	ft_swap(at, at->next, &at, 'a');
	at->flag = -1;
	data->next++;
	ft_rotate(&at, 'a');
	*a = at;
}

void	ft_checkfirstinbfora(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*at;
	t_stack	*bt;

	at = *a;
	bt = *b;
	bt->flag = -1;
	ft_push(&bt, &at, 'a');
	data->next++;
	ft_rotate(&at, 'a');
	*a = at;
	*b = bt;
}

void	ft_checksecondinbfora(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*at;
	t_stack	*bt;

	at = *a;
	bt = *b;
	ft_swap(bt, bt->next, &bt, 'b');
	bt->flag = -1;
	ft_push(&bt, &at, 'a');
	data->next++;
	ft_rotate(&at, 'a');
	*a = at;
	*b = bt;
}

void	ft_fullbandsort(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*at;
	t_stack	*bt;
	int		flag;

	at = *a;
	bt = *b;
	flag = at->flag;
	while (1)
	{
		if (at->index == data->next)
			ft_checkfirstina(&at, data);
		else if (at->next->index == data->next)
			ft_checksecondina(&at, data);
		else if (bt != 0 && bt->index == data->next)
			ft_checkfirstinbfora(&at, &bt, data);
		else if (bt != 0 && bt->next != 0 && bt->next->index == data->next)
			ft_checksecondinbfora(&at, &bt, data);
		else if (at->flag == flag)
			ft_push(&at, &bt, 'b');
		else
			break ;
	}
	*a = at;
	*b = bt;
}
