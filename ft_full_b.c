/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:09:53 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/01 18:09:54 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_datanew(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!(data))
		return (0);
	data->next = 1;
	data->flag = 0;
	data->mid = 0;
	data->max = 0;
	data->newmid = 0;
	data->count = 0;
	return (data);
}

int	ft_mfindmax(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	tmp = stack;
	max = 0;
	if (tmp != 0)
		max = tmp->index;
	while (tmp != 0 && tmp->flag == 0)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

void	ft_canrotateboth(t_stack **a, t_stack **b, t_data *data)
{
	t_stack	*at;
	t_stack	*bt;

	at = *a;
	bt = *b;
	if (bt != 0 && bt->index < data->newmid)
	{
		ft_rotate(&at, 'r');
		ft_rotate(&bt, 'c');
	}
	else
		ft_rotate(&at, 'a');
	*a = at;
	*b = bt;
}

void	ft_fullb(t_stack **a, t_stack **b, t_data *data)
{
	int		i;
	t_stack	*at;
	t_stack	*bt;

	i = 1;
	at = *a;
	bt = *b;
	data->max = ft_findmax(at);
	data->mid = ft_stacksize(at) / 2 + 1;
	data->newmid = (data->mid - data->next) / 2 + data->next;
	while (i <= data->mid)
	{
		if (at->index <= data->mid)
		{
			ft_push(&at, &bt, 'b');
			i++;
		}
		else
			ft_canrotateboth(&at, &bt, data);
	}
	*a = at;
	*b = bt;
}

void	ft_secondfullb(t_stack **a, t_stack **b, t_data *data)
{
	int		i;
	t_stack	*at;
	t_stack	*bt;

	i = 1;
	at = *a;
	bt = *b;
	data->max = ft_mfindmax(at);
	data->mid = (data->max - data->next) / 2 + data->next;
	data->newmid = (data->mid - data->next) / 2 + data->next;
	while (at->flag == 0)
	{
		if (at->index <= data->mid)
		{
			ft_push(&at, &bt, 'b');
			i++;
		}
		else
			ft_canrotateboth(&at, &bt, data);
	}
	*a = at;
	*b = bt;
}
