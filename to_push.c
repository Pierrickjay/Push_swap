/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:14:27 by pjay              #+#    #+#             */
/*   Updated: 2023/01/14 15:10:58 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_tab *tab)
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
	ft_printf("pb\n");
}

void	push_a(t_tab *tab)
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
	ft_printf("pa\n");
}

void	moove_up(int *pile, int size_pile)
{
	int	i;

	i = 0;
	if (size_pile == 1)
		return ;
	while (i < size_pile - 1)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	pile[i] = 0;
}

void	moove_down(int *pile, int size_pile)
{
	int	i;

	i = size_pile;
	while (i > 0)
	{
		pile[i] = pile[i - 1];
		i--;
	}
	pile[i] = 0;
}
