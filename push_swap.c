/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:43:44 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/17 17:13:28 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_end(int *tab, t_stack *a, t_stack *b)
{
	free(tab);
	free_stack(a);
	free_stack(b);
}
void	ft_free_end2(int *tab, t_stack *b)
{
	free(tab);
	free_stack(b);
}

int	main(int ac, char **av)
{
	int *tab;
	int i;
	t_stacks *stack;
	t_stack *a;
	t_stack *b;

	stack = NULL;
	a = NULL;
	b = NULL;
	b = ft_init_stack();
	a = ft_init_stack();
	if (!a)
		return (free_stack(b),0);
	tab = ft_valid(ac, av, &a);
	if (!tab)
		return (0);
	i = 0;
	while (i < a->size)
		add_to_queue(a, tab[i++]);
	stack = malloc(sizeof(t_stacks));
	if (!stack)
		return (ft_free_end(tab, a, b), 0);
	stack->a = a;
	stack->b = b;
	if (is_sorted(a, b) == true)
		return (ft_free_end(tab, a, b), 0);
	if (a->size == 2)
	{
		sort_2(a, b);
		return (ft_free_end(tab, a, b), 0);
	}
	else if (a->size == 3)
	{
		sort_3(a);
		return (ft_free_end(tab, a, b), 0);
	}
	sort_array(tab, a->size);
	sort_stack(stack, a->size, tab);
	ft_free_end(tab, a, b);
	free(stack);
	return (0);
}