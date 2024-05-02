NAME		= libftprintf.a
HEADER		= ../header
LIBFT		= ../libft
SRC_DIR		= src/
UTIL_DIR	= utils/
OBJ_DIR		= objft/
CC			= cc
CC_FLAGS	= -Wall -Wextra -Werror

SRC_FILES	= ft_printf.c ft_printf_util.c specifier_util.c specifier_flags.c convert_flags.c convert_length.c convert_precision.c
UTIL_FILES	= ft_print_i.c ft_print_s.c ft_print_u.c ft_print_x.c ft_print_p.c ft_print_c.c libft_extend.c ft_print_o.c
OBJ_FILES	= $(SRC_FILES:.c=.o) $(UTIL_FILES:.c=.o)
OBJ			= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJF			= .cache_exists

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	echo "Compiling: $<"
	$(CC) $(CC_FLAGS) -I $(HEADER) -c $< -o $@

$(OBJ_DIR)%.o: $(UTIL_DIR)%.c | $(OBJF)
	echo "Compiling: $<"
	$(CC) $(CC_FLAGS) -I $(HEADER) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBFT)
	make bonus -C $(LIBFT)
	cp ../libft/libft.a $(NAME)
	ar r $(NAME) $(OBJ)
	echo "ft_printf is compiled!"

$(OBJF):
	mkdir -p $(OBJ_DIR)

all: $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT)
	echo "All objects are cleaned!"

fclean: clean
	rm -f $(LIBFT)/libft.a
	rm -f $(NAME)

re: fclean all

bonus: all
	
.PHONY : all clean fclean re
