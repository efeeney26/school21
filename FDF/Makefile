#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efeeney <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/30 15:56:01 by efeeney           #+#    #+#              #
#    Updated: 2019/06/30 15:58:28 by efeeney          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC_D = $(addprefix ./srcs/, $(SRCS))
OBJ_D = objs
INC = -I ./libft -I ./includes -I ./minilibx_macos
LIB = -L./libft/ -lft 
MLX = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

GCCFLAGS = -Wall -Wextra -Werror
SRCS = main.c \
	   draw.c \
	   hook.c \
	   image.c \
	   init.c \
	   parse.c \
	   rotation.c\
	   utils.c

OBJS = $(addprefix $(OBJ_D)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME):
			make -C ./libft
			make -C ./minilibx_macos
			gcc $(GCCFLAGS) -c $(SRC_D) $(INC)
			mkdir -p $(OBJ_D) && mv $(SRCS:.c=.o) ./$(OBJ_D)/
			gcc $(GCCFLAGS) -o $(NAME) $(OBJS) $(LIB) $(MLX) $(INC)

clean:
			make clean -C ./libft
			make clean -C ./minilibx_macos
			rm -rf $(OBJ_D)

fclean: clean
			make fclean -C ./libft
			make clean -C ./minilibx_macos
			rm -rf $(NAME)

re: fclean all
