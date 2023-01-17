/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:07:21 by pjay              #+#    #+#             */
/*   Updated: 2023/01/17 09:38:43 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *pilea, int size_a)
{
	int	a;

	if (size_a == 0 || size_a == 1)
		return ;
	a = pilea[0];
	pilea[0] = pilea[1];
	pilea[1] = a;
	ft_printf("sa\n");
}

void	swap_b(int *pileb, int size_b)
{
	int	a;

	if (size_b == 0 || size_b == 1)
		return ;
	a = pileb[0];
	pileb[0] = pileb[1];
	pileb[1] = a;
	ft_printf("sb\n");
}
