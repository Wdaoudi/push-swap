/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:43:44 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/25 19:44:15 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_end(long *tab, t_stack *a, t_stack *b)
{
	if (tab)
		free(tab);
	if (b)
		free_stack(b);
	if (a)
		free_stack(a);
}

int	main(int ac, char **av)
{
	long		*tab;
	size_t		i;
	int			valid;
	t_stacks	stack;

	if (ac > 1)
	{
	stack.a.head = NULL;
	valid = 1;
	stack.b.head = NULL;
	if (ft_only_space(av[1]) == 0)
		return (0);
	tab = ft_valid(ac, av, &stack.a, &valid);
	if (valid == 0)
		return (ft_putendl_fd("Error", 2), 0);
	if (!tab)
		return (0);
	i = 0;
	if (stack.a.size == 0)
		return (ft_free_end(tab, &stack.a, &stack.b), 0);
	while (i < stack.a.size)
		add_to_queue(&stack.a, tab[i++]);
	if (is_sorted(&stack.a, &stack.b) == true)
		return (ft_free_end(tab, &stack.a, &stack.b), 0);
	if (stack.a.size == 2)
	{
		sort_2(&stack.a, &stack.b);
		return (ft_free_end(tab, &stack.a, &stack.b), 0);
	}
	else if (stack.a.size == 3)
		return (sort_3(&stack.a), ft_free_end(tab, &stack.a, &stack.b), 0);
	sort_array(tab, stack.a.size);
	// for(size_t j = 0; j <stack.a.size; j++)
	// {
	// 	printf("%ld\n",tab[j]);
	// }
	sort_stack(&stack, stack.a.size, tab);
	printf("fin de liste\n");
	print_list(stack.a.head);
	ft_free_end(tab, &stack.a, &stack.b);
	}
	return (0);
}
