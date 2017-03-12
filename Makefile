#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 15:20:54 by dkhlopov          #+#    #+#              #
#    Updated: 2017/03/12 15:51:02 by dkhlopov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror
 
SRC = addition.c math.c strmodify.c ft_printf.c ft_atoi.c ft_isdigit.c ft_toupper.c \
	ft_memcpy.c ft_memmove.c ft_putstr.c ft_strchr.c ft_strlen.c ft_strnew.c ft_strstr.c \
	ft_strsub.c ft_strjoin.c ft_strdup.c ft_strcpy.c ft_strdel.c make_aerial.c \
	make_padding.c 	make_flags.c for_parsing.c data_to_str.c parse_format.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	gcc $(FLAGS) -c -o $@ $<


$(NAME) : $(OBJ)
	gcc $(FLAGS) -c $(SRC) -I.
	ar rc $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
