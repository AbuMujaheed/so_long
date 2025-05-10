NAME = so_long

# Directories
SRC_DIR = srcs/
OBJ_DIR = obj/
INC_DIR = includes/
LIBFT_DIR = libft/
GNL_DIR = $(LIBFT_DIR)get_next_line/
MLX_DIR = mlx/

# Files
SRC_FILES = so_long.c init_game.c render.c exit.c map.c validate_map.c \
			errors.c movement.c check_map_path.c check_map_walls.c \
			copy_map.c flood_fill.c map_utils.c scrn_mvs_counter.c \
			check_map_walls_2.c free_map_info.c read_map_info.c
GNL_FILES = get_next_line.c get_next_line_utils.c

# Objects
OBJ_FILES = $(SRC_FILES:.c=.o) $(GNL_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES)) $(addprefix $(GNL_DIR), $(GNL_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR) -g
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Rules
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "Compilation finished: $(NAME)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(GNL_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@rm -f *.o
	@echo "Objects and $(OBJ_DIR) cleaned."

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re