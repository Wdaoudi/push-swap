/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:43:44 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/26 18:55:01 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialize_stacks(t_stacks *stack)
{
	stack->a.head = NULL;
	stack->b.head = NULL;
}

static int	handle_small_sorts(t_stacks *stack, long *tab)
{
	if (is_sorted(&stack->a, &stack->b))
		return (ft_free_end(tab, &stack->a, &stack->b), 1);
	if (stack->a.size == 2)
		return (sort_2(&stack->a, &stack->b), ft_free_end(tab, &stack->a,
				&stack->b), 1);
	if (stack->a.size == 3)
		return (sort_3(&stack->a), ft_free_end(tab, &stack->a, &stack->b), 1);
	return (0);
}

static int	process_input(int ac, char **av, t_stacks *stack, long **tab)
{
	int	valid;

	valid = 1;
	if (ft_only_space(av[1]) == 0)
		return (0);
	*tab = ft_valid(ac, av, &stack->a, &valid);
	if (valid == 0)
		return (ft_putendl_fd("Error", 2), 0);
	if (!*tab)
		return (0);
	if (stack->a.size == 0)
		return (ft_free_end(*tab, &stack->a, &stack->b), 0);
	return (1);
}

static void	fill_stack_a(t_stack *stack_a, long *tab)
{
	size_t	i;

	i = 0;
	while (i < stack_a->size)
		add_to_queue(stack_a, tab[i++]);
}

int	main(int ac, char **av)
{
	t_stacks	stack;
	long		*tab;

	if (ac <= 1)
		return (0);
	initialize_stacks(&stack);
	if (!process_input(ac, av, &stack, &tab))
		return (0);
	fill_stack_a(&stack.a, tab);
	if (handle_small_sorts(&stack, tab))
		return (0);
	sort_array(tab, stack.a.size);
	sort_stack(&stack, stack.a.size, tab);
	ft_free_end(tab, &stack.a, &stack.b);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	long		*tab;
// 	size_t		i;
// 	int			valid;
// 	t_stacks	stack;

// 	if (ac > 1)
// 	{
// 		stack.a.head = NULL;
// 		valid = 1;
// 		stack.b.head = NULL;
// 		if (ft_only_space(av[1]) == 0)
// 			return (0);
// 		tab = ft_valid(ac, av, &stack.a, &valid);
// 		if (valid == 0)
// 			return (ft_putendl_fd("Error", 2), 0);
// 		if (!tab)
// 			return (0);
// 		i = 0;
// 		if (stack.a.size == 0)
// 			return (ft_free_end(tab, &stack.a, &stack.b), 0);
// 		while (i < stack.a.size)
// 			add_to_queue(&stack.a, tab[i++]);
// 		if (is_sorted(&stack.a, &stack.b) == true)
// 			return (ft_free_end(tab, &stack.a, &stack.b), 0);
// 		if (stack.a.size == 2)
// 			return (sort_2(&stack.a, &stack.b), ft_free_end(tab, &stack.a,
// 					&stack.b), 0);
// 		else if (stack.a.size == 3)
// 			return (sort_3(&stack.a), ft_free_end(tab, &stack.a, &stack.b), 0);
// 		sort_array(tab, stack.a.size);
// 		sort_stack(&stack, stack.a.size, tab);
// 		ft_free_end(tab, &stack.a, &stack.b);
// 	}
// 	return (0);
// }