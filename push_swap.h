/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:43:34 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/02 16:16:46 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// # include "./libft/libft.h"
// # include "./printf/ft_printf.h"

// definition de la structure du node
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;
//voir si il est necessaire de definir une structure stack 
typedef struct stack
{
    
}t_stack;

#endif