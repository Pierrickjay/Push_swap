/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_solve_2_3_6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:30:32 by pjay              #+#    #+#             */
/*   Updated: 2023/01/14 15:31:18 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_2(t_tab *tab, char c)
{
	if (c == 'a')
	{
		if (tab->pile_a[0] > tab->pile_a[1])
			swap_a(tab->pile_a, tab->size_a);
		return ;
	}
	if (c == 'b')
	{
		if (tab->pile_b[0] < tab->pile_b[1])
			swap_b(tab->pile_b, tab->size_b);
		return ;
	}
}

void	solve_3_a(int *pile, int size_pile)
{
	if (pile[0] > pile[1] && pile[0] < pile[2])
		swap_a(pile, size_pile);
	if (pile[0] > pile[1] && pile[0] > pile[2])
		rev_tab_a(pile, size_pile);
	if (pile[2] < pile[1] && pile[2] < pile[0])
		rev_rotate_tab_a(pile, size_pile);
	if (pile[1] > pile[0] && pile[1] > pile[2])
	{
		swap_a(pile, size_pile);
		rev_tab_a(pile, size_pile);
	}
	if (pile[1] < pile[0])
		swap_a(pile, size_pile);
}

void	solve_3_b_reverse(int *pile, int size_pile, t_tab *tab)
{
	if (pile[0] < pile[1] && pile[0] < pile[2])
	{
		rev_tab_b(pile, size_pile);
		if (pile[0] < pile[1])
			swap_b(pile, size_pile);
	}
	if (pile[2] > pile[1] && pile[2] > pile[1])
	{
		if (pile[1] > pile[0])
			swap_b(pile, size_pile);
		rev_rotate_tab_b(pile, size_pile);
	}
	if (pile[1] > pile[0] && pile[1] > pile[2])
	{
		if (pile[0] > pile[2])
		{
			rev_tab_b(tab->pile_b, tab->size_b);
			rev_tab_b(tab->pile_b, tab->size_b);
		}
		if (pile[2] > pile[0])
		{
			swap_b(tab->pile_b, tab->size_b);
			rev_rotate_tab_b(tab->pile_b, tab->size_b);
		}
	}
}

void	solve_6_bis(t_tab *tab)
{
	solve_3_a(tab->pile_a, tab->size_a);
	solve_3_b_reverse(tab->pile_b, tab->size_b, tab);
	push_a(tab);
	push_a(tab);
	push_a(tab);
	free_gum(tab);
}

void	solve_6(t_tab *tab, int size_max)
{
	const int	median = find_median(tab->pile_a, tab->size_a);
	int			i;
	int			count;

	count = size_max;
	i = 0;
	while (tab->size_b != 3)
	{
		if (tab->pile_a[i] > median)
			rev_tab_a(tab->pile_a, tab->size_a);
		if (tab->pile_a[i] <= median)
			push_b(tab);
		if (tab->pile_a[tab->size_a - 1] <= median)
			rev_rotate_tab_a(tab->pile_a, tab->size_a);
		i = 0;
	}
	solve_6_bis(tab);
}
