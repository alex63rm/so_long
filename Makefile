# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 15:01:34 by alejarod          #+#    #+#              #
#    Updated: 2023/07/05 20:34:24 by alejarod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# hide terminal output
#.SILENT:

# Variables
NAME = so_long
CC = gcc -g3 #-fsanitize=address
CFLAGS	= -Wall -Werror -Wextra  
RM = rm
AR = ar rcs

# Colors (ANSI escape sequence)
GREEN_PRE = '\033[32m'
RED_PRE = '\033[31m'
RESET_BLACK = '\033[0m'


# External Paths and libraries
PRINTF_PATH = ./ft_printf
PRINTF_A = $(PRINTF_PATH)/libftprintf.a

GNL_PATH = ./ft_gnl
GNL_A = $(GNL_PATH)/gnl.a

MLX_PATH = ./mlx
MLX_A = -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

# Project sources and objects
SRCS_PATH = ./srcs
SRCS = error_exit.c error_utils.c main.c map_error.c map.c move_utils.c movement.c textures.c zz_temp_utils.c
HEADER = $(SRCS_PATH)/so_long.h

OBJS_PATH = ./objs
OBJS = $(addprefix $(OBJS_PATH)/, $(SRCS:.c=.o))


#Object rule and move them to the object folder
$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $^ -o $@

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	MAKE -C $(PRINTF_PATH)
	@echo $(GREEN_PRE)"PRINTF compiled!"$(RESET_BLACK)
	MAKE -C $(GNL_PATH)
	@echo $(GREEN_PRE)"GNL compiled!"$(RESET_BLACK)
	MAKE -C $(MLX_PATH) 2>logs
	$(RM) logs
	@echo $(GREEN_PRE)"MLX compiled!"$(RESET_BLACK)
	$(CC) $^ $(PRINTF_A) $(GNL_A) $(MLX_A) -o $@
	@echo $(GREEN_PRE)"so_long compiled!"$(RESET_BLACK)
	@echo "./so_long <.ber file> to run"

#create the object directory
$(OBJS_PATH):
	mkdir $@

# removes the .o files
clean:
	@$(RM) -rf $(OBJS_PATH)
	MAKE -C $(PRINTF_PATH) clean
	MAKE -C $(GNL_PATH) clean
	MAKE -C $(MLX_PATH) clean
	@echo $(RED_PRE)"Object files deleted !"$(RESET_BLACK)

# removes .o files & so_long executable
fclean: clean
	@$(RM) $(NAME)
	MAKE -C $(PRINTF_PATH) fclean
	MAKE -C $(GNL_PATH) fclean
	MAKE -C $(MLX_PATH) clean
	@echo $(RED_PRE)"so_long.a deleted !"$(RESET_BLACK)

re: fclean all

normi:
	norminette $(SRCS_PATH)/*.c $(HEADER) 

.PHONY: all clean fclean re normi