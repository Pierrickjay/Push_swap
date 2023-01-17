/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:46:41 by pjay              #+#    #+#             */
/*   Updated: 2023/01/17 09:42:53 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atoitab(int size_all, char **av, t_tab *tab, int yes)
{
	int	i;

	i = -1;
	tab->size_max = size_all;
	tab->pile_a = ft_map(av, size_all, &ft_atoi, tab);
	if (!tab->pile_a)
	{
		free(tab);
		exit(0);
	}
	tab->pile_b = ft_calloc(sizeof(int), size_all + 1);
	if (yes == 1)
		free_tab(av, size_all);
	if (!(tab->pile_b))
	{
		free(tab->pile_a);
		exit(0);
	}
	tab->size_a = size_all;
	tab->size_b = 0;
	create_char_array(tab);
}

void	show_tab(t_tab *tab, int size_all)
{
	int	i;

	i = 0;
	ft_printf("a  				b\n");
	while (i < size_all)
	{
		ft_printf("%d  				%d\n", tab->pile_a[i], tab->pile_b[i]);
		i++;
	}
}

int	*ft_map(char **split, int length, int (f)(char *, t_tab *tab, int *),
			t_tab *tab)
{
	int	i;
	int	*array;
	int	a;

	array = ft_calloc(sizeof(int), length + 1);
	if (!array)
	{
		if (tab->yes == 1)
			free_tab(tab->splitted, length);
		exit(0);
	}
	i = 0;
	if (tab->yes == 1)
	{
		i = -1;
		length--;
	}
	a = -1;
	while (++i <= length)
		array[++a] = f(split[i], tab, array);
	check_same_number(array, length, tab->yes, tab->splitted);
	return (array);
}

int	ft_atoi_2(char *nptr, int i, t_tab *tab, int *array)
{
	unsigned int	result;

	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (ft_strlen(nptr) > 10 || (result > 2147483648))
		{
			ft_printf("here\n ?");
			ft_printf("Error\n");
			if (tab->yes == 1)
				free_tab(tab->splitted, count_split(tab->splitted));
			free(array);
			exit(0);
		}
		i++;
	}
	return (result);
}

int	ft_atoi(char *nptr, t_tab *tab, int *array)
{
	int				i;
	int				res;
	unsigned int	result;

	result = 0;
	res = 1;
	i = 0;
	if (ft_strcmp(nptr, "-2147483648") == 0)
		return (-2147483648);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			res *= -1;
		i++;
	}
	return (ft_atoi_2(nptr, i, tab, array) * res);
}
