/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:54:46 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/16 18:00:30 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	rotate_a(t_stack *a)
// {
// 	t_list	*first;
// 	t_list	*last;

// 	if (!(a->head) || !(a->head->next))
// 		return ;
// 	first = a->head;
// 	a->head = first->next;
// 	last = ft_lstlast(a->head);
// 	last->next = first;
// 	first->next = NULL;
// }
// void	rotate_b(t_stack *b)
// {
// 	t_list *first;
// 	t_list *last;

// 	if (!(b->head) || !(b->head->next))
// 		return ;
// 	first = b->head;
// 	b->head = first->next;
// 	last = ft_lstlast(b->head);
// 	last->next = first;
// 	first->next = NULL;
// }

// void    rr(t_stack *a, t_stack *b)
// {
// if (!a->head || !b->head)
// 	return;
// rotate_a(a);
// rotate_b(b);
// }

void rotate(t_stack *stack)
{
    t_list *first;
    t_list *last;

    if (!(stack->head) || !(stack->head->next))
        return;
    first = stack->head;
    stack->head = first->next;
    last = ft_lstlast(stack->head);
    last->next = first;
    first->next = NULL;
}

void rotate_a(t_stack *a)
{
    if (!(a->head) || !(a->head->next))
        return;
    rotate(a);
    // ft_printf("ra\n");
}

void rotate_b(t_stack *b)
{
    if (!(b->head) || !(b->head->next))
        return;
    rotate(b);
    // ft_printf("rb\n");
}

void rr(t_stack *a, t_stack *b)
{
    if (!(a->head) || !(a->head->next) || !(b->head) || !(b->head->next))
        return;
    rotate(a);
    rotate(b);
    // ft_printf("rr\n");
}
