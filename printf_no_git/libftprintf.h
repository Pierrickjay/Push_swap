/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:42:12 by pjay              #+#    #+#             */
/*   Updated: 2023/01/16 14:23:52 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <bsd/string.h>
# include <stddef.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_putnbr_base(unsigned int nbr, char *base, int count);
void	ft_putchar(char c);
void	ft_putnbr_unsigned(unsigned int nb);
int		ft_countnb(int nb);
int		countnb_unsigned(unsigned int nb);
size_t	ft_strlen(const char *str);
void	ft_putnbr_int(int nb);
int		checkptr(uintptr_t p);
int		ft_putchar1(char c);
int		printunsigned(unsigned int d);

#endif
