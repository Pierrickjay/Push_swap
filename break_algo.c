/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:44:50 by pjay              #+#    #+#             */
/*   Updated: 2023/01/17 09:27:04 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	break_algo(t_tab *tab, int size_max)
{
	if (check_tab(tab, size_max) != 1)
	{
		if (size_max == 2)
			solve_2(tab, 'a');
		if (size_max == 3)
			solve_3_a(tab->pile_a, tab->size_a);
		if (size_max == 6)
			solve_6(tab, size_max);
		if (size_max > 3)
			to_solve_big(tab);
		free_gum(tab);
	}
	free_gum(tab);
}
