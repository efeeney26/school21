NAME = fillit
SRCS = ./srcs/*.c
INCLUDES = ./includes/fillit.h
CFLAGS =-Wall -Wextra -Werror
all: $(NAME)
$(NAME):
	gcc  -c $(CFLAGS) -g $(SRCS) -Iincludes $(INCLUDES) -Iincludes/ 
	gcc -o $(NAME) *.o -Iincludes/
	find . -name \*.gch -type f -delete
	find . -name \*.DS_Store -type f -delete
clean:
	-rm -rf *.o
fclean: clean
	-rm -f $(NAME)
re: fclean all
