/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:22:09 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/01 18:42:50 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checksorted(t_stack *a)
{
	t_stack	*tmp;
	int		sorted;

	tmp = a;
	sorted = 1;
	while (tmp != 0)
	{
		if (tmp->next != 0 && tmp->num > tmp->next->num)
			sorted = 0;
		tmp = tmp->next;
	}
	return (sorted);
}

void	ft_printres(t_stack *b, int sorted)
{
	if (b == 0 && sorted == 1)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int argc, char **argv)
{
	char	*s;
	t_stack	*a;
	t_stack	*b;

	if (argc >= 2)
	{
		b = 0;
		if (argc == 2)
			a = ft_oneargforchecker(argv[1]);
		if (argc > 2)
			a = ft_parseargforchecker(argc, argv);
		s = get_next_line(0);
		while (s != 0)
		{
			ft_parsecom(s, &a, &b);
			free(s);
			s = get_next_line(0);
		}
		ft_printres(b, ft_checksorted(a));
		ft_stackclear(b);
		ft_stackclear(a);
	}
	return (0);
}
