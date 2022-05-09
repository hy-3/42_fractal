NAME = fractol
CC = gcc
#FLAGS = -Wall -Wextra -Werror
FLAGS = -framework OpenGL -framework AppKit
LIBFT_PATH=./lib/libft/
LIBFT=./lib/libft/libft.a
MIN_PATH=./lib/minilibx_macos/
MIN=./lib/minilibx_macos/libmlx.a
SRC = src/main.c

all: $(NAME)

$(NAME):
	make -C $(LIBFT_PATH)
	make -C $(MIN_PATH)
	$(CC) $(SRC) $(LIBFT) $(MIN) $(FLAGS) -o $(NAME)

clean:
	make clean -C ${LIBFT_PATH}
	make clean -C ${MIN_PATH}

fclean: clean
	make clean
	rm -f ${LIBFT}
	rm -f ${MIN}
	rm -f ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re
