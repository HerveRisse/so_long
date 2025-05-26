/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromatitien <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:01:35 by afromatitien      #+#    #+#             */
/*   Updated: 2025/05/24 12:01:35 by afromatitien     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*load_xpm_image(void *mlx, char *path, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx, path, width, height));
}

int	load_images(t_game *game)
{
	int	width;
	int	height;

	game->player = load_xpm_image(game->mlx,
			"textures/player.xpm", &width, &height);
	if (!game->player)
		return (0);
	game->wall = load_xpm_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	if (!game->wall)
		return (0);
	game->collectible = load_xpm_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	if (!game->collectible)
		return (0);
	game->exit = load_xpm_image(game->mlx,
			"textures/exit.xpm", &width, &height);
	if (!game->exit)
		return (0);
	game->floor = load_xpm_image(game->mlx,
			"textures/floor.xpm", &width, &height);
	if (!game->floor)
		return (0);
	return (1);
}
