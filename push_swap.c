/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:01:58 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/09/30 22:35:08 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc >= 2)
	{
		if (argc == 2)
			stack = ft_pushswaponearg(argv[1]);
		if (argc > 2)
			stack = ft_parsearg(argc, argv);
		stack = ft_pushswap(stack);
		ft_stackclear(stack);
	}
	return (0);
}
