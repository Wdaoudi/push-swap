/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:47:00 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/26 18:53:44 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_lenght(t_stack *stack)
{
	t_list	*node;
	int		i;

	i = 1;
	node = stack->head->next;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

int	ft_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == 32 || str[i] <= 13))
			return (1);
		i++;
	}
	return (0);
}

void	print_targets(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*current;

	current = stack_b->head;
	while (current)
	{
		get_target(stack_a, current);
		ft_printf("Element %d in B, target in A: %d\n", current->content,
			current->target->content);
		current = current->next;
	}
}

void	print_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*current;
	int		c;

	current = stack_b->head;
	while (current)
	{
		c = cost(current, stack_a, stack_b);
		ft_printf("Element %d in B, cost: %d\n", current->content, c);
		current = current->next;
	}
}

void	ft_free_end(long *tab, t_stack *a, t_stack *b)
{
	if (tab)
		free(tab);
	if (b)
		free_stack(b);
	if (a)
		free_stack(a);
}

// void	print_list2(t_stacks *stack)
// {
// 	t_list	*current;

// 	current = stack->b.head;
// 	if (current == NULL)
// 	{
// 		ft_printf("La liste est vide.\n");
// 		return ;
// 	}
// 	while (current != NULL)
// 	{
// 		ft_printf("Content: %d \n", current->target->content);
// 		current = current->next;
// 	}
// }
