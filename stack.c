/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:44:02 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/05 19:37:49 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// implementer les focntions push, pop, isempty, top

typedef struct s_stack
{
	struct s_list	*first;
}					t_stack;

typedef struct s_list
{
	int				content;
	int				index;
	int				cost;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
t_stack	*init_stack(int *tab, int size)
{
	int		i;
	t_stack	*stack;
	t_list	*current;

	i = 1;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	current = ft_lstnew(tab[0]); // current vaut lstnew du tab de i ++
	stack->first = current;      // le premier nnoeud de la liste vaut current
	while (i < size)
	{
		current->next = ft_lstnew(tab[i++]);
		current->next->prev = current;
		// car le pointeur previous du next de current point vers current
		current = current->next;
		// current deviens le maillon d apres on fait avancer de un
	}
	return (stack);
}

int	main(int ac, char **av)
{
	int	size;
	int	*arr;

	size = ac - 1;
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (1);
	for (int i = 0; i < size; i++)
		arr[i] = atoi(av[i + 1]);
	init_stack(arr, ac - 1);
	for (int i = 0; i < size; i++)
		printf("%d\n", arr[i]);
	return (0);
}
