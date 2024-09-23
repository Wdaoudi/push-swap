/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:29:20 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/23 18:08:44 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../printf/ft_printf.h"

void	print_list(t_list *stack)
{
	t_list	*current;

	current = stack;
	if (current == NULL)
	{
		ft_printf("La liste est vide.\n");
		return ;
	}
	while (current != NULL)
	{
		ft_printf("Content: %d\n", current->content);
		current = current->next;
	}
}
