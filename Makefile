# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbenazza <hbenazza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 18:23:50 by hbenazza          #+#    #+#              #
#    Updated: 2023/11/24 20:36:50 by hbenazza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

LIB = ar -rc

RM = rm -rf

SRC = ft_printf.c ft_putcharft.c ft_putstrft.c ft_putnbrft.c ft_putunsigned.c ft_puthexadecimal.c ft_putpointer.c

OBJ = ${SRC:.c=.o}

${NAME}: ${OBJ} ${SRC}
		${LIB} ${NAME} ${OBJ}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

all: ${NAME}

re: fclean all
