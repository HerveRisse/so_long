#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("Error: wrong number of arguments\n");
		return (1);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	ft_printf("Starting game...\n");
	ft_printf("Parsing map...\n");
	if (!parse_map(map, argv[1]))
	{
		free(map);
		return (1);
	}
	ft_printf("Validating map...\n");
	if (!validate_map(map))
	{
		ft_printf("Error: invalid map\n");
		free_map(map);
		free(map);
		return (1);
	}
	ft_printf("Initializing game...\n");
	game.map = map;
	if (!init_game(&game))
	{
		ft_printf("Error: failed to initialize game\n");
		free_map(map);
		free(map);
		return (1);
	}
	ft_printf("Setting up hooks...\n");
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	ft_printf("Starting game loop...\n");
	mlx_loop(game.mlx);
	return (0);
}
