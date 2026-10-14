# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afournie <afournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/28 15:33:58 by afournie          #+#    #+#              #
#    Updated: 2026/10/14 14:32:58 by afournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=	.
OBJ_DIR		=	obj

SRC			=	main.cpp

INC			=	Array.hpp \
				Array.tpp

OBJ			=	$(SRC:%.cpp=$(OBJ_DIR)/%.o)

CC			=	c++
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror

RM			=	rm -rf

NAME		=	ex02

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
