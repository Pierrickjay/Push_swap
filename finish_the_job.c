/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_the_job.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:12:00 by pjay              #+#    #+#             */
/*   Updated: 2023/01/14 15:33:33 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos_better(t_tab *tab, int **tab_pos_a, int **tab_pos_b)
{
	int	i;
	int	less_pos;
	int	pos;

	pos = 0;
	less_pos = tab_pos_a[0][0] + tab_pos_b[0][0];
	i = 0;
	while (i < tab->size_b)
	{
		if ((tab_pos_a[i][0] + tab_pos_b[i][0]) < less_pos)
		{
			less_pos = tab_pos_a[i][0] + tab_pos_b[i][0];
			pos = i;
		}
		i++;
	}
	return (pos);
}
