#include "../includes/so_long.h"

void	find_player_pos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->grid[y])
	{
		x = 0;
		while (game->map->grid[y][x])
		{
			if (game->map->grid[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	handle_collision(t_game *game, char next_pos, int new_x, int new_y)
{
	if (next_pos == 'C')
		game->map->collectibles--;
	if (next_pos == 'X')
	{
		game->game_over = 1;
		draw_map(game);
		return (1);
	}
	if (next_pos == 'E' && game->map->collectibles == 0)
	{
		game->game_over = 2;
		draw_map(game);
		return (1);
	}
	game->map->grid[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	return (1);
}

int	move_player(t_game *game, int new_x, int new_y)
{
	char	next_pos;

	next_pos = game->map->grid[new_y][new_x];
	if (next_pos == '1')
		return (0);
	if (next_pos == 'E' && game->map->collectibles > 0)
		return (0);
	game->map->grid[game->player_y][game->player_x] = '0';
	return (handle_collision(game, next_pos, new_x, new_y));
}

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

static int	try_move_enemy(t_game *game, t_pos *pos, t_pos *new_pos)
{
	if (game->map->grid[new_pos->y][new_pos->x] == '0')
	{
		game->map->grid[pos->y][pos->x] = '0';
		game->map->grid[new_pos->y][new_pos->x] = 'X';
		return (1);
	}
	else if (game->map->grid[new_pos->y][new_pos->x] == 'P')
	{
		game->game_over = 1;
		return (1);
	}
	return (0);
}

static t_pos	get_new_pos(t_pos *pos, int dir)
{
	t_pos	new_pos;

	new_pos = *pos;
	if (dir == 0)
		new_pos.y--;
	else if (dir == 1)
		new_pos.y++;
	else if (dir == 2)
		new_pos.x--;
	else if (dir == 3)
		new_pos.x++;
	return (new_pos);
}

static int	get_pseudo_random(t_game *game)
{
	return ((game->frame_count * game->player_x + game->player_y) % 4);
}

int	move_enemies(t_game *game)
{
	t_pos	pos;
	t_pos	new_pos;
	int		moved;
	int		dir;

	moved = 0;
	pos.y = 0;
	while (pos.y < game->map->height)
	{
		pos.x = 0;
		while (pos.x < game->map->width)
		{
			if (game->map->grid[pos.y][pos.x] == 'X')
			{
				dir = get_pseudo_random(game);
				new_pos = get_new_pos(&pos, dir);
				moved |= try_move_enemy(game, &pos, &new_pos);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (moved);
}
