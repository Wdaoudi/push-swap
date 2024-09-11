/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:54:46 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/11 18:49:25 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *a)
{
	t_list	*first;
	t_list	*last;

	if (!(a->head) || !(a->head->next))
		return ;
	first = a->head;
	a->head = first->next;
	last = ft_lstlast(a->head);
	last->next = first;
	first->next = NULL;
}
void	rotate_b(t_stack *b)
{
	t_list *first;
	t_list *last;

	if (!(b->head) || !(b->head->next))
		return ;
	first = b->head;
	b->head = first->next;
	last = ft_lstlast(b->head);
	last->next = first;
	first->next = NULL;
}

void    rr(t_stack *a, t_stack *b)
{
if (!a->head || !b->head)
	return;
rotate_a(a);
rotate_b(b);
}