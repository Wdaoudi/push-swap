/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallshort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:40:54 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/14 16:18:52 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*lst;

	lst = stack_a->head;
	if (lst == NULL || lst->next == NULL)
		return ;
	if (is_sorted(stack_a, stack_b) == false)
		swap_a(stack_a);
}

void	sort_3(t_stack *stack_a)
{
	t_list	*low;
	t_list	*higher;
	int		lowest_ind;
	int		higher_index;

	low = find_low(stack_a);
	higher = find_top(stack_a);
	higher_index = determine_index(higher, stack_a);
	if (higher_index == 0)
		rotate_a(stack_a);
	else if (higher_index == 1)
		rra(stack_a);
	lowest_ind = determine_index(low, stack_a);
	if (lowest_ind == 1)
		swap_a(stack_a);
}
