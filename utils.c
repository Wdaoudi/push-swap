/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:22:54 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/11 18:17:54 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr != '\0')
		ptr++;
	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}

long	ft_atoispe(const char *nptr)
{
	long	nbr;
	long	i;
	int		signe;

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
	if ((nbr * signe > 2147483647) || (nbr * signe < -2147483648))
		return (nbr + nbr);
	return (nbr * signe);
}

void	free_stack(t_list *stack)
{
	t_list	*current;
	t_list	*next;

	if (!stack)
		return ;
	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

static int	ft_atoi_strict_helper(const char *str, int *error, long *result,
		int *sign)
{
	*result = 0;
	*sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		*sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (!*str)
	{
		*error = 1;
		return (0);
	}
	return (1);
}

int	ft_atoi_strict(const char *str, int *error)
{
	long	result;
	int		sign;

	*error = 0;
	if (!ft_atoi_strict_helper(str, error, &result, &sign))
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			*error = 1;
			return (0);
		}
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return ((int)(result * sign));
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}