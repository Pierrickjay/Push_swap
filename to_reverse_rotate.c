/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:01:31 by pjay              #+#    #+#             */
/*   Updated: 2023/01/17 09:40:37 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_tab_a(int *tab, int size)
{
	int	i;

	if (size == 0)
	{
		ft_printf("rra\n");
		return ;
	}
	i = tab[size - 1];
	moove_down(tab, size);
	tab[0] = i;
	tab[size] = 0;
	ft_printf("rra\n");
}

void	rev_rotate_tab_b(int *tab, int size)
{
	int	i;

	if (size == 0)
	{
		ft_printf("rrb\n");
		return ;
	}
	i = tab[size - 1];
	moove_down(tab, size);
	tab[0] = i;
	tab[size] = 0;
	ft_printf("rrb\n");
}

void	rev_rotate_tab_no_w(int *tab, int size)
{
	int	i;

	if (size == 0)
		return ;
	i = tab[size - 1];
	moove_down(tab, size);
	tab[0] = i;
	tab[size] = 0;
}

void	rev_rotate_both_tab(t_tab *tab)
{
	rev_rotate_tab_no_w(tab->pile_a, tab->size_a);
	rev_rotate_tab_no_w(tab->pile_b, tab->size_b);
	ft_printf("rrr\n");
}

void	rev_rotate_both_tab_no_w(t_tab *tab)
{
	rev_rotate_tab_no_w(tab->pile_a, tab->size_a);
	rev_rotate_tab_no_w(tab->pile_b, tab->size_b);
}
