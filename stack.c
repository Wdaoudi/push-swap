/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:44:02 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/05 21:33:55 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// implementer les focntions push, pop, isempty, top

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
// int	*fil_tab(char **str, int size)
// {
// 	int	i;

// 	i = 1;
// 	while (i < size - 1)
// 	{
// 		init_stack(str[i], size);
// 	}
// 	return ()
// }
int	parse_arg(char *arg, int *result, int *number)
{
	char	**words;
	int		i;

	words = ft_split(arg, ' ');
	if (!words)
		return (0);
	i = 0;
	while (words[i])
	{
		result[*number] = ft_atoi(words[i]);
		(*number)++;
		free(words[i]);
		i++;
	}
	free(words);
	return (1);
}
int	*parsing_fill(char **str, int ac)
{
	int	*result;
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	while (i < ac)
		count += count_words(str[i++], ' ');
	result = malloc(sizeof(int) * count);
	if (!result)
		return (NULL);
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (!parse_arg(str[i], result, &j))
		{
			free(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}

int	main(int ac, char **av)
{
	print_list(init_stack(parsing_fill(av, ac), ac - 1));
	// for (int i = 0; i < size; i++)
	// 	printf("%d\n", arr[i]);
	return (0);
}
