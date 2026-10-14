# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afournie <afournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/28 15:32:40 by afournie          #+#    #+#              #
#    Updated: 2026/10/14 12:07:34 by afournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=	.
OBJ_DIR		=	obj

SRC			=	main.cpp

INC			=	whatever.hpp

OBJ			=	$(SRC:%.cpp=$(OBJ_DIR)/%.o)

CC			=	c++
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror

RM			=	rm -rf

NAME		=	ex00

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
