# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 15:01:34 by alejarod          #+#    #+#              #
#    Updated: 2023/03/01 21:33:44 by alejarod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# hide terminal output
#.SILENT:

# Variables
NAME = so_long
CC = gcc
CFLAGS	= -Wall -Werror -Wextra #-g3 -fsanitize=address
RM = rm -rf
AR = ar rcs

# Colors (ANSI escape sequence)
GREEN_PRE = '\033[32m'
RED_PRE = '\033[31m'
RESET_BLACK = '\033[0m'

# Paths
LIBFT_PATH = libft
SRCS_PATH = srcs

# Files
LIBFT_SRCS = $(wildcard $(LIBFT_PATH)/*.c)
SRCS = $(wildcard $(SRCS_PATH)/*.c)
OBJS = $(LIBFT_SRCS:.c=.o) $(SRCS:.c=.o)

# Targets
all: $(NAME)

# rule to compile .c into .o
# $< refers to %.o and $@ refers to %.c
%.o: %.c
#	$(CC) $(CFLAGS) -Imlx_linux -c $< -o $@
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	MAKE -C mlx
	$(CC) $(CFLAGS) -I mlx/libmlx.a -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)
#	$(CC) $(CFLAGS) -I mlx/libmlx.dylib -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)
	@echo $(GREEN_PRE)"MLX & so_long compiled !"$(RESET_BLACK)
	@echo "./so_long <.ber file> to run"

# removes the .o files
clean:
	@$(RM) $(OBJS)
	@$(RM) mlx/*.o
	@echo $(RED_PRE)"Object files deleted !"$(RESET_BLACK)

# removes .o files & push_swap executable
fclean: clean
	@$(RM) $(NAME)
	@$(RM) mlx/libmlx.a
#	$(RM) mlx/libmlx.dylib
	@echo $(RED_PRE)"so_long.a & libmlx.a deleted !"$(RESET_BLACK)

re: fclean all

.PHONY: all test checker clean fclean re