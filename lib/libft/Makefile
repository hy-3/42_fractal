CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a

PART1_SRC = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c
PART2_SRC = \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c
SRC_DIR = src
CONV_DIR = conversion
UTIL_DIR = util
FT_PRINTF_SRC = \
	$(FT_PRINTF_PATH)/$(SRC_DIR)/ft_printf.c \
	$(FT_PRINTF_PATH)/$(CONV_DIR)/c_conv.c \
	$(FT_PRINTF_PATH)/$(CONV_DIR)/s_conv.c \
	$(FT_PRINTF_PATH)/$(CONV_DIR)/p_conv.c \
	$(FT_PRINTF_PATH)/$(CONV_DIR)/d_i_conv.c \
	$(FT_PRINTF_PATH)/$(CONV_DIR)/u_conv.c \
	$(FT_PRINTF_PATH)/$(CONV_DIR)/x_conv.c \
	$(FT_PRINTF_PATH)/$(UTIL_DIR)/is_char_match.c \
	$(FT_PRINTF_PATH)/$(UTIL_DIR)/base_ten_power.c \
	$(FT_PRINTF_PATH)/$(UTIL_DIR)/cust_putnbr_int.c \
	$(FT_PRINTF_PATH)/$(UTIL_DIR)/cust_putnbr_unsigned_int.c \
	$(FT_PRINTF_PATH)/$(UTIL_DIR)/cust_putchar.c

MANDATORY_SRC = $(PART1_SRC) $(PART2_SRC) $(FT_PRINTF_SRC)
MANDATORY_OBJ = $(MANDATORY_SRC:%.c=%.o)

FT_PRINTF_PATH = ft_printf
FT_PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
	@ar -rcs $(NAME) $(MANDATORY_OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

re: fclean all

fclean: clean
	@echo "Deleting $(NAME)"
	@rm -f $(NAME)

clean:
	@echo "Deleting object files"
	@rm -f $(MANDATORY_OBJ)

.PONHY: all re fclean clean
