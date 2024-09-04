/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:48:34 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/04 19:57:14 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parsing(char **str, int ac)
{
	char *tab;
	char **result;
	int i;
	int len;

	if (ac < 2)
		return (NULL);
	len = 0;
	i = 1;
	while (i < ac)
	{
		len += ft_strlen(str[i]) + 1;
		i++;
	}
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	tab[0] = '\0';
	i = 1;
	while (i < ac)
	{
		ft_strcat(tab, str[i]);
		ft_strcat(tab, " ");
		i++;
	}
	result = ft_split(tab, ' ');
	free(tab);
	return (result);
}