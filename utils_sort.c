/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:44:41 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/17 16:25:39 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_low(t_stack *stack)
{
	t_list	*current;
	t_list	*lowest;

	lowest = stack->head;
	current = stack->head->next;
	while (current)
	{
		if (current->content < lowest->content)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

t_list	*find_top(t_stack *stack)
{
	t_list	*current;
	t_list	*top;

	top = stack->head;
	current = stack->head->next;
	while (current)
	{
		if (current->content > top->content)
			top = current;
		current = current->next;
	}
	return (top);
}

int	determine_index(t_list *node, t_stack *stack)
{
	t_list	*current;
	int		i;

	current = stack->head;
	i = 0;
	while (current)
	{
		if (current == node)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

bool	is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*node;

	if (!stack_a || !stack_a->head)
		return (false);
	if (stack_b && stack_b->head)
		return (false);
	node = stack_a->head;
	if (node->next == NULL && stack_b->head == NULL)
		return (true);
	if (node->content > node->next->content)
		return (false);
	while (node->next)
	{
		if (node->content > node->next->content)
			return (false);
		node = node->next;
	}
	return (true);
}

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

// t_stack	*input_count(t_stack *lst)
// {
// 	int i = 0;
// 	while (lst->head->next)
// 	{
// 		lst->head->next;
// 		i++;
// 	}
// 	lst->size = i;
// 	return (lst);
// }

// int main()
// {
// 	int *tab;
// 	tab[] = {1,2,3,4,5};
// 	t_stack *stack_a;
// 	init_stack()
//}