/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:03:51 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/14 16:13:27 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert(t_stacks *stack)
{
	t_list	*change;
	t_list	*closest;

	change = find_low(stack->b);
	rotate_top(change, stack->b,stack);
	if (find_top(stack->a)->content < change->content)
		closest = find_low(stack->a);
	else
		closest = highest(change, stack->a);
	rotate_top(closest,stack->a, stack);
	push_a(stack->a, stack->b);
}
// verifier le rotate top
void	rotate_top(t_list *node, t_stack *stack,t_stacks *both) // suppression de la SIZE A VOIr l effet
{
	if (determine_index(node, stack) > (ft_lstsize(stack->head)/ 2))
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
		while(stack->head != node)
		{
			if(stack == both->b)
				rotate_b(both->b);
			else
				rotate_a(both->a);
		}
	}
}

t_list	*find_cheapest(t_stack *stack)
{
	t_list *current;
	t_list *cheapest;

	current = stack->head;
	cheapest = stack->head;
	while (current != NULL)
	{
		if (current->content < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}