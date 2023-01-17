/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_deal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:21:33 by pjay              #+#    #+#             */
/*   Updated: 2023/01/14 10:22:06 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deal_up(int count_b, int count_a, t_tab *tab)
{
	while (count_b && count_a)
	{
		rev_both_tab(tab);
		count_a--;
		count_b--;
	}
	if (count_a || count_b)
	{
		while (count_a)
		{
			rev_tab_a(tab->pile_a, tab->size_a);
			count_a--;
		}
		while (count_b)
		{
			rev_tab_b(tab->pile_b, tab->size_b);
			count_b--;
		}
	}
}

void	deal_down(int count_b, int count_a, t_tab *tab)
{
	while (count_b && count_a)
	{
		rev_rotate_both_tab(tab);
		count_a--;
		count_b--;
	}
	if (count_b || count_a)
	{
		while (count_a)
		{
			rev_rotate_tab_a(tab->pile_a, tab->size_a);
			count_a--;
		}
		while (count_b)
		{
			rev_rotate_tab_b(tab->pile_b, tab->size_b);
			count_b--;
		}
	}
}
