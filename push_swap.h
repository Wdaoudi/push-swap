/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:43:34 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/07 19:04:23 by wdaoudi-         ###   ########.fr       */
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

// definition de la structure dunode
// typedef struct s_list
// {
// 	int				content;
// 	int				index;
// 	int				cost;
// 	struct s_list	*target;
// 	struct s_list	*next;
// 	struct s_list	*prev;
// }					t_list;

typedef struct s_stack
{
	struct s_list	*first;
}					t_stack;

// fonction utils
long				ft_atoispe(const char *nptr);
char				*ft_strcat(char *dest, const char *src);
void				free_stack(t_stack *stack);
int					ft_atoi_strict(const char *str, int *error);

// fonction de parsing/check
// char				**parsingcheck(char **str, int ac);
int					check_error(char *str);
int					check(char **str, int ac);
int					check_dup(int *numbers, int count);
int					parse_and_check(char **av, int ac);
int					check_limits(char **parsed);
char				**parse_input(char **av, int ac);

// remplissage de la stack
int					parse_arg(char *arg, int *result, int *number);
int					*parsing_fill(char **str, int ac);
t_stack				*init_stack(int *tab, int size);

// temporaire
// size_t				ft_strlen(const char *str);
// char				*ft_strjoin(char const *s1, char const *s2);
// char				*ft_strdup(const char *s);
// char				**ft_split(char const *s, char c);
// char				**slip(char const *s, char c, char **str);
// int					lenght_word(char const *s, char c, int i);
// int					count_words(char const *s, char c);
// t_list				*ft_lstnew(int content);
 void				print_list(t_stack *stack);
// int					ft_atoi(const char *nptr);
// void				ft_free(char **str);

// test

#endif