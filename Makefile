NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror
LINKS = -L ./lib/libft -lft \
		-L ./lib/minilibx -lmlx \
		-framework OpenGL -framework AppKit
SRC = src/main.c

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) $(LINKS)

