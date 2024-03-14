# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 06:33:15 by hkocan            #+#    #+#              #
#    Updated: 2024/03/13 06:33:15 by hkocan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
NORMINETTE = norminette

LIBFT_PATH	=	./inc/libft
LIBFT		=	$(LIBFT_PATH)/libft.a

OBJ_PATH = ./obj
SRC_PATH = ./src
LIST_PATH = ./src/list_utils
SORT_PATH=./src/sort_time
ACTION_PATH=./src/action

SRC = $(SRC_PATH)/main.c				\
	  $(SRC_PATH)/check_arg.c			\
	  $(SRC_PATH)/free.c				\
	  $(LIST_PATH)/create_box.c			\
	  $(LIST_PATH)/list_functions.c		\
	  $(SORT_PATH)/sort.c				\
	  $(SORT_PATH)/quick_sort.c			\
	  $(SORT_PATH)/tree_sort.c			\
	  $(ACTION_PATH)/action_swap.c		\
	  $(ACTION_PATH)/action_push.c		\
	  $(ACTION_PATH)/action_rotate.c	\
	  $(ACTION_PATH)/action_reverse.c	\

OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)/%.o)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@ echo "\nPush_swap is compiled\n"

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_PATH) all

all: $(NAME)

clean:
	@ $(MAKE) -C $(LIBFT_PATH) clean
	@ $(RM) $(OBJ_PATH)

fclean: clean
	@ $(MAKE) -C $(LIBFT_PATH) fclean
	@ $(RM) $(NAME)

norm:
	$(NORMINETTE) $(SRC) ./inc/push_swap.h ./inc/libft

re: fclean all

.PHONY: all clean fclean re norm