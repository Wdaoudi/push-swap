/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temporaire.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:12:48 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/13 01:18:13 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	k;
// 	char	*str;

// 	k = 0;
// 	i = 0;
// 	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!str)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		str[k] = s1[i];
// 		k++;
// 		i++;
// 	}
// 	i = 0;
// 	while (s2[i])
// 	{
// 		str[k] = s2[i];
// 		k++;
// 		i++;
// 	}
// 	str[k] = 0;
// 	return (str);
// }

// int	ft_isspace(int c)
// {
// 	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
// 		|| c == '\r');
// }

// char	*ft_strdup(const char *s)
// {
// 	size_t	i;
// 	char	*dest;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	dest = malloc(sizeof(char) * (i + 1));
// 	if (!dest)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		dest[i] = s[i];
// 		i++;
// 	}
// 	dest[i] = 0;
// 	return (dest);
// }

// int	count_words(char const *s, char c)
// {
// 	size_t	i;
// 	int		n;

// 	i = 0;
// 	n = 0;
// 	while (s[i])
// 	{
// 		while (s[i] && s[i] == c)
// 			i++;
// 		if (s[i] && s[i] != c)
// 		{
// 			n++;
// 			while (s[i] && s[i] != c)
// 				i++;
// 		}
// 	}
// 	return (n);
// }

// int	lenght_word(char const *s, char c, int i)
// {
// 	int	n;

// 	n = 0;
// 	while (s[i + n] != c && s[i + n])
// 		n++;
// 	return (n);
// }

// void	ft_free(char **str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return ;
// 	while (str[i])
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// 	return ;
// }

// char	**slip(char const *s, char c, char **str)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	k;

// 	i = 0;
// 	j = 0;
// 	while (s[i] == c && s[i])
// 		i++;
// 	while (s[i])
// 	{
// 		k = 0;
// 		str[j] = malloc((lenght_word(s, c, i) + 1) * sizeof(char));
// 		if (str[j] == NULL)
// 			return (ft_free(str), NULL);
// 		while (s[i] && s[i] != c)
// 			str[j][k++] = s[i++];
// 		str[j][k] = 0;
// 		while (s[i] == c && s[i])
// 			i++;
// 		j++;
// 	}
// 	str[j] = NULL;
// 	return (str);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**str;

// 	if (!s)
// 		return (NULL);
// 	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
// 	if (str == NULL)
// 		return (str);
// 	if (!slip(s, c, str))
// 		ft_free(str);
// 	return (str);
// }
// int	ft_atoi(const char *nptr)
// {
// 	int	nbr;
// 	int	i;
// 	int	signe;

// 	i = 0;
// 	signe = 1;
// 	nbr = 0;
// 	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
// 		i++;
// 	if (nptr[i] == 45)
// 	{
// 		signe = -signe;
// 		i++;
// 	}
// 	else if (nptr[i] == 43)
// 		i++;
// 	while (nptr[i] >= 48 && nptr[i] <= 57)
// 	{
// 		nbr = (nbr * 10) + nptr[i] - '0';
// 		i++;
// 	}
// 	return (nbr * signe);
// }

// t_list	*ft_lstnew(int content)
// {
// 	t_list	*new;

// 	new = malloc(sizeof(t_list));
// 	if (!new)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }

void	print_list(t_list *stack)
{
	t_list *current;

	current = stack; // Pointeur pour parcourir la liste
	// Vérifier si la liste est vide
	if (current == NULL)
	{
		printf("La liste est vide.\n");
		return ;
	}
	// Parcourir la liste jusqu'à la fin
	while (current != NULL)
	{
		printf("Content: %d\n", current->content);
		current = current->next;// Passer au nœud suivant
	}
}
// long	ft_atol(char *str)
// {
// 	long	result;
// 	int		sign;

// 	result = 0;
// 	sign = 1;
// 	while ((*str))
// 		str++;
// 	if (*str == '-' || *str == '+')
// 	{
// 		if (*str == '-')
// 			sign = -1;
// 		str++;
// 	}
// 	while (ft_isdigit(*str))
// 	{
// 		result = result * 10 + (*str - '0');
// 		str++;
// 	}
// 	return (result * sign);
// }

// int	ft_isdigit(int c)
// {
// 	if (c >= 48 && c <= 57)
// 		return (1);
// 	else
// 		return (0);
// }