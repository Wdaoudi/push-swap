/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:51:16 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/11 19:47:39 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_list	*last;
	t_list	*second_last;

	if (!(a->head) || !(a->head->next))
		return ;
	second_last = ft_second_last(a->head);
	last = second_last->next;
	last->next = a->head;
	a->head = last;
	second_last->next = NULL;
}
void	rrb(t_stack *b)
{
	t_list	*last;
	t_list	*second_last;

	if (!(b->head) || !(b->head->next))
		return ;
	second_last = ft_second_last(b->head);
	last = second_last->next;
	last->next = b->head;
	b->head = last;
	second_last->next = NULL;
}
void	rrr(t_stack *a, t_stack *b)
{
	if (!a->head || !b->head)
		return ;
	rra(a);
	rrb(b);
}