/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:43:34 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/14 16:19:09 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
// definition de la structure dunode
// typedef struct s_list
// {
// 	int				content;
// 	int				cost;
// 	struct s_list	*target;
// 	struct s_list	*next;
// }					t_list;

typedef struct s_stack
{
	struct s_list	*head;
	int				size;
}					t_stack;

typedef struct s_stacks
{
	struct s_stack	*a;
	struct s_stack	*b;
}					t_stacks;

// Fonctions utilitaires
long				ft_atoi_spe(char *str);
void				free_stack(t_stack *stack);
void				free_list(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_second_last(t_list *head);
int					ft_isdigit_spe(char **str);
char				*ft_strjoin_free(char *s1, char *s2);
int					ft_isdigit_string(char *str);
int					ft_strlen_tab(char **res);

// Fonctions algorithmiques utilitaires
bool				is_sorted(t_stack *stack_a, t_stack *stack_b);
int					determine_index(t_list *node, t_stack *stack);
t_list				*find_top(t_stack *stack);
t_list				*find_low(t_stack *stack);
void				swap(int *x, int *y);
t_stack				*input_count(t_stack *lst);
void				rotate_top(t_list *node, t_stack *stack, t_stacks *both);
t_list				*find_cheapest(t_stack *stack);
void				insert(t_stacks *stack);

// a classer 
void	sort_stack(t_stacks *both, int size,int *tab);
void higher_half_to_b(t_stacks *both,int size,int *tab);
void lowest_half_to_b(t_stacks *both, int size, int *tab);
void sort(t_stacks *both);

// Fonctions de parsing et de vérification
int					*ft_valid(int ac, char **av, t_stack **lst);
char				*ft_input(char **av);
int					ft_check_str(char **res);
char				**ft_parsing(int ac, char **av);

// Fonctions d'initialisation et de manipulation de stack
int					*ft_init_tab(char **res, t_stack *lst);
t_stack				*ft_init_stack(void);
void				add_to_queue(t_stack *lst, int nbr);
t_stack				*stack_size(t_stack *stack);

// Fonctions de tri
void				sort_2(t_stack *stack_a, t_stack *stack_b);
void				sort_3(t_stack *stack_a);
void				sort_array(int *array, int length);
void				quick_sort(int *array, int start, int end);
int					part(int *array, int start, int end);

// Fonctions de calcul de coût
void				cost_all_list(t_stack *stack_a, t_stack *stack_b);
int					cost(t_list *lst, t_stack *stack_a, t_stack *stack_b);
int					cost_top(t_list *lst, t_stack *stack);
t_list				*highest(t_list *lst, t_stack *stack);

// Fonctions de mouvements
void				push_b(t_stack *stack_a, t_stack *stack_b);
void				push_a(t_stack *stack_a, t_stack *stack_b);
void				swap_a(t_stack *a);
void				swap_b(t_stack *b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				rotate_a(t_stack *a);
void				rotate_b(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

// Fonctions d'affichage (pour le débogage)
void				display_stack(t_stack *lst);
void				print_list(t_list *stack);

#endif