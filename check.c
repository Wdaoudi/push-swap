/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:20:54 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/07 18:58:16 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(char *str)
{
	int	i;
	int	has_digit;
	int	number;

	free((number = 0, i = 0, has_digit = 0, NULL));
	while (str[i])
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
		i++;
	}
	return (has_digit == 0);
}
int	check_dup(int *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
int	check_limits(char **parsed)
{
	int		i;
	long	num;

	i = 0;
	while (parsed[i])
	{
		num = ft_atol(parsed[i]);
		if (num < -2147483648 || num > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

char	**parse_input(char **av, int ac)
{
	char	**parsed;
	int		i;

	if (ac == 2)
		parsed = ft_split(av[1], ' ');
	else
	{
		parsed = malloc(sizeof(char *) * ac);
		if (!parsed)
			return (NULL);
		i = 0;
		while (i < ac - 1)
		{
			parsed[i] = ft_strdup(av[i + 1]);
			if (!parsed)
				return (ft_free(parsed), NULL);
			i++;
		}
		parsed[i] = NULL;
	}
	return (parsed);
}

int	parse_and_check(char **av, int ac)
{
	int		*numbers;
	int		count;
	int		error;
	int		i;
	char	**split;
	int		j;

	numbers = malloc(sizeof(int) * (ac - 1));
	if (!numbers)
		return (1);
	count = 0;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (free(numbers), 1);
		j = 0;
		while (split[j])
		{
			error = 0;
			numbers[count] = ft_atoi_strict(split[j], &error);
			if (error)
				return (ft_free(split), 1);
			count++;
			j++;
		}
		ft_free(split);
		i++;
	}
	if (check_dup(numbers, count))
	{
		free(numbers);
		return (1);
	}
	free(numbers);
	return (0);
}
int	check(char **str, int ac)
{
	return (parse_and_check(str, ac));
}
