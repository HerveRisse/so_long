#include "../includes/so_long.h"

void	draw_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	display_message(t_game *game, char *message)
{
	int	x;
	int	y;
	int	win_width;
	int	win_height;

	win_width = game->map->width * TILE_SIZE;
	win_height = game->map->height * TILE_SIZE;
	x = (win_width / 2) - (ft_strlen(message) * 5);
	y = win_height / 2;
	mlx_string_put(game->mlx, game->win, x, y, 0xFFFFFF, message);
}

static void	draw_tile_by_type(t_game *game, char type, int x, int y)
{
	draw_tile(game, game->img_floor, x, y);
	if (type == '1')
		draw_tile(game, game->img_wall, x, y);
	else if (type == 'C')
		draw_tile(game, game->img_collectible, x, y);
	else if (type == 'E')
		draw_tile(game, game->img_exit, x, y);
	else if (type == 'P')
		draw_tile(game, game->img_player, x, y);
	else if (type == 'X')
		draw_tile(game, game->img_enemy, x, y);
}

void	draw_map(t_game *game)
{
	int		x;
	int		y;
	char	*score;
	char	*moves;

	y = 0;
	while (game->map->grid[y])
	{
		x = 0;
		while (game->map->grid[y][x])
		{
			draw_tile_by_type(game, game->map->grid[y][x], x, y);
			x++;
		}
		y++;
	}
	moves = ft_itoa(game->moves);
	score = ft_strjoin("Score: ", moves);
	free(moves);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, score);
	free(score);
	if (game->game_over == 1)
		display_message(game, "Game Over! Press ESC to exit");
	else if (game->game_over == 2)
		display_message(game, "Victory! Press ESC to exit");
}

int	load_images(t_game *game)
{
	int	width;
	int	height;

	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &width, &height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &width, &height);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy.xpm", &width, &height);
	return (game->img_player && game->img_wall && game->img_collectible
		&& game->img_exit && game->img_floor && game->img_enemy);
}
