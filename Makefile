NAME		=	minishell
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
HEADER 		=	inc
BUILTINS	=	cd echo env exit export pwd unset
ENV			=	env get shlvl sort
EXEC		=	bin builtin
PARSE		=	expansion line token
UTILS		=	expansion fd free gnl minishell parse redir token type utils
MINI		=	main rd_cmd signalling

SRC			=	$(addsuffix .c, $(addprefix shell/builtins/, $(BUILTINS))) \
				$(addsuffix .c, $(addprefix shell/env/, $(ENV))) \
				$(addsuffix .c, $(addprefix shell/exec/, $(EXEC))) \
				$(addsuffix .c, $(addprefix shell/parse/, $(PARSE))) \
				$(addsuffix .c, $(addprefix shell/utils/, $(UTILS))) \
				$(addsuffix .c, $(addprefix src/, $(MINI)))

# LIBRARY	= 	libft/libft.a 
OBJ 		=	$(SRC:.c=.o)

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