/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:54:46 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/17 16:33:09 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_list	*first;
	t_list	*last;

	if (!(stack->head) || !(stack->head->next))
		return ;
	first = stack->head;
	stack->head = first->next;
	last = ft_lstlast(stack->head);
	last->next = first;
	first->next = NULL;
}

void	rotate_a(t_stack *a)
{
	if (!(a->head) || !(a->head->next))
		return ;
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack *b)
{
	if (!(b->head) || !(b->head->next))
		return ;
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (!(a->head) || !(a->head->next) || !(b->head) || !(b->head->next))
		return ;
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
