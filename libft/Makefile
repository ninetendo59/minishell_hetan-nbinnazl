# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 23:26:27 by hetan             #+#    #+#              #
#    Updated: 2024/09/08 06:23:41 by hetan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = ../header
CFLAGS = -Wall -Wextra -Werror -I $(HEADER)
RM = rm -rf
PRINTF_DIRS = ft_printf/src/
PRINTF_DIRU = ft_printf/utils/
GNL_DIRU = get_next_line/
SOURCE = ft_isascii.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c		\
			ft_atoi.c ft_isdigit.c ft_memchr.c ft_putendl_fd.c ft_striteri.c	\
			ft_strncmp.c ft_toupper.c ft_bzero.c ft_isprint.c ft_memcmp.c		\
			ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_calloc.c ft_itoa.c		\
			ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c ft_isalnum.c	\
			ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c ft_isalpha.c		\
			ft_memset.c ft_strchr.c ft_strlen.c	ft_substr.c						\
			ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c ft_lstiter.c		\
			ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lstclear.c		\
			ft_strcmp.c															\
			$(PRINTF_DIRS)ft_printf.c $(PRINTF_DIRS)ft_printf_util.c			\
			$(PRINTF_DIRS)specifier_util.c $(PRINTF_DIRS)specifier_flags.c		\
			$(PRINTF_DIRS)convert_flags.c $(PRINTF_DIRS)convert_length.c		\
			$(PRINTF_DIRS)convert_precision.c									\
			$(PRINTF_DIRU)ft_print_i.c $(PRINTF_DIRU)ft_print_s.c				\
			$(PRINTF_DIRU)ft_print_u.c $(PRINTF_DIRU)ft_print_x.c				\
			$(PRINTF_DIRU)ft_print_p.c $(PRINTF_DIRU)ft_print_c.c				\
			$(PRINTF_DIRU)libft_extend.c $(PRINTF_DIRU)ft_print_o.c				\
			$(GNL_DIRU)get_next_line.c $(GNL_DIRU)get_next_line_utils.c			
OBJF = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJF)
	@echo "Compiling..."
	@ar rcs $(NAME) $(OBJF)
	@echo "Libft compiled!\n"

%.o : %.c
	@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	@echo "Cleaning o.o files please wait..."
	@$(RM) $(OBJF)
	@echo "Done clean!\n"

fclean: clean
	@echo "fclean starts"
	@$(RM) $(NAME)
	@echo "DONE FCLEAN!\n"

re: fclean all
	@echo "\ndone re-make"

.PHONY : all clean fclean re



# NAME = so_long
# SRC_DIR = src/
# UTIL_DIR = utils/
# MLX = mlx_opengl/
# HEADER = header/
# A_FILE = library/libft.a $(MLX)libmlx.a

# SOURCE = $(SRC_DIR)so_long.c $(SRC_DIR)map_check.c $(SRC_DIR)map_content.c	$(SRC_DIR)map_frame.c $(SRC_DIR)map_path.c $(SRC_DIR)map_show.c $(SRC_DIR)utility.c $(SRC_DIR)controller.c

# OBJ = $(SOURCE:.c=.o)
# CFLAGS = -Wall -Wextra -Werror -I$(HEADER) -I$(MLX)

# RM = -rm -rf

# all: $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(NAME): $(OBJ)
# 	make -C library
# 	make -C $(MLX)
# 	$(CC) $(OBJ) $(CFLAGS) -L$(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(A_FILE) 

# clean:
# 	$(RM) $(OBJ)
# 	make -C $(MLX) clean
# 	make -C library clean

# fclean: clean
# 	$(RM) $(NAME)
# 	make -C library fclean
# 	make -C $(MLX) clean

# re: fclean all

# .PHONY: all clean fclean re
