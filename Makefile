# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 20:42:33 by thabeck-          #+#    #+#              #
#    Updated: 2023/01/08 14:59:22 by thabeck-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

LIBFT_DIR	= ./libft
LIBFT		= ./libft/libft.a

SRC_DIR		= ./src/
HDR_DIR		= ./inc/

HDR 		= ./inc/push_swap.h

SRCS		= ./src/push_swap.c ./src/arguments.c				\
			  ./src/stack_utils_1.c ./src/stack_utils_2.c		\
			  ./src/index_utils.c ./src/sort_three_nbr.c		\
			  ./src/sort_five_nbr.c ./src/big_sort.c			\
			  ./src/big_sort_utils_1.c ./src/big_sort_utils_2.c	\
			  ./src/big_sort_utils_3.c ./src/moves.c			\
			  ./src/push.c ./src/swap.c ./src/rotate.c			\
			  ./src/reverse_rotate.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

GREEN		= \e[38;5;118m
BLUE		= \e[38;5;75m
RESET		= \e[0m
_SUCCESS	= [$(GREEN)== SUCCESS ==$(RESET)]
_INFO		= [$(BLUE)== INFO ==$(RESET)]

all: $(NAME)

.c.o:
	@ $(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(LIBFT):
	@ make bonus -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT) 
	@ $(CC) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)
	@ echo "\n$(_SUCCESS) $(NAME) is ready.\n"

norm:
	@ norminette $(SRC_DIR) $(HDR_DIR)

clean:	
	@ $(RM) $(OBJS)

fclean: clean
	@ make fclean -C $(LIBFT_DIR)
	@ $(RM) $(NAME)
	@ echo "\n$(_INFO) $(NAME) was removed.\n"

re: fclean all

.PHONY: all clean fclean re
