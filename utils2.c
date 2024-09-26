/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:26:35 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/26 18:39:10 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if ((str[j] == '-' || str[j] == '+') && str[j + 1])
			j++;
		while (str[j] && str[j] >= '0' && str[j] <= '9')
			j++;
		if (str[j] != '\0')
			return (0);
	}
	return (1);
}

size_t	ft_strlen_tab(char **res)
{
	size_t	i;

	i = 0;
	if (!res)
		return (0);
	while (res[i])
		i++;
	return (i);
}

void	get_target(t_stack *stack_a, t_list *node)
{
	t_list		*current;
	t_list		*target;
	long long	min_diff;
	long long	diff;

	current = stack_a->head;
	target = NULL;
	min_diff = LLONG_MAX;
	while (current != NULL)
	{
		if (current->content > node->content)
		{
			diff = (long long)current->content - node->content;
			if (diff < min_diff)
			{
				min_diff = diff;
				target = current;
			}
		}
		current = current->next;
	}
	if (!target)
		target = find_low(stack_a);
	node->target = target;
}
