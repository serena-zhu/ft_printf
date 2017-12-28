# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yazhu <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 10:32:40 by yazhu             #+#    #+#              #
#    Updated: 2017/12/27 18:49:58 by yazhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFILES	= ft_atoi.c ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c \
		  ft_putwchar.c ft_putwstr.c ft_wstrlen.c ft_haschar.c \
		  ft_digits.c ft_putnbr_base.c process_putnbr.c \
		  convert_xou.c convert_di.c convert_p_percent.c ft_printf.c
OFILES	= $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(CFILES)
	@ar rc $(NAME) $(OFILES)

clean:
	@/bin/rm -f $(OFILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
