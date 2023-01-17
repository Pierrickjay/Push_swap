/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_lower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:24:11 by pjay              #+#    #+#             */
/*   Updated: 2023/01/14 15:34:49 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	up_or_down(int pos, int size_tab)
{
	int	i;
	int	j;
	int	u;

	i = 0;
	j = 0;
	u = pos;
	while (i < pos)
		i++;
	while (u < size_tab)
	{
		u++;
		j++;
	}
	if (i < j)
		return (0);
	return (-1);
}

int	pos_higher(t_tab *tab, int size_max)
{
	int	res;
	int	i;
	int	pos;

	i = 0;
	res = 0;
	while (i <= size_max)
	{
		if (tab->pile_a[i] > res)
		{
			res = tab->pile_a[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	find_upper_pile_b(t_tab *tab)
{
	int	i;
	int	res;
	int	res2;

	i = 0;
	res2 = tab->pile_b[0];
	res = 0;
	while (i < tab->size_b)
	{
		if (tab->pile_b[i] > res2)
		{
			res = i;
			res2 = tab->pile_b[i];
		}
		i++;
	}
	return (res);
}

int	find_second_upper_b(t_tab *tab)
{
	int			i;
	int			res;
	int			res2;
	int			res3;
	static int	compteur = 1;

	if (compteur == 0)
		return (-1);
	res3 = find_upper_pile_b(tab);
	i = 0;
	res = 0;
	res2 = tab->pile_b[0];
	while (i < tab->size_b)
	{
		if (tab->pile_b[i] > res2 && i != res3)
		{
			res = i;
			res2 = tab->pile_b[i];
		}
		i++;
	}
	return (res);
}

int	find_second_upper(t_tab *tab)
{
	int			i;
	int			res;
	int			res2;
	int			res3;
	static int	compteur = 1;

	if (compteur == 0)
		return (-1);
	res3 = find_upper_pile_b(tab);
	i = 0;
	res = 0;
	res2 = tab->pile_b[0];
	while (i < tab->size_b)
	{
		if (tab->pile_b[i] > res2 && i != res3)
		{
			res = i;
			res2 = tab->pile_b[i];
		}
		i++;
	}
	return (res);
}
