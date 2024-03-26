NAME	=	minishell
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
HEADER 	=	-I inc/
SRC		=	src/main.c \
			util/util.c
LIBRARY	= 	libft/libft.a
OBJ 	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBRARY)
	$(CC) $(CFLAGS) $(HEADER) $(OBJ) $(LIBRARY) -o $@

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re