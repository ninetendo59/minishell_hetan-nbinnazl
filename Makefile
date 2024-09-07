NAME	=	minishell
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
HEADER 	=	inc
SRC		=	src/main.c src/signalling.c	src/rd_cmd.c\
			shell/builtins/cd.c shell/builtins/echo.c shell/builtins/env.c shell/builtins/exit.c shell/builtins/export.c shell/builtins/pwd.c shell/builtins/unset.c	\
			shell/builtins/env.c shell/env/sort.c	\

# LIBRARY	= 	libft/libft.a 
OBJ 	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJ) -o $@ -lreadline

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re