# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 23:10:05 by julee             #+#    #+#              #
#    Updated: 2018/09/25 21:51:54 by julee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC := $(shell find src -name "*.c") 

INC = includes/*.h

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) $(INC)
	@ar -rc libft.a $(OBJ) $(PFOBJ)
	@ranlib libft.a

.PHONY: clean fclean all re

clean:
	@rm -f $(OBJ) $(PFOBJ)

fclean: clean
	@rm -f $(NAME)

all: $(NAME)

re: fclean all