/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:29:20 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/26 18:37:59 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"
#include "libft.h"

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
		ft_printf("Content: %d \n", current->content);
		current = current->next;
	}
}
// void	print_list2(t_stacks stack)
// {
// 	t_list	*current;

// 	current = stack;
// 	if (current == NULL)
// 	{
// 		ft_printf("La liste est vide.\n");
// 		return ;
// 	}
// 	while (current != NULL)
// 	{
// 		ft_printf("Content: %d \n", current->target->content);
// 		current = current->next;
// 	}
// }
