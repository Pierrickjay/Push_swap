/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_algo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:29:22 by pjay              #+#    #+#             */
/*   Updated: 2023/01/17 09:40:13 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid_instruction_2(char *str)
{
	int	check;

	check = 0;
	if (ft_strcmp(str, "rr\n"))
		check--;
	if (ft_strcmp(str, "rb\n"))
		check--;
	if (ft_strcmp(str, "ra\n"))
		check--;
	if (ft_strcmp(str, "rr\n"))
		check--;
	if (ft_strcmp(str, "rrb\n"))
		check--;
	if (ft_strcmp(str, "rra\n"))
		check--;
	if (ft_strcmp(str, "rrr\n"))
		check--;
	return (check);
}

void	check_valid_instruction(char *str, t_tab *tab)
{
	int	check;

	check = 0;
	if (ft_strcmp(str, "sa\n"))
		check--;
	if (ft_strcmp(str, "sb\n"))
		check--;
	if (ft_strcmp(str, "ss\n"))
		check--;
	if (ft_strcmp(str, "pa\n"))
		check--;
	if (ft_strcmp(str, "pb\n"))
		check--;
	if (ft_strcmp(str, "rb\n"))
		check--;
	if (ft_strcmp(str, "ra\n"))
		check--;
	if (check + check_valid_instruction_2(str) == -14)
	{
		ft_printf("Error\n");
		free(str);
		get_next_line(0, 1);
		free_gum(tab);
	}
}

void	do_the_ope_2(t_tab *tab, char *str)
{
	if (!ft_strcmp(str, "rr\n"))
		rev_both_tab_no_w(tab);
	if (!ft_strcmp(str, "rb\n"))
		rev_tab_b_no_w(tab->pile_b, tab->size_b);
	if (!ft_strcmp(str, "ra\n"))
		rev_tab_a_no_w(tab->pile_a, tab->size_a);
	if (!ft_strcmp(str, "rrb\n"))
		rev_rotate_tab_no_w(tab->pile_b, tab->size_b);
	if (!ft_strcmp(str, "rra\n"))
		rev_rotate_tab_no_w(tab->pile_a, tab->size_a);
	if (!ft_strcmp(str, "rrr\n"))
		rev_rotate_both_tab_no_w(tab);
}

void	do_the_ope(t_tab *tab, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		swap_a_no_w(tab->pile_a, tab->size_a);
	if (!ft_strcmp(str, "sb\n"))
		swap_b_no_w(tab->pile_b, tab->size_b);
	if (!ft_strcmp(str, "ss\n"))
		swap_a_b(tab);
	if (!ft_strcmp(str, "pa\n"))
		push_a_no_w(tab);
	if (!ft_strcmp(str, "pb\n"))
		push_b_no_w(tab);
	do_the_ope_2(tab, str);
}

void	create_char_array(t_tab *tab)
{
	char	*str;

	str = get_next_line(0, 0);
	while (str)
	{
		check_valid_instruction(str, tab);
		do_the_ope(tab, str);
		free(str);
		str = get_next_line(0, 0);
	}
	check_both_tab_bonus(tab);
}
