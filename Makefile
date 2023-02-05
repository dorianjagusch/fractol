# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 11:46:33 by djagusch          #+#    #+#              #
#    Updated: 2023/01/27 15:02:38 by djagusch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COLOURS ###

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

### SET UP ###
CC = cc
CFLAGS = -Wall -Werror -Wall -I$I -O3

RM = /bin/rm -f
RMDIR = /bin/rmdir -p

MINILIBX = mlx/libmlx.a
LIBFT = libft/libft.a

S = srcs
O = objs
I = incl

FILES = main handlers fractol fractal draw_fractal view_changers view_shifters \
	view_utils image_setup ft_help ft_rand \
	ft_cadd ft_csub ft_cmult ft_fmultc ft_cmag ft_cpow \
	ft_cdiv ft_ccum_sumf ft_neg_exp \
	ft_mandelbrot ft_julia ft_newton ft_burning_ship \
	get_colour make_bw make_colour make_colour2

HEADER = fractol.h libft.h macos_keys.h errors.h
HEADER := $(addprefix $I/,$(HEADER))

SRCS := $(shell find $S -type f -name '*.c')

OBJS = $(patsubst $S/%,$O/%,$(SRCS:.c=.o))
O_DIRS = $(dir $(OBJS))

NAME = fractol

### RULES ###
all: $(NAME)

minilib: $(MINILIBX)

libft: $(LIBFT)

print:
	@echo $(SRCS)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS)  -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(COLOUR_GREEN) $(NAME) successfully created$(COLOUR_END)"

$(MINILIBX):
	@cd mlx && $(MAKE)
	@echo "$(COLOUR_GREEN) $(MINILIBX) successfully created$(COLOUR_END)"

$(LIBFT):
	@cd libft && $(MAKE)
	@echo "$(COLOUR_GREEN) $(LIBFT) successfully created$(COLOUR_END)"

$O:
	@mkdir -p $@ $(O_DIRS)

$O/%.o: $S/%.c $(HEADER) | $O
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
	@echo "$(COLOUR_GREEN) $@ successfully created$(COLOUR_END)"

clean:
	@cd mlx && $(MAKE) clean
	@echo "$(COLOUR_RED) $(MINILIBX) removed$(COLOUR_END)"
	@cd libft && $(MAKE) clean
	@echo "$(COLOUR_RED) $(LIBFT) removed$(COLOUR_END)"
	@$(RM) $(OBJS)
	@if [ -d $O ]; then $(RM) -rf $(O_DIRS) $O; fi

fclean : clean
	@cd libft && $(MAKE) fclean
	@$(RM) $(NAME)
	@echo "$(COLOUR_RED) $(NAME) removed$(COLOUR_END)"

re: fclean $(NAME)

.PHONY: all clean fclean re
