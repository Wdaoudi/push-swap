/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:51:16 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/13 01:52:35 by wdaoudi-         ###   ########.fr       */
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

t_list	*ft_second_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

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

// int	main(void)
// {
// 	int tab[8] = {1, 2, 3, 4, 5, 6, 7, 8};
// 	t_stack *lsta;
// 	t_stack *lstb;
// 	int i = 0;

// 	lsta = ft_init_stack();
// 	lstb = ft_init_stack();

// 	while (i < 8)
// 	{
// 		add_to_queue(lsta, tab[i++]);
// 	}
// 	printf("stack a avant = \n");
// 	print_list(lsta->head);
// 	printf("----------------------------\n");
// 	print_list(lstb->head);
// printf("----------------------------\n");
// 	printf("rra = \n");
// 	printf("----------------------------\n");
// 	rra(lsta);
// 	printf("----------------------------\n");
// 	print_list(lstb->head);
// 	printf("----------------------------\n");
// 	print_list(lsta->head);
// 	//printf("swap b = \n");
// 	//display_stack(lstb);
// 	// printf("stack b avant = \n");
// 	// display_stack(lstb);
// 	// ft_push_a(lsta, lstb);
// 	// ft_push_a(lsta,lstb);
// 	// printf("stack a apres = \n");
// 	// display_stack(lsta);
// 	// printf("stack b apres = \n");
// 	// display_stack(lstb);
// 	// printf("stack apres un push_a = \n");
// 	// ft_push_a(lstb, lsta);
// 	// display_stack(lsta);
// 	return (0);
// }