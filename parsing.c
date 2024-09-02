/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:48:34 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/02 23:39:47 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*parsing(char **str, int ac)
{
	size_t	i;
	char	*tab;

	i = 1;
	tab = ft_strdup(str[1]);
	if (!tab)
		return (NULL);
	while (str[i + 1])
	{
		tab = ft_strjoin(tab, " ");
		tab = ft_strjoin(tab, str[i + 1]);
		i++;
	}
	return (split(tab, " "));
}
