/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:29:20 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/17 16:32:05 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_list(t_list *stack)
{
	t_list	*current;

	current = stack;
	if (current == NULL)
	{
		printf("La liste est vide.\n");
		return ;
	}
	while (current != NULL)
	{
		printf("Content: %d\n", current->content);
		current = current->next;
	}
}
