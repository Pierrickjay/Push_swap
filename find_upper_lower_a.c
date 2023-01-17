/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_upper_lower_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:17:04 by pjay              #+#    #+#             */
/*   Updated: 2023/01/14 15:34:16 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_upper_pile_a(t_tab *tab)
{
	int	i;
	int	res;
	int	res2;

	i = 0;
	res2 = tab->pile_a[0];
	res = 0;
	while (i < tab->size_a)
	{
		if (tab->pile_a[i] > res2)
		{
			res = i;
			res2 = tab->pile_a[i];
		}
		i++;
	}
	return (res);
}

int	find_second_upper_a(t_tab *tab)
{
	int			i;
	int			res;
	int			res2;
	int			res3;
	static int	compteur = 1;

	if (compteur == 0)
		return (-1);
	res3 = find_upper_pile_a(tab);
	i = 0;
	res = 0;
	res2 = tab->pile_a[find_lower_pile_a(tab)];
	while (i < tab->size_a)
	{
		if (tab->pile_a[i] > res2 && i != res3)
		{
			res = i;
			res2 = tab->pile_a[i];
		}
		i++;
	}
	return (res);
}

int	find_third_upper_a(t_tab *tab)
{
	int			i;
	int			res;
	int			res2;
	static int	compteur = 1;

	if (compteur == 0)
		return (-1);
	i = 0;
	res = 0;
	res2 = tab->pile_a[find_lower_pile_a(tab)];
	while (i < tab->size_a)
	{
		if (tab->pile_a[i] > res2 && i != find_second_upper_a(tab)
			&& i != find_upper_pile_a(tab))
		{
			res = i;
			res2 = tab->pile_a[i];
		}
		i++;
	}
	return (res);
}

int	find_lower_pile_a(t_tab *tab)
{
	int	i;
	int	res;
	int	res2;

	i = 0;
	res = 0;
	res2 = tab->pile_a[0];
	while (i < tab->size_a)
	{
		if (tab->pile_a[i] < res2)
		{
			res = i;
			res2 = tab->pile_a[i];
		}
		i++;
	}
	return (res);
}

int	find_second_lower(t_tab *tab)
{
	int			i;
	int			res;
	int			res2;
	int			res3;
	static int	compteur = 1;

	if (compteur == 0)
		return (-1);
	res3 = find_lower_pile_a(tab);
	i = 0;
	res = 0;
	res2 = tab->pile_a[0];
	while (i < tab->size_a)
	{
		if (tab->pile_a[i] < res2 && i != res3)
		{
			res = i;
			res2 = tab->pile_a[i];
		}
		i++;
	}
	compteur--;
	return (res);
}
