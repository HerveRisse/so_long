/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:47:36 by hrisse            #+#    #+#             */
/*   Updated: 2025/05/28 15:47:43 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	init_window(t_game *game)
{
	int	win_width;
	int	win_height;

	win_width = game->map.width * TILE_SIZE;
	win_height = game->map.height * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, win_width, win_height, "So Long");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (0);
	}
	return (1);
}

int	init_game(t_game *game)
{
	find_player_pos(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	if (!init_window(game))
		return (0);
	if (!load_images(game))
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (0);
	}
	game->moves = 0;
	draw_map(game);
	mlx_hook(game->win, 17, 0, close_game, game);
	return (1);
}
