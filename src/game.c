#include "../includes/so_long.h"

/* Initialize random number generator */
__attribute__((constructor))
static void	init_rand(void)
{
	// Removed srand(time(NULL));
}

static void	destroy_images(t_game *game)
{
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_enemy)
		mlx_destroy_image(game->mlx, game->img_enemy);
}

int	init_game(t_game *game)
{
	int	win_width;
	int	win_height;

	find_player_pos(game);
	game->moves = 0;
	game->game_over = 0;
	game->frame_count = 0;

	win_width = game->map->width * TILE_SIZE;
	win_height = game->map->height * TILE_SIZE;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, win_width, win_height, "So Long");
	if (!game->win)
		return (0);
	if (!load_images(game))
		return (0);
	draw_map(game);
	mlx_loop_hook(game->mlx, handle_frame, game);
	return (1);
}

int	handle_key(int keycode, t_game *game)
{
	if (game->game_over)
	{
		if (keycode == KEY_ESC)
			close_game(game);
		return (0);
	}

	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == KEY_S)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == KEY_A)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == KEY_D)
		move_player(game, game->player_x + 1, game->player_y);

	draw_map(game);
	return (0);
}

int	close_game(t_game *game)
{
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	destroy_images(game);
	free_map(game->map);
	free(game->map);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	handle_frame(t_game *game)
{
	game->frame_count++;
	if (game->frame_count % 9000 == 0 && !game->game_over)
	{
		if (move_enemies(game))
			draw_map(game);
	}
	return (0);
}
