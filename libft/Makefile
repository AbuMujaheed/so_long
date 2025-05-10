# ==============================================================================
#                                LIBFT MAKEFILE
# ==============================================================================

NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I.

# ================================
# Source Files
# ================================

SRC =	ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c

BSRC =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ     = $(SRC:.c=.o)
BOBJ    = $(BSRC:.c=.o)

# ================================
# ft_printf
# ================================

FT_PRINTF_DIR   = ft_printf
FT_PRINTF_LIB   = $(FT_PRINTF_DIR)/libftprintf.a

# ================================
# get_next_line
# ================================

GNL_DIR         = get_next_line
GNL_SRC         = get_next_line.c get_next_line_utils.c
GNL_OBJ         = $(addprefix $(GNL_DIR)/, $(GNL_SRC:.c=.o))

# ================================
# Build Targets
# ================================

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ)
	@make -C $(FT_PRINTF_DIR)
	cp $(FT_PRINTF_LIB) $(NAME)
	ar rc $(NAME) $(OBJ) $(GNL_OBJ)

bonus: $(OBJ) $(BOBJ) $(GNL_OBJ)
	ar rc $(NAME) $(OBJ) $(BOBJ) $(GNL_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(BOBJ) $(GNL_OBJ)
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re