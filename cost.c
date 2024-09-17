/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:10:11 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/17 17:03:03 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_all_list(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*lst;

	lst = stack_b->head;
	while (lst != NULL)
	{
		lst->cost = cost(lst, stack_a, stack_b);
		lst = lst->next;
	}
}

int	cost(t_list *lst, t_stack *stack_a, t_stack *stack_b)
{
	int	cost;

	cost = cost_top(lst, stack_b);
	get_target(stack_a, lst);
	cost += cost_top(lst->target, stack_a);
	++cost;
	return (cost);
}

int	cost_top(t_list *lst, t_stack *stack)
{
	t_list	*current;
	int		index;
	int		cost;

	cost = 0;
	current = lst;
	index = determine_index(lst, stack);
	if (index > ft_lstsize(stack->head) / 2)
	{
		while (current->next)
		{
			current = current->next;
			cost++;
		}
		cost++;
	}
	else
		cost = index;
	return (cost);
}

t_list	*highest(t_list *lst, t_stack *stack)
{
	int		temp;
	t_list	*current;
	t_list	*closest;

	current = stack->head;
	closest = stack->head;
	temp = INT_MAX;
	while (current != NULL)
	{
		if (current->content < temp && lst->content < current->content)
		{
			closest = current;
			temp = current->content;
		}
		current = current->next;
	}
	return (closest);
}
