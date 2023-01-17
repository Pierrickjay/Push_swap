/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:53:05 by pjay              #+#    #+#             */
/*   Updated: 2023/01/17 09:35:21 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "printf_no_git/libftprintf.h"
# include "get_next_line/get_next_line_bonus.h"

typedef struct s_tab
{
	int		*pile_a;
	int		*pile_b;
	int		size_max;
	int		size_a;
	int		size_b;
	int		yes;
	char	**splitted;
}t_tab;

void	push_b(t_tab *tab);
void	push_a(t_tab *tab);
void	moove_up(int *pile, int size_pile);
int		ft_atoi(char *nptr, t_tab *tab, int *array);
int		*ft_map(char **split, int length, int (f)(char *, t_tab *tab, int *),
			t_tab *tab);
void	atoitab(int ac, char **av, t_tab *tab, int yes);
void	swap_b(int *pileb, int size_b);
void	swap_a(int *pilea, int size_a);
void	swap_b_no_w(int *pileb, int size_b);
void	swap_a_no_w(int *pilea, int size_a);
void	swap_a_b(t_tab *tab);
void	show_tab(t_tab *tab, int ac);
void	moove_down(int *pile, int size_pile);
void	rev_tab_a(int *tab, int size_pile);
void	rev_tab_b(int *tab, int size_pile);
void	rev_tab_a_no_w(int *tab, int size_pile);
void	rev_tab_b_no_w(int *tab, int size_pile);
void	rev_both_tab(t_tab *tab);
void	rev_rotate_tab_a(int *tab, int size_pile);
void	rev_rotate_tab_b(int *tab, int size_pile);
void	rev_rotate_tab_no_w(int *tab, int size);
void	rev_rotate_both_tab(t_tab *tab);
void	break_algo(t_tab *tab, int size_max);
void	solve_2(t_tab *tab, char c);
void	solve_3_a(int *pile, int size_pile);
void	solve_3_b_reverse(int *pile, int size_pile, t_tab *tab);
void	solve_4(t_tab *tab, int size_max);
void	solve_4_bis(t_tab *tab, int pos);
void	solve_6(t_tab *tab, int size_max);
void	solve_6_bis(t_tab *tab);
void	solve_5(t_tab *tab, int size_max);
void	solve_5_ter(t_tab *tab, int size_max);
void	solve_5_bis(t_tab *tab);
void	solve_5_quarter(t_tab *tab, int size_max);
int		check_tab(t_tab *tab, int size_max);
void	array_mixer(t_tab *tab, int index);
void	array_mixer_b(t_tab *tab, int index);
int		calc_moyenne(t_tab *tab, int size_max);
void	fill_array(t_tab *tab);
void	fill_array_2(t_tab *tab);
int		pos_higher(t_tab *tab, int size_max);
char	**ft_split(char const *s, char c);
int		find_lower_pile_a(t_tab *tab);
int		find_second_lower(t_tab *tab);
int		find_upper_pile_a(t_tab *tab);
int		find_upper_pile_b(t_tab *tab);
int		find_second_upper(t_tab *tab);
int		find_upper_tab(int *tab, int size);
void	free_gum(t_tab *tab);
int		find_median(int *tab, int size);
int		check_median(int tmp, int pos, int **save_median, int size_array);
int		check_pos(int **save_median, int size, int pos);
int		check_if(int *tab, int tmp1, int *tmp, int j);
void	fill_save_median(int **save_median, int e, int tmp, int pos);
int		fill_array_median_bis(int tab, int e, int tmp1, int size);
void	to_solve_big(t_tab *tab);
int		check_both_tab(t_tab *tab);
int		check_same_number(int *tab, int size_max, int yes, char **tab_splitt);
void	*ft_calloc(size_t nmemb, size_t size);
void	free_tab(char **splitted, int size);
void	it_s_finish(t_tab *tab);
int		check_upper_mediane(t_tab *tab, int mediane_b);
void	fill_push_b(t_tab *tab, int compteur);
void	array_mixer_b(t_tab *tab, int index);
int		up_or_down(int pos, int size_tab);
int		check_place_b(t_tab *tab, int size_tab, int pos);
void	solve_a(t_tab *tab);
void	solve_a_test(t_tab *tab);
void	array_mixer_test(t_tab *tab, int index);
int		find_second_upper_b(t_tab *tab);
int		find_second_upper_a(t_tab *tab);
int		find_third_upper_a(t_tab *tab);
int		**calc_tab_b(t_tab *tab);
int		find_calc_pos(t_tab *tab);
void	finish_the_job_a(t_tab *tab, int pos);
void	finish_the_job_b(t_tab *tab, int pos);
int		find_pos_better(t_tab *tab, int **tab_pos_a, int **tab_pos_b);
void	free_gum_tab(t_tab *tab, int **tab_free, int size_tab);
int		calc_rr(int pos);
int		calc_rrr(int pos, int size_tab);
int		calc_cout(t_tab *tab, int number);
int		calc_pos(t_tab *tab, int number);
int		calc_pos_b(t_tab *tab, int number);
void	free_both_tab(int **tab_a, int **tab_b, int size_tab);
void	deal_up(int count_b, int count_a, t_tab *tab);
void	deal_down(int count_b, int count_a, t_tab *tab);
void	close_everything(char **tab_splitt, int size_max, int yes, int *tab);
int		count_split(char **split);

/*							Get next line								*/
char	*get_next_line(int fd, int tbool);
char	*creatit(char *str);
char	*savetheend(char *str);

/*							Bonus										*/

void	create_char_array(t_tab *tab);
int		ft_strcmp(char *s1, char *s2);
void	check_both_tab_bonus(t_tab *tab);
void	rev_rotate_both_tab_no_w(t_tab *tab);
void	rev_both_tab_no_w(t_tab *tab);
void	swap_a_b_no_w(t_tab *tab);
void	push_b_no_w(t_tab *tab);
void	push_a_no_w(t_tab *tab);
#endif
