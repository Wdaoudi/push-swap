/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:20:54 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/05 20:13:51 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(char *str)
{
	int	i;
	int	has_digit;
	int	number;

	free((number = 0, i = -1, has_digit = 0, NULL));
	while (str[++i])
	{
		if (str[i] == ' ')
			number = 0;
		else if (str[i] == '-' || str[i] == '+')
		{
			if (number || !(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (1);
			number = 1;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			free((has_digit = 1, number = 1, NULL));
		else // if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
			return (1);
	}
	if (has_digit == 0)
		return (1);
	return (0);
}
int	check_dup(char **parsed)
{
	int	i;
	int	j;
	int	comp1;
	int	comp2;

	i = 0;
	while (parsed[i])
	{
		j = i + 1;
		while (parsed[j])
		{
			// printf("in checkdup\n");
			comp1 = ft_atoispe(parsed[i]);
			comp2 = ft_atoispe(parsed[j]);
			if (comp1 == comp2)
				return (printf("Error\n"), 1);
			// printf (" %d comp %d\n", comp1, comp2);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_lim(int nbr)
{
	if (nbr < -2147483648 || nbr > 2147483647)
		return (1);
	return (0);
}


int	free_parsed(char **parsed)
{
	int	i;

	i = 0;
	while (parsed[i])
	{
		free(parsed[i]);
		i++;
	}
	free(parsed);
	return (1);
}

int	check_limits(char **parsed)
{
	int		i;
	long	num;

	i = 0;
	while (parsed[i])
	{
		num = ft_atoispe(parsed[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_printf("overflow\n");
			return (free_parsed(parsed));
		}
		i++;
	}
	return (0);
}

int	parse_and_check(char **str, int ac)
{
	char	**parsed;
	int		i;

	if (ac == 2)
	{
		if (check_error(str[1]))
			return (ft_printf("Error bad input\n"), 1);
		parsed = ft_split(str[1], ' ');
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			if (check_error(str[i]))
				return (ft_printf("Error bad input\n"), 1);
			i++;
		}
		parsed = parsing(str, ac);
	}
	if (!parsed)
		return (ft_printf("Memory allocation error\n"), 1);
	if (check_limits(parsed) || check_dup(parsed) || free_parsed(parsed))
		return (1);
	return (0);
}

int	check(char **str, int ac)
{
	return (parse_and_check(str, ac));
}

/*1. check error OK
2. parsing
2.1 creer un tableau geant avec tout les array suivi d un espace
2.2 split le tableau
2.3 atoi chaque membre du tableau
3. check limit
4. atoi
5. check duplicate*/

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int result = check(av, ac);
		if (result == 0)
			printf("valid\n");
	}
	// while (i < ac)
	// {
	// 	result = check_error(av[i]);
	// 	if (result == 1)
	// 	{
	// 		printf("error\n");
	// 		return (0);
	// 	}
	// 	i++;
	// }
	// 	printf("valid\n");
	return (0);
}