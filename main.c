/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:38:25 by pjay              #+#    #+#             */
/*   Updated: 2023/01/16 19:38:25 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int ac, char **av)
{
	int	i;
	int	a;

	i = -1;
	a = 0;
	while (++a < ac)
	{
		i = -1;
		while (av[a][++i])
		{
			if (!(av[a][i] >= '0' && av[a][i] <= '9') && av[a][i] != ' ')
			{
				if (!(i == 0 && (av[a][i] == '-' || av[a][i] == '+')))
				{
					write(1, "Error\n", 6);
					return (0);
				}
			}
		}
	}
	return (1);
}

int	check_args_split(int ac, char **av)
{
	int	i;
	int	a;

	i = -1;
	a = 0;
	while (++a < ac)
	{
		i = -1;
		while (av[a][++i])
		{
			if (!(av[a][i] >= '0' && av[a][i] <= '9') && av[a][i] != ' ')
			{
				if (!(i == 0 && (av[a][i] == '-' || av[a][i] == '+')))
				{
					if (!(av[a][i - 1] == ' '))
					{
						write(1, "Error\n", 6);
						return (0);
					}
				}
			}
		}
	}
	return (1);
}

int	count_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	t_tab	tab;

	tab.yes = 0;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (check_args_split(ac, av))
		{
			tab.splitted = ft_split(av[1], ' ');
			tab.yes = 1;
			atoitab(count_split(tab.splitted), tab.splitted, &tab, tab.yes);
		}
	}
	else
	{
		if (check_args(ac, av) == 0)
			return (0);
		atoitab(ac - 1, av, &tab, tab.yes);
	}
	return (0);
}
