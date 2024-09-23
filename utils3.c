/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:47:00 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/23 19:50:11 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_lenght(t_stack *stack)
{
	t_list	*node;
	int		i;

	i = 1;
	node = stack->head->next;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

int ft_only_space(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (!(str[i] == 32 || str[i] <= 13))
			return (1);
		i ++;
	}
	return (0);
}