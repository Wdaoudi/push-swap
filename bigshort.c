/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigshort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:41:04 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/16 18:41:07 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stacks *both, int size, int *tab)
{
	higher_half_to_b(both, size, tab);
	lowest_half_to_b(both, size, tab);
	sort_3(both->a);
	while (both->b->head != NULL)
	{
		cost_all_list(both->a, both->b);
		insert(both);
	}
	sort(both);
}

void	higher_half_to_b(t_stacks *both, int size, int *tab)
{
	t_stack	*stack;

	stack = both->a;
	while (find_top(stack)->content > tab[size * 1 / 2])
	{
		if (stack->head->content > tab[size / 4 * 3])
		{
			push_b(both->a, both->b);
			if (stack->head->content <= size / 2)
				rr(both->a, both->b);
			else
				rotate_b(both->b);
		}
		else if (stack->head->content > tab[size * 1 / 2])
		{
			push_b(both->a, both->b);
		}
		else
		{
			rotate_a(both->a);
		}
	}
}

void	lowest_half_to_b(t_stacks *both, int size, int *tab)
{
	t_stack	*stack;
	int		number_input;

	stack = both->a;
	number_input = size;
	while (find_top(stack)->content > tab[size / 4]
		&& ft_lstsize(stack->head) > 3)
	{
		if (stack->head->content > tab[number_input / 4])
			push_b(both->a, both->b);
		else
		{
			push_b(both->a, both->b);
			rotate_b(both->b);
		}
		while (ft_lstsize(stack->head) > 3)
			push_b(both->a, both->b);
	}
}

void	sort(t_stacks *both)
{
	t_list *lower;
	lower = find_low(both->a);
	rotate_top(lower, both->a, both);
}