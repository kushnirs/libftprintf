#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skushnir <skushnir@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 14:17:51 by skushnir          #+#    #+#              #
#    Updated: 2017/11/09 14:18:08 by skushnir         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
SRC =  ft_putstr.c ft_strmapi.c ft_putstr_fd.c ft_strncat.c ft_atoi.c	\
	ft_strcat.c	ft_strncmp.c ft_bzero.c ft_memalloc.c ft_strchr.c		\
	ft_strncpy.c ft_isalnum.c ft_memccpy.c ft_strclr.c ft_strnequ.c		\
	ft_memchr.c ft_strcmp.c ft_strnew.c ft_isascii.c ft_memcmp.c		\
	ft_strcpy.c ft_strnstr.c ft_isdigit.c ft_memcpy.c ft_strdel.c		\
	ft_strrchr.c ft_isprint.c ft_memdel.c ft_strdup.c ft_strsplit.c		\
	ft_itoa.c ft_memmove.c ft_strequ.c ft_strstr.c ft_lstadd.c			\
	ft_memset.c ft_striter.c ft_strsub.c ft_putchar.c	ft_isalpha.c	\
	ft_striteri.c ft_strtrim.c ft_lstdel.c ft_putchar_fd.c ft_strjoin.c	\
	ft_tolower.c ft_lstdelone.c ft_putendl.c ft_strlcat.c ft_toupper.c	\
	ft_lstiter.c ft_putendl_fd.c ft_strlen.c ft_lstmap.c ft_putnbr.c	\
	ft_lstnew.c ft_putnbr_fd.c ft_strmap.c ft_strrev.c ft_putnstr.c		\
	printf/ft_addition.c printf/ft_apply_flags.c printf/ft_decnbr.c		\
	printf/ft_doublenbr.c printf/ft_eg_nbr.c printf/ft_hexnbr.c			\
	printf/ft_octnbr.c	printf/ft_printf.c ft_strpcmp.c					\
	printf/ft_decnbrlen.c printf/ft_binnbr.c
	
OBJ = $(SRC:.c=.o)

all: $(SRC) $(SRC_PR) $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

.c.o:
	@gcc  -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
