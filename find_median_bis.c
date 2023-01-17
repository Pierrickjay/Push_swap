/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:49:55 by pjay              #+#    #+#             */
/*   Updated: 2023/01/14 15:31:42 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_upper_tab(int *tab, int size)
{
	int	i;
	int	res;
	int	res2;

	i = 0;
	res2 = tab[0];
	res = 0;
	while (i < size - 1)
	{
		if (tab[i] > res2)
		{
			res = i;
			res2 = tab[i];
		}
		i++;
	}
	return (res2);
}

int	check_median(int tmp, int pos, int **save_median, int size_array)
{
	int	i;

	i = 0;
	while (i <= size_array / 2)
	{
		if (save_median[i][0] == tmp && pos == save_median[i][1])
			return (1);
		i++;
	}
	return (0);
}

int	check_pos(int **save_median, int size, int pos)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pos == save_median[i][1])
			return (1);
		i++;
	}
	return (0);
}

void	fill_save_median(int **save_median, int e, int tmp, int pos)
{
	save_median[e][0] = tmp;
	save_median[e][1] = pos;
}

int	check_if(int *tab, int tmp1, int *tmp, int j)
{
	if (tab[j] >= tmp1 && tab[j] < *tmp)
	{
		*tmp = tab[j];
		return (0);
	}
	else
		return (1);
}
