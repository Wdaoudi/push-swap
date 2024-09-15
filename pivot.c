/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:53:49 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/12 21:33:57 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *array, int lenght)
{
	quick_sort(array, 0, lenght - 1);
}

void	quick_sort(int *array, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = part(array, start, end);
		quick_sort(array, pivot_index + 1, end);
		quick_sort(array, start, pivot_index - 1);
	}
}

int	part(int *array, int start, int end)
{
	int i;
	int j;
	int pivot_value;
	// int temp;
	// temp = 0;
	i = start;
	j = start;
	pivot_value = array[end];
	while (j < end)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[j], &array[i]);
			i++;
		}
		j++;
	}
	swap(&array[i], &array[end]);
	return (i);
}