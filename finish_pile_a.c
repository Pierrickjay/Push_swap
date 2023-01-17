/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_pile_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:05:46 by pjay              #+#    #+#             */
/*   Updated: 2023/01/14 14:53:22 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next(t_tab *tab, int last_pos)
{
	int	next;
	int	i;
	int	pos_higher;
	int	pos_next;

	i = 0;
	pos_next = 0;
	pos_higher = find_lower_pile_a(tab);
	next = tab->pile_a[pos_higher];
	while (i < tab->size_a)
	{
		if (i + last_pos < tab->size_a
			&& tab->pile_a[i + last_pos] < tab->pile_a[last_pos]
			&& tab->pile_a[i + last_pos] > next)
		{
			next = tab->pile_a[i + last_pos];
			pos_next = i + last_pos;
		}
		i++;
	}
	return (pos_next);
}

void	solve_a_test(t_tab *tab)
{
	int	numb_high;
	int	numb_high2;
	int	numb_high3;

	numb_high = tab->pile_a[find_upper_pile_a(tab)];
	numb_high2 = tab->pile_a[find_second_upper_a(tab)];
	numb_high3 = tab->pile_a[find_third_upper_a(tab)];
	while (tab->size_a != 3)
	{
		if (tab->pile_a[0] == numb_high || tab->pile_a[0] == numb_high2
			|| tab->pile_a[0] == numb_high3)
			rev_tab_a(tab->pile_a, tab->size_a);
		else
			push_b(tab);
	}
	solve_3_a(tab->pile_a, tab->size_a);
	while (tab->size_a < tab->size_max)
		find_calc_pos(tab);
	while (check_both_tab(tab) == 0)
		rev_rotate_tab_a(tab->pile_a, tab->size_a);
}
