/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:48:34 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/02 16:21:07 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parsing(char **str, int ac)
{
	size_t	i;
    char *tab;
    char *
	i = 0;
    tab = ft_strdup(str[1]);
    if (!tab)
        return (NULL);
    while(str[i+1])
    {
        tab = ft_strjoin(tab, " ");
        tab = ft_strjoin(tab, str[i + 1]);
        i ++;
    }
	return (tab);
}

int	main(int ac, char **av)
{
    int i = 0;
	if (ac > 1)
	{
        while (av != "\0")
		{
            parsing(av[i], ac);
	    }
    }
    
	write(1, "\n", 1);
	return (0);
}