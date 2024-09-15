/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:43:44 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/14 16:22:10 by wdaoudi-         ###   ########.fr       */
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
// 	lst = stack_size(lst);
// 	printf("%d\n", lst->size);
// 	}
// 	free(tab);
// 	print_list(lst->head);
// 	free_stack(lst);
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_stacks	stacks;
	int			*tab;
	// int			size;

	if (ac < 2)
		return (0);
	stacks.a = NULL;
	stacks.b = NULL;
	tab = ft_valid(ac, av, &stacks.a);
	if (!tab)
		return (ft_putendl_fd("Error", 2), 1);
	// size = stacks.a->size;
	stacks.b = ft_init_stack();
	if (!stacks.b)
		return (free(tab), free_stack(stacks.a), ft_putendl_fd("Error", 2), 1);
	print_list(stacks.a->head);
	// if (is_sorted(stacks.a, stacks.b))
	// 	return (free(tab), free_stack(stacks.a), free_stack(stacks.b), 0);
	// if (size <= 3)
	// 	sort_3(stacks.a, stacks.b);
	// else if (size <= 5)
	// 	sort_5(&stacks, size);
	// else
	// 	sort_stack(&stacks, size, tab);
	// free(tab);
	// free_stack(stacks.a);
	// free_stack(stacks.b);
	return (0);
}
