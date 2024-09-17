/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:22:54 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/17 15:37:42 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_spe(char *str)
{
	size_t		i;
	long int	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
		if (res * sign > 2147483647 || res * sign < -2147483648)
			return (2147483648);
	}
	return (res * sign);
}

// char	*ft_strcat(char *dest, const char *src)
// {
// 	char	*ptr;

// 	ptr = dest;
// 	while (*ptr != '\0')
// 		ptr++;
// 	while (*src != '\0')
// 	{
// 		*ptr = *src;
// 		ptr++;
// 		src++;
// 	}
// 	*ptr = '\0';
// 	return (dest);
// }

int	ft_isdigit_spe(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[j][0] == '\0')
		return (0);
	while (str[j])
	{
		if (str[j][0] == '-' || str[j][0] == '+')
			i++;
		while (str[j][i] && str[j][i] >= '0' && str[j][i] <= '9')
			i++;
		if (str[j][i] != '\0')
			return (ft_putendl_fd("error", 2), 0);
		j++;
		i = 0;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_list	*current;
	t_list	*tmp;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(stack);
}

void	free_list(t_list *stack)
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

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * (sizeof(char)));
	if (!str)
		return (free(s1), NULL);
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}

int	ft_isdigit_string(char *str)
{
	int	j;

	j = 0;
	if (str[j] == '\0')
		return (0);
	while (str[j])
	{
		if (str[j] == '-' || str[j] == '+')
			j++;
		while (str[j] && str[j] >= '0' && str[j] <= '9')
			j++;
		if (str[j] != '\0')
			return (0);
	}
	return (1);
}
int	ft_strlen_tab(char **res)
{
	int	i;

	i = 0;
	if (!res)
		return (0);
	while (res[i])
		i++;
	return (i);
}

// void	display_stack(t_stack *lst)
// {
// 	t_list	*current;

// 	current = lst->head;
// 	if (current == NULL)
// 	{
// 		printf("la liste est vide\n");
// 		return ;
// 	}
// 	while (current)
// 	{
// 		printf("[%d]\n", current->content);
// 		current = current->next;
// 	}
// }

// int	ft_lstsize(t_stack *lst)
// {
// 	t_list	*current;
// 	int		i;

// 	i = 0;
// 	current = lst->head;
// 	while (current)
// 	{
// 		current = current->next;
// 		i++;
// 	}
// 	return (i);
// }


