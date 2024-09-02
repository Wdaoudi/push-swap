/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:20:54 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/02 23:37:46 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(char *str)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (1);
		}
		else if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
			return (1);
		if (str[i] >= '0' && str[i] <= '9')
			has_digit = 1;
		i++;
	}
	if (has_digit = 0)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	i;
	int	signe;

	i = 0;
	signe = 1;
	nbr = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45)
	{
		signe = -signe;
		i++;
	}
	else if (nptr[i] == 43)
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nbr = (nbr * 10) + nptr[i] - '0';
		i++;
	}
	return (nbr * signe);
}

int	check_dup(int nbr)
{
	int i = 0;
	while ()
}
// d abord verfier les differetns input pour voir si ils sont valide apres avooir parser
//correctement ett split la chaine creer,la atoi les different tableau et ensuite envoyer les tableau a check dup

int	check_lim(int nbr)
{
	if (nbr < -2147483648 || nbr > 2147483647)
		return (1);
	return (0);
}

int	check(char *str)
{
	/*1. check error OK
 2. parsing 
 	2.1 creer un tableau geant avec tout les array suivi d un espace
	2.2 split le tableau 
	2.3 atoi chaque membre du tableau
 3. check limit
 4. atoi
 5. check duplicate*/
}

int	main(int ac, char **av)
{
	int i;
	int result;
	i = 1;
	while (i < ac)
	{
		result = check_error(av[i]);
		if (result == 1)
		{
			printf("error\n");
			return 0;
		}
		i++;
	}		//printf("(\"%s\")", result ? "error" : "valid");
	printf("valid\n");
	return (0);
}