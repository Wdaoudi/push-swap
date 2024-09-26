/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:20:54 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/26 18:40:59 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_input(char **av)
{
	int		i;
	char	*str;
	char	*space;

	space = ft_strdup(" ");
	if (space == NULL)
		return (NULL);
	i = 1;
	str = ft_strdup(av[i]);
	if (!str)
		return (free(space), NULL);
	while (av[i + 1])
	{
		str = ft_strjoin_free(str, space);
		if (!str)
			return (free(space), NULL);
		str = ft_strjoin_free(str, av[i + 1]);
		if (!str)
			return (free(space), NULL);
		i++;
	}
	free(space);
	return (str);
}

int	ft_check_str(char **res, int *valid)
{
	int		i;
	int		j;
	long	nb1;
	long	nb2;

	j = -1;
	nb1 = 0;
	nb2 = 0;
	if (ft_isdigit_spe(res) == 0)
		return (*valid = 0, 0);
	while (res[++j])
	{
		i = j + 1;
		nb1 = ft_atoi_spe(res[j]);
		if (nb1 == 2147483648)
			return (*valid = 0, 0);
		while (res[i])
		{
			nb2 = ft_atoi_spe(res[i]);
			if (nb1 == nb2 || nb1 >= 2147483648 || nb2 >= 2147483648)
				return (*valid = 0, 0);
			i++;
		}
	}
	return (1);
}

long	*ft_valid(int ac, char **av, t_stack *lst, int *valid)
{
	char	**res;
	long	*tab;

	res = ft_parsing(ac, av, valid);
	if (!res)
		return (NULL);
	tab = ft_init_tab(res, lst, valid);
	if (!tab)
		return (ft_free(res), NULL);
	return (ft_free(res), tab);
}

char	**ft_parsing(int ac, char **av, int *valid)
{
	char	*str;
	char	**res;

	if (ac > 1)
	{
		str = ft_input(av);
		if (!str)
			return (free(str), NULL);
		res = ft_split(str, ' ');
		if (!res)
			return (free(str), NULL);
		if (ft_check_str(res, valid) == 0)
			return (free(str), ft_free(res), NULL);
		else
			return (free(str), res);
	}
	return (NULL);
}
