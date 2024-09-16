/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:43:44 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/16 18:41:52 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int ac, char **av)
// {
// 	int		*tab;
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	int		i;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	tab = ft_valid(ac, av, &stack_a);
// 	if (!tab)
// 		return (0);
// 	i = 0;
// 	{
// 	while (i < lst->size)
// 		add_to_queue(lst, tab[i++]);
// lst = stack_size(lst);
// 	printf("%d\n", lst->size);
// 	}
// 	free(tab);
// 	print_list(lst->head);
// 	free_stack(lst);
// 	return (0);
// }

int	main(int ac, char **av)
{
	int *tab;

	t_stacks *stack = NULL;
	t_stack *a = NULL;
	t_stack *b = NULL;
	int i;
	b = ft_init_stack();
	a = ft_init_stack();
	tab = ft_valid(ac, av, &a);
	if (!tab)
		return (0);
	i = 0;
	while (i < a->size)
		add_to_queue(a, tab[i++]);
	// printf("%d\n", a->size);
	// free(tab);
	// print_list(a->head);
	stack = malloc(sizeof(t_stacks));
	if (!stack)
	{
		return (0);
	}
	stack->a = a;
	stack->b = b;
	
	// PARTIE DE TRI
	if (is_sorted(a, b) == true)
		return (0);
	if (a->size == 2)
	{
		sort_2(a, b);
		return (0);
	}
	else if (a->size == 3)
	{
		sort_3(a);
		return (0);
	}
	sort_array(tab, a->size);
	sort_stack(stack, a->size, tab);
	printf("liste a la fin du programme\n");
	print_list(a->head);
	// free_stack(stack->a);
	return (0);
}