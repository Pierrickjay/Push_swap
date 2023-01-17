/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_algo_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:08:35 by pjay              #+#    #+#             */
/*   Updated: 2023/01/16 18:56:02 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_no_w(t_tab *tab)
{
	if (tab->size_a == 0)
		return ;
	if (tab->size_b != 0)
		moove_down(tab->pile_b, tab->size_b);
	tab->pile_b[0] = tab->pile_a[0];
	if (tab->size_a == 1)
		tab->pile_a[0] = 0;
	moove_up(tab->pile_a, tab->size_a);
	tab->size_a--;
	tab->size_b++;
}

void	push_a_no_w(t_tab *tab)
{
	if (tab->size_b == 0)
		return ;
	if (tab->size_a != 0)
		moove_down(tab->pile_a, tab->size_a);
	tab->pile_a[0] = tab->pile_b[0];
	if (tab->size_b == 1)
		tab->pile_b[0] = 0;
	moove_up(tab->pile_b, tab->size_b);
	tab->size_a++;
	tab->size_b--;
}

void	rev_both_tab_no_w(t_tab *tab)
{
	rev_tab_a_no_w(tab->pile_a, tab->size_a);
	rev_tab_b_no_w(tab->pile_b, tab->size_b);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	check_both_tab_bonus(t_tab *tab)
{
	int	i;

	i = 0;
	while (i + 1 < tab->size_a && tab->pile_a[i] <= tab->pile_a[i + 1])
		i++;
	i++;
	if (i == tab->size_max)
	{
		ft_printf("OK\n");
		free_gum(tab);
	}
	else
	{
		ft_printf("KO\n");
		free_gum(tab);
	}
}
