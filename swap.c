/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:06:22 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/12 20:17:58 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	t_list	*first;
	t_list	*second;

	if (!(a->head) || !(a->head->next))
		return ;
	first = a->head;
	second = a->head->next;
	a->head = second;
	first->next = second->next;
	second->next = first;
}
void	swap_b(t_stack *b)
{
	t_list	*first;
	t_list	*second;

	if (!(b->head) || !(b->head->next))
		return ;
	first = b->head;
	second = b->head->next;
	b->head = second;
	first->next = second->next;
	second->next = first;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a->head || !stack_b->head)
		return ;
	swap_a(stack_a);
	swap_b(stack_b);
}
