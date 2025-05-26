NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I./libft -Iminilibx-linux

MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_FILES = main.c map.c map_utils.c game.c utils.c display.c movement.c map_read.c display_utils.c game_utils.c map_validation.c game_init.c map_checks.c map_path.c

SRC = $(addprefix src/, $(SRC_FILES))
OBJS = $(SRC:.c=.o)

all: $(MLX_DIR)/libmlx.a $(NAME)

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX_DIR)/libmlx.a $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(OBJS) $(CFLAGS) $(MLX_FLAGS) -L./libft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C ./libft clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
