/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:43:34 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/26 18:54:19 by wdaoudi-         ###   ########.fr       */
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
	size_t			size;
}					t_stack;
// allias qui permet de simplifier
typedef struct s_stacks
{
	struct s_stack	a;
	struct s_stack	b;
}					t_stacks;

// Fonctions utilitaires
long				ft_atoi_spe(char *str);
void				free_stack(t_stack *stack);
void				free_list(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_second_last(t_list *lst);
int					ft_isdigit_spe(char **str);
char				*ft_strjoin_free(char *s1, char *s2);
int					ft_isdigit_string(char *str);
size_t				ft_strlen_tab(char **res);
void				ft_free_end(long *tab, t_stack *a, t_stack *b);
int					ft_only_space(char *str);

// Fonctions algorithmiques utilitaires
bool				is_sorted(t_stack *stack_a, t_stack *stack_b);
int					determine_index(t_list *node, t_stack *stack);
t_list				*find_top(t_stack *stack);
t_list				*find_low(t_stack *stack);
void				swap(long *x, long *y);
t_stack				*input_count(t_stack *lst);
void				rotate_top(t_list *node, t_stack *stack, t_stacks *both);
t_list				*find_cheapest(t_stack *stack);
void				insert(t_stacks *stack);
int					stack_lenght(t_stack *stack);

// a classer
void				sort_stack(t_stacks *both, int size, long *tab);
void				higher_half_to_b(t_stacks *both, int size, long *tab);
void				lowest_half_to_b(t_stacks *both, int size, long *tab);
void				sort(t_stacks *both);

// Fonctions de parsing et de vérification
long				*ft_valid(int ac, char **av, t_stack *lst, int *valid);
char				*ft_input(char **av);
int					ft_check_str(char **res, int *valid);
char				**ft_parsing(int ac, char **av, int *valid);

// Fonctions d'initialisation et de manipulation de stack
long				*ft_init_tab(char **res, t_stack *lst, int *valid);
t_stack				*ft_init_stack(void);
void				add_to_queue(t_stack *lst, int nbr);
t_stack				*stack_size(t_stack *stack);

// Fonctions de tri
void				sort_2(t_stack *stack_a, t_stack *stack_b);
void				sort_3(t_stack *stack_a);
void				sort_array(long *array, int length);
void				quick_sort(long *array, int start, int end);
int					part(long *array, int start, int end);

// Fonctions de calcul de coût
void				cost_all_list(t_stack *stack_a, t_stack *stack_b);
int					cost(t_list *lst, t_stack *stack_a, t_stack *stack_b);
int					cost_top(t_list *lst, t_stack *stack);
t_list				*highest(t_list *lst, t_stack *stack);
void				get_target(t_stack *stack_a, t_list *node);

// Fonctions de mouvements
void				push_b(t_stack *stack_a, t_stack *stack_b);
void				push_a(t_stack *stack_a, t_stack *stack_b);
void				swap_lst(t_stack *stack);
void				swap_a(t_stack *a);
void				swap_b(t_stack *b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				rotate(t_stack *stack);
void				rotate_a(t_stack *a);
void				rotate_b(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				reverse_rotate(t_stack *stack);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

// reduction du main 
//(non necessaire car declarer en static locale sur le fichier)
// static void			initialize_stacks(t_stacks *stack);
// static int			handle_small_sorts(t_stacks *stack, long *tab);
// static int			process_input(int ac, char **av, t_stacks *stack,
// 						long **tab);
// static void			fill_stack_a(t_stack *stack_a, long *tab);

// Fonctions d'affichage (pour le débogage)
// void				display_stack(t_stack *lst);
// void				print_list(t_list *stack);
// void	print_list2(t_stacks stack);
void				print_targets(t_stack *stack_a, t_stack *stack_b);
void				print_costs(t_stack *stack_a, t_stack *stack_b);

#endif