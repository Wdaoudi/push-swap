/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:20:27 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/04 16:43:23 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
    unsigned char *tmp;
    size_t i;
    
    i = 0;
    tmp = malloc(nmemb * size);
    if (!tmp)
        return (NULL);
    while (i < nmemb * size)
        tmp[i++] = 0;
    return (tmp);
}
