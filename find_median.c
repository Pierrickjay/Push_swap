/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:23:54 by pjay              #+#    #+#             */
/*   Updated: 2023/01/14 14:02:34 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**create_tab(int size)
{
	int	i;
	int	**save_median;

	i = 0;
	save_median = malloc(sizeof(int *) * size / 2);
	if (!save_median)
		exit(0);
	while (i < size / 2)
	{
		save_median[i] = malloc(sizeof(int) * 2);
		if (!save_median[i])
			exit(0);
		save_median[i][0] = 0;
		save_median[i][1] = -1;
		i++;
	}
	return (save_median);
}

void	fill_array_median(int **save_median, int odds, int size, int *tab)
{
	int	j;
	int	e;
	int	tmp;
	int	pos;
	int	tmp1;

	tmp1 = INT_MIN;
	pos = 0;
	e = -1;
	while (++e < size / 2)
	{
		tmp = find_upper_tab(tab, size);
		j = -1;
		while (++j < size - odds)
			if (!check_pos(save_median, e, j) && !check_if(tab, tmp1, &tmp, j))
				pos = j;
		if (check_median(tmp, pos, save_median, e) == 0)
		{
			fill_save_median(save_median, e, tmp, pos);
			tmp1 = tmp;
		}
	}
}

int	pick_median(int **tab, int size)
{
	int	highest;
	int	i;

	i = 0;
	highest = INT_MIN;
	while (i < size)
	{
		if (tab[i][0] > highest)
			highest = tab[i][0];
		i++;
	}
	return (highest);
}

int	find_median(int *tab, int size)
{
	int	pos;
	int	**save_median;
	int	tmp;
	int	i;

	i = -1;
	pos = 0;
	if (size % 2 != 0)
	{
		size++;
		save_median = create_tab(size);
		fill_array_median(save_median, 1, size, tab);
	}
	else
	{
		save_median = create_tab(size);
		fill_array_median(save_median, 0, size, tab);
	}
	tmp = pick_median(save_median, size / 2);
	while (++i < size / 2)
		free(save_median[i]);
	free(save_median);
	return (tmp);
}

// int main()
// {
// 	int tab[2] =
// 	{8,3};
// 	int compteur = 0;
// 	for (int i = 0; i < 2; i++)
// 		printf("tab[%d] = %d\n", i, tab[i]);
// 	printf("Median de tab est egal a %d \n", find_median(tab,2));
// 	// for (int i = 0; i < 8; i++)
// 	// {
// 	// 	if (tab[i] <= find_median(tab,8))
// 	// 	{
// 	// 		printf("tab[%d] = %d || compteur = %d \n", i, tab[i], compteur);
// 	// 		compteur++;
// 	// 	}
// 	// }
// }
