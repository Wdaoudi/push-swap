/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:44:02 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/17 16:32:42 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_init_tab(char **res, t_stack *lst)
{
	int	i;
	int	*tab;

	i = 0;
	lst->size = ft_strlen_tab(res);
	tab = malloc(sizeof(int) * (lst->size));
	if (!tab)
		return (NULL);
	while (i < lst->size)
	{
		tab[i] = ft_atoi_spe(res[i]);
		i++;
	}
	return (tab);
}

t_stack	*ft_init_stack(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	else
		new->head = NULL;
	return (new);
}

void	add_to_queue(t_stack *lst, int nbr)
{
	t_list	*new;
	t_list	*current;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->target = NULL;
	new->content = nbr;
	if (!lst->head)
		lst->head = new;
	else
	{
		current = lst->head;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

t_stack	*stack_size(t_stack *stack)
{
	stack->size = ft_lstsize(stack->head);
	return (stack);
}

// int	main(int ac, char **av)
// {
// 	int *tab;
// 	t_stack *lst;
// 	// t_stack *b;
// 	int i;

// 	lst = NULL;
// 	// b = NULL;
// 	tab = ft_valid(ac, av, &lst);
// 	if (!tab)
// 		return (0);
// 	i = 0;
// 	while (i < lst->size)
// 		add_to_queue(lst, tab[i++]);
// 	lst = stack_size(lst);
// 	printf("%d\n", lst->size);
// 	free(tab);
// 	print_list(lst->head);
// 	free_stack(lst);
// 	return (0);
// }