/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_solve_bigger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:16:42 by pjay              #+#    #+#             */
/*   Updated: 2023/01/16 13:55:19 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_rrr(t_tab *tab, int mediane_a, int mediane_b)
{
	while (tab->pile_a[0] > mediane_a && tab->pile_b[0] <= mediane_b
		&& tab->size_a < tab->size_max / 2 && tab->size_b <= tab->size_max / 2)
		rev_both_tab(tab);
	while (tab->pile_a[tab->size_a - 1] <= mediane_a
		&& tab->pile_b[tab->size_b - 1] > mediane_b
		&& tab->size_a < tab->size_max / 2 && tab->size_b <= tab->size_max / 2)
		rev_rotate_both_tab(tab);
	while (tab->pile_a[0] > tab->pile_a[1] && tab->pile_b[1] > tab->pile_b[0])
		swap_a_b(tab);
}

void	swap_2nd_part_b(t_tab *tab, int mediane_a)
{
	int	mediane_b;

	mediane_b = mediane_a;
	mediane_b = find_median(tab->pile_b, tab->size_b);
	show_tab(tab, tab->size_max);
}

void	swap_rr_rra(t_tab *tab, int mediane, int precision)
{
	int	i;

	i = 0;
	while (tab->pile_a[0] >= mediane
		&& tab->size_b + precision < tab->size_max / 2 - 1)
	{
		rev_tab_a(tab->pile_a, tab->size_a);
		if (tab->pile_a[0] < mediane)
			push_b(tab);
	}
	if (tab->pile_a[0] < mediane)
		push_b(tab);
}

void	to_solve_big(t_tab *tab)
{
	int	mediane_a;
	int	precision;
	int	compteur;

	compteur = 0;
	precision = 0;
	if (tab->size_max % 2 != 0)
		precision = 1;
	mediane_a = find_median(tab->pile_a, tab->size_a);
	while (compteur < tab->size_max / 2)
	{
		swap_rr_rra(tab, mediane_a, precision);
		compteur++;
	}
	solve_a_test(tab);
	check_both_tab(tab);
}
