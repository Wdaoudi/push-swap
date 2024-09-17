/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:06:22 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/17 13:53:54 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_lst(t_stack *stack)
{
    t_list *first;
    t_list *second;

    if (!(stack->head) || !(stack->head->next))
        return;
    first = stack->head;
    second = first->next;
    first->next = second->next;
    second->next = first;
    stack->head = second;
}

void swap_a(t_stack *a)
{
    if (!(a->head) || !(a->head->next))
        return;
    swap_lst(a);
    ft_printf("sa\n");
}

void swap_b(t_stack *b)
{
    if (!(b->head) || !(b->head->next))
        return;
    swap_lst(b);
    ft_printf("sb\n");
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    if (!(stack_a->head) || !(stack_a->head->next) || !(stack_b->head) || !(stack_b->head->next))
        return;
    swap_lst(stack_a);
    swap_lst(stack_b);
    ft_printf("ss\n");
}

