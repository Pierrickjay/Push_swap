/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:53:46 by pjay              #+#    #+#             */
/*   Updated: 2023/01/17 09:33:21 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_gum(t_tab *tab)
{
	free(tab->pile_a);
	free(tab->pile_b);
	exit(0);
}

void	free_tab(char **splitted, int size)
{
	int	i;

	i = -1;
	while (++i <= size)
		free(splitted[i]);
	free(splitted);
}

void	free_gum_tab(t_tab *tab, int **tab_free, int size_tab)
{
	int	i;

	i = 0;
	while (i < size_tab)
	{
		free(tab_free[i]);
		i++;
	}
	free(tab_free);
	free_gum(tab);
}

void	free_both_tab(int **tab_a, int **tab_b, int size_tab)
{
	int	i;

	i = 0;
	while (i < size_tab)
	{
		free(tab_a[i]);
		free(tab_b[i]);
		i++;
	}
	free(tab_a);
	free(tab_b);
}

void	close_everything(char **tab_splitt, int size_max, int yes, int *tab)
{
	ft_printf("Error\n");
	if (yes == 1)
		free_tab(tab_splitt, size_max);
	free(tab);
	exit(0);
}
