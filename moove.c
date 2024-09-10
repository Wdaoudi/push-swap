/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:21:18 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/10 16:41:55 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stacks *stack)
{
	t_list *current;
    t_list *new_top;
	if (!stack->a)
		return;
    current = stack->a;
    new_top = current->next;
    if (stack->b == NULL)
    {
       stack->b = current;
       current->next = NULL;
       stack->a = new_top;
    }
    else
    {
        current->next = stack->b;
        stack->a = new_top;
    }
}

int main(void)
{
    int tab[5] = {1,2,3,4,5};
    // t_stack *a = init_stack(tab,5);
    // t_stack b;
    t_stacks stack;

    stack.a = init_stack(tab,5);
    stack.b = NULL;
    printf("avant stack a=\n");
    print_list(stack.a);
    printf("avant stack b=\n");
    print_list(stack.b);
    push(&stack);
    
    printf("apres stack a=\n");
    print_list(stack.a);
    printf("stack b=\n");
    print_list(stack.b);

    return (0);
}