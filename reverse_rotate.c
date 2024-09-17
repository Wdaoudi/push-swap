/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:51:16 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/17 16:33:29 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_list	*last;
	t_list	*second_last;

	if (!(stack->head) || !(stack->head->next))
		return ;
	second_last = ft_second_last(stack->head);
	last = second_last->next;
	last->next = stack->head;
	stack->head = last;
	second_last->next = NULL;
}

void	rra(t_stack *a)
{
	if (!(a->head) || !(a->head->next))
		return ;
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (!(b->head) || !(b->head->next))
		return ;
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	if (!(a->head) || !(a->head->next) || !(b->head) || !(b->head->next))
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}

t_list	*ft_second_last(t_list *lst)
{
	if (!lst || !lst->next)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
