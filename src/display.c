/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:46:10 by hrisse            #+#    #+#             */
/*   Updated: 2025/05/28 15:46:16 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	win_width = game->map.width * TILE_SIZE;
	win_height = game->map.height * TILE_SIZE;
	x = (win_width / 2) - (ft_strlen(message) * 5);
	y = win_height / 2;
	mlx_string_put(game->mlx, game->win, x, y, 0xFFFFFF, message);
}

static void	draw_tile_by_type(t_game *game, char type, int x, int y)
{
	draw_tile(game, game->floor, x, y);
	if (type == '1')
		draw_tile(game, game->wall, x, y);
	else if (type == 'C')
		draw_tile(game, game->collectible, x, y);
	else if (type == 'E')
		draw_tile(game, game->exit, x, y);
	else if (type == 'P')
		draw_tile(game, game->player, x, y);
}

static void	draw_score(t_game *game)
{
	char	*score;
	char	*moves;

	moves = ft_itoa(game->moves);
	score = ft_strjoin("Score: ", moves);
	free(moves);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, score);
	free(score);
}

void	draw_map(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			draw_tile_by_type(game, game->map.grid[y][x], x, y);
			x++;
		}
		y++;
	}
	draw_score(game);
}
