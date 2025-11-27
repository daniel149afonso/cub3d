# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_INC) -I$(MLX_DIR)
# CFLAGS += -w -Wno-incompatible-pointer-types -Wno-error

# OS settings
ifeq ($(shell uname), Darwin)
	MLX_DIR = ./minilibx-opengl
	MLX_FLAGS = -I$(MLX_DIR)
	MLX_LIBS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR = ./minilibx-linux
	MLX_FLAGS = -I$(MLX_DIR)
	MLX_LIBS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
endif

# Paths
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIBFT_DIR = libft
LIBFT_INC = $(LIBFT_DIR)/include
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Files
SRC = main.c \
	  check_map.c \
	  check_map_utils.c \
	  end_game.c \
	  free.c \
	  free_utils.c \
	  init.c \
	  load_map.c \
	  move.c \
	  raycasting.c \
	  raycasting_utils.c \
	  draw.c \
	  utils.c \
	  minimap.c \
	  key_inputs.c \
	  ray.c \
	  ray_utils.c \
	  load_textures.c \
	  parse_textures.c \
	  mouse.c \
	  player.c \
	  door_handler.c \
	  game_loop.c \
	  init_player.c \
	  render_loop.c \
	  draw_texture.c \
	  parse_utils.c

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

# Targets
NAME = cub3D

# Colors
GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIBS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)✅ Compilation successfully completed!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -I$(INC_DIR) -I$(LIBFT_INC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	@echo "$(GREEN)🧹 Object files cleaned.$(RESET)"

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	@echo "$(GREEN)🗑️  All binaries cleaned.$(RESET)"

re: fclean all

.SILENT:
.PHONY: all clean fclean re
