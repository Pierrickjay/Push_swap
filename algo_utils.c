/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:52:41 by pjay              #+#    #+#             */
/*   Updated: 2023/01/14 14:47:19 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_diff(int numb, int numb2)
{
	int	count;

	count = 0;
	while (numb < numb2)
	{
		numb++;
		count++;
	}
	return (count);
}

int	calc_rr(int pos)
{
	int	i;

	i = 0;
	while (pos > 0)
	{
		pos--;
		i++;
	}
	return (i);
}

int	calc_rrr(int pos, int size_tab)
{
	int	j;
	int	u;

	j = 0;
	u = pos;
	while (u < size_tab)
	{
		u++;
		j++;
	}
	return (j);
}

int	calc_cout(t_tab *tab, int number)
{
	int	i;
	int	save_pos;
	int	check;

	check = tab->pile_a[find_upper_pile_a(tab)];
	i = 0;
	save_pos = 0;
	while (i < tab->size_a)
	{
		if (number < tab->pile_a[i]
			&& check_diff(number, tab->pile_a[i]) < check_diff(number, check))
		{
			check = tab->pile_a[i];
			save_pos = i;
		}
		i++;
	}
	if (check == tab->pile_a[find_upper_pile_a(tab)])
		save_pos = find_upper_pile_a(tab);
	return (save_pos);
}

int	calc_pos_b(t_tab *tab, int number)
{
	int	i;
	int	save_pos;

	i = 0;
	save_pos = 0;
	while (i < tab->size_b)
	{
		if (number > tab->pile_b[i])
			save_pos = i + 1;
		i++;
	}
	return (save_pos);
}
