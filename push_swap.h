/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:43:34 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/05 15:35:59 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// definition de la structure du node
typedef struct s_list
{
	int				content;
	int				index;
	int				cost;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_stack
{
	struct s_list	*first;
}					t_stack;

// temporaire
// size_t				ft_strlen(const char *str);
// char				*ft_strjoin(char const *s1, char const *s2);
// char				*ft_strdup(const char *s);
// char				**ft_split(char const *s, char c);
// char				**slip(char const *s, char c, char **str);
// int					lenght_word(char const *s, char c, int i);
// int					count_words(char const *s, char c);

// fonction utils
long				ft_atoispe(const char *nptr);
char				*ft_strcat(char *dest, const char *src);

// fonction de parsing/check
char				**parsing(char **str, int ac);
int					check_error(char *str);
int					check_lim(int nbr);
int					check(char **str, int ac);

// test
int					check(char **str, int ac);
int					parse_and_check(char **str, int ac);
int					check_limits(char **parsed);
int					free_parsed(char **parsed);

#endif