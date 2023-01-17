/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:10:56 by pjay              #+#    #+#             */
/*   Updated: 2023/01/16 14:53:08 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	it_s_finish(t_tab *tab)
{
	while (tab->size_b)
		push_a(tab);
	free_gum(tab);
}

int	check_same_number(int *tab, int size_max, int yes, char **tab_splitt)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	if (yes == 1)
		size_max++;
	while (i < size_max)
	{
		j = -1;
		while (++j < size_max)
			if (tab[i] == tab[j])
				count++;
		if (count >= 2)
			close_everything(tab_splitt, size_max, yes, tab);
		count = 0;
		i++;
	}
	return (0);
}

int	check_tab(t_tab *tab, int size_max)
{
	int	i;

	i = 0;
	while (i < size_max && tab->pile_a[i] <= tab->pile_a[i + 1])
		i++;
	if (i == size_max - 1)
		return (1);
	else
		return (0);
}

int	check_both_tab(t_tab *tab)
{
	int	i;

	i = 0;
	while (i + 1 < tab->size_a && tab->pile_a[i] <= tab->pile_a[i + 1])
		i++;
	i++;
	if (i == tab->size_a)
	{
		i = 0;
		while (i + 1 < tab->size_b && tab->pile_b[i] >= tab->pile_b[i + 1])
			i++;
		if (i == tab->size_b)
		{
			it_s_finish(tab);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int	check_upper_mediane(t_tab *tab, int mediane_b)
{
	int	i;

	i = 0;
	while (i < tab->size_b)
	{
		if (tab->pile_b[i] < mediane_b)
			return (1);
		i++;
	}
	return (0);
}
