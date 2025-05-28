/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:48:38 by hrisse            #+#    #+#             */
/*   Updated: 2025/05/28 15:48:44 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

static int	check_file_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	return (!ft_strncmp(file + len - 4, ".ber", 4));
}

static int	validate_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error\nUsage: %s <map.ber>\n", argv[0]);
		return (0);
	}
	if (!check_file_extension(argv[1]))
	{
		ft_printf("Error\nInvalid file extension (must be .ber)\n");
		return (0);
	}
	return (1);
}

static int	initialize_map(t_map *map, char *map_file)
{
	if (!allocate_map(map, map_file))
	{
		ft_printf("Error\nFailed to allocate map\n");
		return (0);
	}
	if (!parse_map(map, map_file))
	{
		ft_printf("Error\nFailed to parse map\n");
		free_map(map);
		return (0);
	}
	return (1);
}

static int	initialize_map_and_game(t_game *game, t_map *map, char *map_file)
{
	if (!initialize_map(map, map_file))
		return (0);
	game->map = *map;
	if (!init_game(game))
	{
		ft_printf("Error\nFailed to initialize game\n");
		free_map(map);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		status;
	t_game	game;
	t_map	map;

	status = validate_args(argc, argv);
	if (!status)
		return (1);
	status = initialize_map_and_game(&game, &map, argv[1]);
	if (!status)
		return (1);
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	free_map(&map);
	return (0);
}
