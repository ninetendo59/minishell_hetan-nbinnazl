# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 23:26:27 by hetan             #+#    #+#              #
#    Updated: 2024/05/02 06:59:58 by hetan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC_DIR = src/
UTIL_DIR = utils/
MLX = mlx_opengl/
HEADER = header/
A_FILE = library/libft.a $(MLX)libmlx.a

SOURCE = $(SRC_DIR)so_long.c $(SRC_DIR)map_check.c $(SRC_DIR)map_content.c	$(SRC_DIR)map_frame.c $(SRC_DIR)map_path.c $(SRC_DIR)map_show.c $(SRC_DIR)utility.c $(SRC_DIR)controller.c

OBJ = $(SOURCE:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I$(HEADER) -I$(MLX)

RM = -rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C library
	make -C $(MLX)
	$(CC) $(OBJ) $(CFLAGS) -L$(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(A_FILE) 

clean:
	$(RM) $(OBJ)
	make -C $(MLX) clean
	make -C library clean

fclean: clean
	$(RM) $(NAME)
	make -C library fclean
	make -C $(MLX) clean

re: fclean all

.PHONY: all clean fclean re


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
