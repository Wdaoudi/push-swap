/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:58:36 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/17 17:59:28 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	size_t	i;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}

int	lenght_word(char const *s, char c, int i)
{
	int	n;

	n = 0;
	while (s[i + n] != c && s[i + n])
		n++;
	return (n);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ;
}

char	**slip(char const *s, char c, char **str)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		k = 0;
		str[j] = malloc((lenght_word(s, c, i) + 1) * sizeof(char));
		if (str[j] == NULL)
			return (ft_free(str), NULL);
		while (s[i] && s[i] != c)
			str[j][k++] = s[i++];
		str[j][k] = 0;
		while (s[i] == c && s[i])
			i++;
		j++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (str == NULL)
		return (str);
	if (!slip(s, c, str))
		return (NULL);
	return (str);
}

// int	main(void)
// {
// 	char **result;
// 	int i;

// 	result = ft_split("tripouille", 0);
// 	if (result)
// 	{
// 		for (i = 0; result[i] != NULL; i++)
// 		{
// 			printf("result[%d]: %s\n", i, result[i]);
// 		}
// 		for (i = 0; result[i] != NULL; i++)
// 		{
// 			free(result[i]);
// 		}
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("ft_split a retourné NULL\n");
// 	}
// 	return (0);
// }