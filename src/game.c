/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromatitien <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:01:35 by afromatitien      #+#    #+#             */
/*   Updated: 2025/05/24 12:01:35 by afromatitien     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	destroy_images(t_game *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
}

static void	process_movement(t_game *game, int keycode)
{
	int	new_x;
	int	new_y;

	if (keycode == KEY_ESC)
		close_game(game);
	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
	{
		update_position(keycode, &new_x, &new_y);
		if (move_player(game, new_x, new_y))
			draw_map(game);
	}
}

int	handle_key(int keycode, t_game *game)
{
	process_movement(game, keycode);
	return (0);
}

int	close_game(t_game *game)
{
	if (!game)
		exit(0);
	destroy_images(game);
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(&game->map);
	exit(0);
	return (1);
}
