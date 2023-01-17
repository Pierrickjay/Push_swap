/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:26:43 by pjay              #+#    #+#             */
/*   Updated: 2023/01/14 15:40:56 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**create_tab_a(t_tab *tab, int **tab_pos_b)
{
	int	**tab_pos_a;
	int	i;

	i = 0;
	tab_pos_a = ft_calloc(sizeof(int *), tab->size_b);
	if (!tab_pos_a)
		free_gum_tab(tab, tab_pos_b, tab->size_b);
	while (i < tab->size_b)
	{
		tab_pos_a[i] = ft_calloc(sizeof(int), 2);
		if (!tab_pos_a[i])
			free_gum_tab(tab, tab_pos_b, tab->size_b);
		i++;
	}
	return (tab_pos_a);
}

int	**create_tab_b(t_tab *tab)
{
	int	**tab_cout_b;
	int	i;

	i = 0;
	tab_cout_b = ft_calloc(sizeof(int *), tab->size_b);
	if (!tab_cout_b)
		free_gum(tab);
	while (i < tab->size_b)
	{
		tab_cout_b[i] = ft_calloc(sizeof(int), 2);
		if (!tab_cout_b[i])
			free_gum(tab);
		i++;
	}
	return (tab_cout_b);
}

int	**calc_tab_a(t_tab *tab, int **tab_pos_b)
{
	int	i;
	int	**tab_pos_a;
	int	pos;

	tab_pos_a = create_tab_a(tab, tab_pos_b);
	i = 0;
	while (i < tab->size_b)
	{
		pos = calc_cout(tab, tab->pile_b[i]);
		if (up_or_down(pos, tab->size_a) == 0)
		{
			tab_pos_a[i][0] = calc_rr(pos);
			tab_pos_a[i][1] = 0;
		}
		else
		{
			tab_pos_a[i][0] = calc_rrr(pos, tab->size_a);
			tab_pos_a[i][1] = 1;
		}
		i++;
	}
	return (tab_pos_a);
}

int	**calc_tab_b(t_tab *tab)
{
	int	**tab_cout_b;
	int	i;

	i = 0;
	tab_cout_b = create_tab_b(tab);
	while (i < tab->size_b)
	{
		if (up_or_down(i, tab->size_b) == 0)
		{
			tab_cout_b[i][0] = calc_rr(i);
			tab_cout_b[i][1] = 0;
		}
		else
		{
			tab_cout_b[i][0] = calc_rrr(i, tab->size_b);
			tab_cout_b[i][1] = 1;
		}
		i++;
	}
	return (tab_cout_b);
}

int	find_calc_pos(t_tab *tab)
{
	int	**switch_b;
	int	**switch_a;
	int	pos;

	switch_b = calc_tab_b(tab);
	switch_a = calc_tab_a(tab, switch_b);
	pos = find_pos_better(tab, switch_a, switch_b);
	if (switch_b[pos][1] == 0 && switch_a[pos][1] == 0)
		deal_up(switch_b[pos][0], switch_a[pos][0], tab);
	if (switch_b[pos][1] == 1 && switch_a[pos][1] == 1)
		deal_down(switch_b[pos][0], switch_a[pos][0], tab);
	if (switch_b[pos][1] == 1 && switch_a[pos][1] == 0)
	{
		deal_up(0, switch_a[pos][0], tab);
		deal_down(switch_b[pos][0], 0, tab);
	}
	if (switch_b[pos][1] == 0 && switch_a[pos][1] == 1)
	{
		deal_up(switch_b[pos][0], 0, tab);
		deal_down(0, switch_a[pos][0], tab);
	}
	push_a(tab);
	free_both_tab(switch_a, switch_b, tab->size_b + 1);
	return (0);
}
