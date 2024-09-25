/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:54:46 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/25 18:14:09 by wdaoudi-         ###   ########.fr       */
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

// int	main(int ac, char **av)
// {
// 	int			*parsed;
// 	t_stack stack_a, stack_b;
// 	if (ac > 1)
// 	{
// 		if (check(av, ac) == 0)
// 		{
// 			parsed = parsing_fill(av, ac);
// 			if (!parsed)
// 				return (1);
// 			stack_a.head= init_stack(parsed, ac - 1);
// 			stack_b.head = NULL;
// 			free(parsed);
// 			printf("avant stack a=\n");
// 			print_list(stack_a.head);
// 			printf("avant stack b=\n");
// 			print_list(stack_b.head);

// 	rotate_a(&stack_a);
// 			printf("apres stack a=\n");
// 			print_list(stack_a.head);
// 			printf("stack b=\n");
// 			print_list(stack_b.head);

// 			// if (stack.a || stack.b)
// 			// {
// 			// 	free_stack(stack.a);
// 			// 	// free_stack(stack.b);
// 			// }
// 			// free_stack((init_stack(parsing_fill(av, ac), ac - 1)));
// 			// for (int i = 0; i < size; i++)
// 			// 	printf("%d\n", arr[i]);
// 		}
// 		else
// 			return (ft_putendl_fd("Error", 2), -1);
// 	}
// 	return (0);
// }
