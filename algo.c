/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:03:51 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/17 16:44:08 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_cheaper(t_stack *stack)
{
	t_list	*current;
	t_list	*lowest;

	lowest = stack->head;
	current = stack->head->next;
	while (current)
	{
		if (current->cost < lowest->cost)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

void	insert(t_stacks *stack)
{
	t_list	*change;
	t_list	*closest;

	change = find_cheaper(stack->b);
	closest = change->target;
	rotate_top(change, stack->b, stack);
	rotate_top(closest, stack->a, stack);
	push_a(stack->a, stack->b);
}

void	rotate_top(t_list *node, t_stack *stack, t_stacks *both)
{
	if (determine_index(node, stack) > (ft_lstsize(stack->head) / 2))
	{
		while (stack->head != node)
		{
			if (stack == both->b)
				rrb(both->b);
			else
				rra(both->a);
		}
	}
	else
	{
		while (stack->head != node)
		{
			if (stack == both->b)
				rotate_b(both->b);
			else
				rotate_a(both->a);
		}
	}
}

t_list	*find_cheapest(t_stack *stack)
{
	t_list		*current;
	t_list		*cheapest;

	current = stack->head;
	cheapest = stack->head;
	while (current != NULL)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
