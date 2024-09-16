/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:51:16 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/16 18:04:36 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	rra(t_stack *a)
// {
// 	t_list	*last;
// 	t_list	*second_last;

// 	if (!(a->head) || !(a->head->next))
// 		return ;
// 	second_last = ft_second_last(a->head);
// 	last = second_last->next;
// 	last->next = a->head;
// 	a->head = last;
// 	second_last->next = NULL;
// }
// void	rrb(t_stack *b)
// {
// 	t_list	*last;
// 	t_list	*second_last;

// 	if (!(b->head) || !(b->head->next))
// 		return ;
// 	second_last = ft_second_last(b->head);
// 	last = second_last->next;
// 	last->next = b->head;
// 	b->head = last;
// 	second_last->next = NULL;
// }
// void	rrr(t_stack *a, t_stack *b)
// {
// 	if (!a->head || !b->head)
// 		return ;
// 	rra(a);
// 	rrb(b);
// }

// t_list	*ft_second_last(t_list *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next->next)
// 		lst = lst->next;
// 	return (lst);
// }

// int	main(int ac, char **av)
// {
// 	int *tab;
// 	t_stack *stack_a;
// 	t_stack *stack_b;
// 	int i;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	tab = ft_valid(ac, av, &stack_a);
// 	if (!tab)
// 		return (0);
// 	i = 0;
// 	while (i < stack_a->size)
// 		add_to_queue(stack_a, tab[i++]);
// 	free(tab);
// 	printf("stack a avant =\n");
// 	print_list(stack_a->head);
// 	printf("stack_b avant\n");
// 	print_list(stack_b->head);
	
// 	push_a_a(stack_a, stack_b);

// 	printf("stack a apres =\n");
// 	print_list(stack_a->head);
// 	printf("stack_b apres\n");
// 	print_list(stack_b->head);

// 	return (0);
// }
void reverse_rotate(t_stack *stack)
{
    t_list *last;
    t_list *second_last;

    if (!(stack->head) || !(stack->head->next))
        return;
    second_last = ft_second_last(stack->head);
    last = second_last->next;
    last->next = stack->head;
    stack->head = last;
    second_last->next = NULL;
}

void rra(t_stack *a)
{
    if (!(a->head) || !(a->head->next))
        return;
    reverse_rotate(a);
    // ft_printf("rra\n");
}

void rrb(t_stack *b)
{
    if (!(b->head) || !(b->head->next))
        return;
    reverse_rotate(b);
    // ft_printf("rrb\n");
}

void rrr(t_stack *a, t_stack *b)
{
    if (!(a->head) || !(a->head->next) || !(b->head) || !(b->head->next))
        return;
    reverse_rotate(a);
    reverse_rotate(b);
    // ft_printf("rrr\n");
}

t_list *ft_second_last(t_list *lst)
{
    if (!lst || !lst->next)
        return NULL;
    while (lst->next->next)
        lst = lst->next;
    return lst;
}
