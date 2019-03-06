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

SRC = ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c \
	  ft_isdigit.c ft_isalpha.c ft_atoi.c ft_strncmp.c ft_strcmp.c \
	  ft_strcpy.c ft_strncpy.c ft_strdup.c ft_strlen.c ft_strcat.c \
	  ft_strncat.c ft_strlcat.c ft_strstr.c ft_strnstr.c ft_strchr.c \
	  ft_strrchr.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_memccpy.c \
	  ft_memcpy.c ft_bzero.c ft_memset.c ft_memalloc.c ft_memdel.c \
	  ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	  ft_strjoin.c ft_strtrim.c ft_strsplit.c  ft_itoa.c ft_putchar.c \
	  ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd.c ft_lstmap.c\
	  ft_lstdel.c ft_lstiter.c ft_lstdelone.c

PFSRC = ft_printf/ft_printf.c ft_printf/conversion_c.c ft_printf/conversion_i.c \
		ft_printf/conversion_o.c ft_printf/conversion_p.c ft_printf/conversion_pcnt.c \
		ft_printf/conversion_s.c ft_printf/conversion_u.c ft_printf/conversion_x.c \
		ft_printf/flag.c ft_printf/globalfunc.c ft_printf/itoa.c

PFOBJ = $(PFSRC:.c=.o)

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) $(PFOBJ) libft.h ft_printf/ft_printf.h
	@ar -rc libft.a $(OBJ) $(PFOBJ)
	@ranlib libft.a

.PHONY: clean fclean all re

clean:
	@rm -f $(OBJ) $(PFOBJ)

fclean: clean
	@rm -f $(NAME)

all: $(NAME)

re: fclean all