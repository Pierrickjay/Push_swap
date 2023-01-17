
CC=clang
CFLAGS=-Wall -Werror -Wextra -g3
INCLUDE= printf_no_git/libftprintf.a
SRC=init_tab.c \
	to_swap.c \
	to_push.c \
	to_rotate.c \
	to_reverse_rotate.c \
	to_solve_2_3_6.c \
	main.c \
	checker_tab.c \
	upper_lower.c \
	free.c \
	ft_split.c \
	find_median.c \
	find_median_bis.c \
	to_solve_bigger.c \
	break_algo.c \
	ft_calloc.c \
	finish_pile_a.c \
	algo.c \
	finish_the_job.c \
	algo_utils.c \
	to_deal.c \
	find_upper_lower_a.c \
	checker_algo_utils_bonus.c \
	to_swap_bis.c \

SRCBONUS=init_tab_bonus.c \
	checker_bonus.c \
	checker_algo_bonus.c \
	checker_algo_utils_bonus.c \
	to_swap.c \
	to_swap_bis.c \
	to_push.c \
	to_rotate.c \
	to_reverse_rotate.c \
	to_solve_2_3_6.c \
	checker_tab.c \
	upper_lower.c \
	free.c \
	ft_split.c \
	find_median.c \
	find_median_bis.c \
	to_solve_bigger.c \
	ft_calloc.c \
	finish_pile_a.c \
	algo.c \
	finish_the_job.c \
	algo_utils.c \
	to_deal.c \
	find_upper_lower_a.c \
	get_next_line/get_next_line_bonus.c \
	get_next_line/get_next_line_utils_bonus.c \

OBJBONUS =$(SRCBONUS:%.c=build_bonus/%.o)

OBJ=$(SRC:%.c=build/%.o)
NAME=push_swap
NAMEBONUS=checker

all : $(NAME)

.PHONY: all

$(NAME): $(OBJ)
		$(CC) $(OBJ) $(INCLUDE) -o $(NAME)

bonus : $(NAMEBONUS)

.PHONY: bonus

$(NAMEBONUS) : $(OBJBONUS)
		$(CC) $(OBJBONUS) $(INCLUDE) -o $(NAMEBONUS)


build/%.o : %.c
	make -C ./printf_no_git
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

build_bonus/%.o : %.c
	make -C ./printf_no_git
	mkdir -p build_bonus
	mkdir -p build_bonus/get_next_line
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build
	rm -rf build_bonus
	rm -rf printf_no_git/build

.PHONY: clean

fclean : clean
	rm -f $(NAME)
	rm -f $(NAMEBONUS)
	rm -f printf_no_git/libftprintf.a

.PHONY: fclean

re : fclean all

.PHONY: re
