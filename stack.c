/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:44:02 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/10 16:44:50 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// implementer les focntions push, pop, isempty, top

t_list	*init_stack(int *tab, int size)
{
	int		i;
	t_list	*listt;
	t_list	*maillon;

	i = 0;
	listt = NULL;
	while (i < size)
	{
		maillon = ft_lstnew(tab[i++]);
		if (!maillon)
		{
			free_stack(listt);
			return (NULL);
		}
		ft_lstadd_back(&listt, maillon);
	}
	return (listt);
}
// int	*fil_tab(char **str, int size)
// {
// 	int	i;

// 	i = 1;
// 	while (i < size - 1)
// 	{s
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
		i++;
	}
	ft_free(words);
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
			return (free(result), NULL);
		i++;
	}
	return (result);
}

// int	main(int ac, char **av)
// {
// 	int		*parsed;
// 	t_stack	*stack;

// 	if (ac > 1)
// 	{
// 		if (check(av, ac) == 0)
// 		{
// 			parsed = parsing_fill(av, ac);
// 			if (!parsed)
// 				return (1);
// 			stack = init_stack(parsed, ac - 1);
// 			print_list(stack);
// 			if (stack)
// 				free_stack(stack);
// 			free(parsed);
// 			// free_stack((init_stack(parsing_fill(av, ac), ac - 1)));
// 			// for (int i = 0; i < size; i++)
// 			// 	printf("%d\n", arr[i]);
// 		}
// 		else
// 			return (printf("wrong\n"), 1);
// 	}
// 	return (printf("valid\n"), 0);
// }
