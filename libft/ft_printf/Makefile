# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 19:08:02 by sojetimi          #+#    #+#              #
#    Updated: 2025/02/03 18:47:23 by sojetimi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Werror -Wextra	


SOURCES		=	ft_printf.c	\
				ft_print_char.c		\
				ft_print_number.c	\
				ft_print_pointer.c	\
				ft_print_string.c

F_LIBS		= libraries/

LIBS		= ft_printf.h

# SOURCES		= $(MAIN)

OBJECTS		= $(SOURCES:.c=.o)
###

$(NAME) : $(OBJECTS)
	ar crs $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(NAME) $(OBJECTS)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@	