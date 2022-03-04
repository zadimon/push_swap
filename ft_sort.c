/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:01:48 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/09/30 19:03:22 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checkfirstinb(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*at;
	t_stack	*bt;

	at = *a;
	bt = *b;
	bt->flag = -1;
	ft_push(&bt, &at, 'a');
	data->next++;
	if (bt->index < data->mid && bt->index != data->next)
	{
		ft_rotate(&bt, 'r');
		ft_rotate(&at, 'c');
	}
	else
		ft_rotate(&at, 'a');
	*a = at;
	*b = bt;
}

void	ft_checklastinb(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*at;
	t_stack	*bt;

	at = *a;
	bt = *b;
	ft_revrot(&bt, 'b');
	bt->flag = -1;
	ft_push(&bt, &at, 'a');
	data->next++;
	if (bt->index < data->mid && bt->index != data->next)
	{
		ft_rotate(&bt, 'r');
		ft_rotate(&at, 'c');
	}
	else
		ft_rotate(&at, 'a');
	*a = at;
	*b = bt;
}

void	ft_emptyb(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*at;
	t_stack	*bt;
	t_stack	*tmp;

	at = *a;
	bt = *b;
	tmp = bt;
	while (tmp->next != 0)
		tmp = tmp->next;
	if (bt->index >= data->mid)
	{
		bt->flag = data->flag;
		ft_push(&bt, &at, 'a');
		data->count--;
	}
	else if (bt->index == data->next)
		ft_checkfirstinb(&at, &bt, data);
	else if (tmp->index == data->next)
		ft_checklastinb(&at, &bt, data);
	else
		ft_rotate(&bt, 'b');
	*a = at;
	*b = bt;
}

void	ft_sortb(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*at;
	t_stack	*bt;
	int		i;

	at = *a;
	bt = *b;
	i = 1;
	while (bt != 0)
	{
		data->max = ft_findmax(bt);
		data->mid = (data->max - data->next) / 2 + data->next;
		data->flag++;
		data->count = data->max - data->mid + 1;
		while (data->count > 0)
			ft_emptyb(&at, &bt, data);
	}
	*a = at;
	*b = bt;
}

t_stack	*ft_sort(t_stack *stack)
{
	t_stack	*a;
	t_stack	*b;
	t_data	*data;

	b = 0;
	a = stack;
	data = ft_datanew();
	ft_fullb(&a, &b, data);
	ft_sortb(&a, &b, data);
	data->flag = a->flag;
	while (data->flag > 0)
	{
		ft_sortpt2(&a, &b, data);
		data->flag = a->flag;
	}
	ft_secondfullb(&a, &b, data);
	ft_reversea(&a, &b, data);
	ft_sortb(&a, &b, data);
	while (data->flag != -1)
	{
		ft_sortpt2(&a, &b, data);
		data->flag = a->flag;
	}
	free(data);
	return (a);
}
