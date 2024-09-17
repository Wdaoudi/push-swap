/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:20:54 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/17 16:45:49 by wdaoudi-         ###   ########.fr       */
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

int	ft_check_str(char **res)
{
	int			i;
	int			j;
	long int	nb1;
	long int	nb2;

	j = -1;
	nb1 = 0;
	nb2 = 0;
	if (ft_isdigit_spe(res) == 0)
		return (0);
	while (res[++j])
	{
		i = j + 1;
		nb1 = ft_atoi_spe(res[j]);
		if (nb1 == 2147483648)
			return (0);
		while (res[i])
		{
			nb2 = ft_atoi_spe(res[i]);
			if (nb1 == nb2 || nb1 >= 2147483648 || nb2 >= 2147483648)
				return (ft_putendl_fd("error", 2), 0);
			i++;
		}
	}
	return (1);
}

int	*ft_valid(int ac, char **av, t_stack **lst)
{
	char	**res;
	int		*tab;

	res = ft_parsing(ac, av);
	if (!res)
		return (NULL);
	*lst = ft_init_stack();
	if (!*lst)
		return (ft_free(res), NULL);
	tab = ft_init_tab(res, *lst);
	if (!tab)
		return (ft_free(res), free_stack(*lst), NULL);
	return (ft_free(res), tab);
}

char	**ft_parsing(int ac, char **av)
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
		if (ft_check_str(res) == 0)
			return (free(str), ft_free(res), NULL);
		else
			return (free(str), res);
	}
	return (NULL);
}
