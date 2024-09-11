/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:21:18 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/11 19:26:27 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_a(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_list	*current;
// 	t_list	*new_top;

// 	if (!stack_a || !stack_a->head || !stack_b)
// 		return ;
// 	current = stack_a->head;
// 	new_top = stack_a->head->next;
// 	if (stack_b == NULL)
// 	{
// 		stack_b->head = current;
// 		current->next = NULL;
// 		stack_a->head = new_top;
// 	}
// 	else
// 	{
// 		current->next = stack_b->head;
// 		stack_a->head = new_top;
// 	}
// }
void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*current;

	if (!stack_a || !stack_a->head || !stack_b)
		return ;
	current = stack_a->head;
	stack_a->head = current->next;
	current->next = stack_b->head;
	stack_b->head = current;
	// stack_a->size--;
	// stack_b->size++;
}

// void	push_b(t_stacks *stack)
// {
// 	t_list	*current;
// 	t_list	*new_top;

// 	if (!stack->b)
// 		return ;
// 	current = stack->b;
// 	new_top = current->next;
// 	if (stack->a == NULL)
// 	{
// 		stack->a = current;
// 		current->next = NULL;
// 		stack->b = new_top;
// 	}
// 	else
// 	{
// 		current->next = stack->a;
// 		stack->b = new_top;
// 	}
// }

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*current;

	if (!stack_b || !stack_b->head || !stack_a)
		return ;
	current = stack_b->head;
	stack_b->head = current->next;
	current->next = stack_a->head;
	stack_a->head = current;
	// stack_b->size--;
	// stack_a->size++;
}

int	main(void)
{
	int		tab[5] = {1, 2, 3, 4, 5};
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return (1);
	}
	// t_stack *a = init_stack(tab,5);
	// t_stack b;
	stack_a->head = init_stack(tab, 5);
	stack_b->head = NULL;
    
	printf("avant stack a=\n");
	print_list(stack_a->head);
	printf("avant stack b=\n");
	print_list(stack_b->head);
   rra(stack_a);
	printf("apres stack a=\n");
	print_list(stack_a->head);
	printf("stack b=\n");
	print_list(stack_b->head);
	return (0);
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

// 			push_a(&stack_a);

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
