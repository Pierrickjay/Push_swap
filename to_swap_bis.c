/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_swap_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:38:16 by pjay              #+#    #+#             */
/*   Updated: 2023/01/17 09:40:00 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_no_w(int *pilea, int size_a)
{
	int	a;

	if (size_a == 0 || size_a == 1)
		return ;
	a = pilea[0];
	pilea[0] = pilea[1];
	pilea[1] = a;
}

void	swap_b_no_w(int *pileb, int size_b)
{
	int	a;

	if (size_b == 0 || size_b == 1)
		return ;
	a = pileb[0];
	pileb[0] = pileb[1];
	pileb[1] = a;
}

void	swap_a_b(t_tab *tab)
{
	swap_b_no_w(tab->pile_b, tab->size_b);
	swap_a_no_w(tab->pile_a, tab->size_a);
	ft_printf("ss\n");
}
