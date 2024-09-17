/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:43:44 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/17 18:53:23 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_end(int *tab, t_stack *a, t_stack *b)
{
	free(tab);
	free_stack(b);
	free_stack(a);
}

int	main(int ac, char **av)
{
	int			*tab;
	int			i;
	t_stacks	stack;

	stack.a.head = NULL;
	stack.b.head = NULL;
	tab = ft_valid(ac, av, &stack.a);
	if (!tab)
		return (0);
	i = 0;
	while (i < stack.a.size)
		add_to_queue(&stack.a, tab[i++]);
	if (is_sorted(&stack.a, &stack.b) == true)
		return (ft_free_end(tab, &stack.a, &stack.b), 0);
	if (stack.a.size == 2)
	{
		sort_2(&stack.a, &stack.b);
		return (ft_free_end(tab, &stack.a, &stack.b), 0);
	}
	else if (stack.a.size == 3)
		return (sort_3(&stack.a), ft_free_end(tab, &stack.a, &stack.b), 0);
	sort_array(tab, stack.a.size);
	sort_stack(&stack, stack.a.size, tab);
	ft_free_end(tab, &stack.a, &stack.b);
	return (0);
}
