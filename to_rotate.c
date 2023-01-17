/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:14:17 by pjay              #+#    #+#             */
/*   Updated: 2023/01/17 09:35:44 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_tab_a(int *tab, int size_pile)
{
	int	i;

	if (size_pile == 0)
	{
		ft_printf("ra\n");
		return ;
	}
	i = tab[0];
	moove_up(tab, size_pile);
	tab[size_pile - 1] = i;
	ft_printf("ra\n");
}

void	rev_tab_a_no_w(int *tab, int size_pile)
{
	int	i;

	if (size_pile == 0)
		return ;
	i = tab[0];
	moove_up(tab, size_pile);
	tab[size_pile - 1] = i;
}

void	rev_tab_b(int *tab, int size_pile)
{
	int	i;

	if (size_pile == 0)
	{
		ft_printf("rb\n");
		return ;
	}
	i = tab[0];
	moove_up(tab, size_pile);
	tab[size_pile - 1] = i;
	ft_printf("rb\n");
}

void	rev_tab_b_no_w(int *tab, int size_pile)
{
	int	i;

	if (size_pile == 0)
		return ;
	i = tab[0];
	moove_up(tab, size_pile);
	tab[size_pile - 1] = i;
}

void	rev_both_tab(t_tab *tab)
{
	rev_tab_a_no_w(tab->pile_a, tab->size_a);
	rev_tab_b_no_w(tab->pile_b, tab->size_b);
	ft_printf("rr\n");
}
