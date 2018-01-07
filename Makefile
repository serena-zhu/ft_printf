# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yazhu <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 10:32:40 by yazhu             #+#    #+#              #
#    Updated: 2018/01/06 23:27:52 by yazhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFILES	= ft_atoi.c ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c \
		  ft_putwchar.c ft_putwstr.c ft_wstrlen.c ft_haschar.c \
		  ft_digits.c ft_putnbr_base.c ft_power.c process_nbr.c \
		  convert_xou.c convert_di.c convert_p.c convert_s.c convert_ws.c convert_c.c \
		  convert_efg.c put_nbr_ef.c set_color.c ft_printf.c
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
