NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror
FRAMEWORK_FLAGS = -framework OpenGL -framework AppKit
LIBFT_PATH = lib/libft/
LIBFT = lib/libft/libft.a
MIN_PATH = lib/minilibx_opengl_20191021/
MIN = lib/minilibx_opengl_20191021/libmlx.a
SRC = src/main.c \
	  src/fractol.c \
	  src/key_mouse_controle.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	make -C $(MIN_PATH)
	$(CC) $(OBJ) $(LIBFT) $(MIN) $(FLAGS) $(FRAMEWORK_FLAGS) -o $(NAME)

%.o: %.clean
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(MIN_PATH)
	rm -f $(OBJ)

fclean: clean
	make clean
	rm -f $(LIBFT)
	rm -f $(MIN)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
