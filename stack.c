/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:44:02 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/05 18:08:21 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// implementer les focntions push, pop, isempty, top

t_stack	init_stack(int *tab, int size)
{
	int		i;
	t_stack	*stack;
	t_list	*current;

	i = 0;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	current = ft_lstnew(tab[i++]); //current vaut lstnew du tab de i ++
	stack->first = current;//le premier nnoeud de la liste vaut current
	while (i < size)
	{
		current->next = ft_lstnew(tab[i++]);
		current->next->prev = current; //car le pointeur previous du next de current point vers current
		current = current->next; // current deviens le maillon d apres on fait avancer de un 
	}
	return (stack);
}
t_list	new_node(int content)
{
	ft_lstnew(content);
}

int	main(int ac, char **av)
{
	stack(atoi());
}
