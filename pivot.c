/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:53:49 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/12 16:18:01 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_tab(t_stack *stack)
{
	int	tab[ft_lstsize(stack->head)];
	int	i;

	i = 0;
	while (stack->head->next)
	{
		tab[i] = stack->head->content;
		i++;
	}
	return (tab[i]);
}
int	*short_tab(int *tab)
{
	int	i;
	int	j;
	int tamp = 0;
	i = 0;
	j = 1;
	while (tab[i])
	{
		if (tab[i+1] <tab[i])
		{
			tamp = tab[i];
			tab[i] = tab[i+1];
			tab[i+1] = tamp;
			j = 0;
		}
	}
}

int	find_med(t_stack *stack, int size)
{
	int	tab[size + 1];
	int	i;

	i = 0;
	while (stack->head->next)
	{
		tab[i] = stack->head->content;
		i++;
	}
	return (tab[i / 2]);
}

int	find_firstq(t_stack *stack, int size)
{
	int	tab[size + 1];
	int	i;

	i = 0;
	while (stack->head->next)
	{
		tab[i] = stack->head->content;
		i++;
	}
	return (tab[i / 4]);
}

int	find_lastq(t_stack *stack, int size)
{
	int	tab[size + 1];
	int	i;

	i = 0;
	while (stack->head->next)
	{
		tab[i] = stack->head->content;
		i++;
	}
	return (tab[i * 3 / 4]);
}

int	main(void)
{
	int tab[5] = {1, 2, 3, 4, 5};
	t_stack *stack_a;
	t_stack *stack_b;

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

	for (int i = 0; i < lst_)
		// printf("%d\n", find_med(stack_a, ft_lstsize(stack_a->head)));
		// printf("%d\n", find_firstq(stack_a, ft_lstsize(stack_a->head)));
		// printf("%d\n", find_lastq(stack_a, ft_lstsize(stack_a->head)));
		// printf("avant stack a=\n");
		// print_list(stack_a->head);
		// printf("avant stack b=\n");
		// print_list(stack_b->head);
		//    printf("%d\n", ft_lstsize(stack_a->head));

		return (0);
}