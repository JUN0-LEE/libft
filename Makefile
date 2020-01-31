# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 23:10:05 by julee             #+#    #+#              #
#    Updated: 2020/01/31 13:22:01 by julee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

CFLAGS := -Wall -Wextra -Werror

NAME := libft.a

SRC := $(shell find src -name "*.c") 

INC := $(shell find includes -name "*.h")

OBJ := $(SRC:.c=.o)

$(NAME): $(OBJ) $(INC)
	@ar -rc libft.a $(OBJ)
	@ranlib libft.a

$(OBJ): %.o : %.c $(INC)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean fclean all re

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

all: $(NAME)

re: fclean all
