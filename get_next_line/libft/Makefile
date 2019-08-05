#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efeeney <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 15:29:55 by efeeney           #+#    #+#              #
#    Updated: 2018/12/01 15:29:56 by efeeney          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=libft.a
FLAGS=-c -Wall -Werror -Wextra
INC=*.h
$(NAME):
	gcc $(FLAGS) *.c *.h
	ar rc $(NAME) *.o
	ranlib $(NAME)
all: $(NAME)
clean:
	rm -f *.o
fclean:	clean
	rm -f $(NAME)
re: fclean all