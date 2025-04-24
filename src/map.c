#include "../includes/so_long.h"

static int	read_map_lines(t_map *map, int fd)
{
	char	*line;
	char	*newline;
	int		i;

	i = 0;
	while ((line = get_next_line(fd)))
	{
		newline = ft_strchr(line, '\n');
		if (newline)
			*newline = '\0';
		map->grid[i] = line;
		if (i == 0)
			map->width = ft_strlen(line);
		i++;
	}
	map->grid[i] = NULL;
	return (1);
}

int	parse_map(t_map *map, char *file)
{
	int	fd;

	ft_printf("Allocating map memory...\n");
	if (!allocate_map(map, file))
	{
		ft_printf("Failed to allocate map memory\n");
		return (0);
	}
	ft_printf("Opening map file...\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Failed to open map file\n");
		return (0);
	}
	ft_printf("Reading map lines...\n");
	if (!read_map_lines(map, fd))
	{
		close(fd);
		return (0);
	}
	close(fd);
	ft_printf("Map loaded successfully\n");
	return (1);
}

static int	check_map_requirements(t_map *map)
{
	if (map->collectibles == 0)
		ft_printf("Error: No collectibles found\n");
	if (map->exit != 1)
		ft_printf("Error: Must have exactly one exit (found %d)\n", map->exit);
	if (map->player != 1)
		ft_printf("Error: Must have exactly one player (found %d)\n", map->player);
	return (map->collectibles > 0 && map->exit == 1 && map->player == 1);
}

int	validate_map(t_map *map)
{
	int	i;
	int	j;

	map->collectibles = 0;
	map->exit = 0;
	map->player = 0;
	i = 0;
	while (map->grid[i])
	{
		if (ft_strlen(map->grid[i]) != (size_t)map->width)
			return (0);
		j = 0;
		while (map->grid[i][j])
		{
			if (!check_map_chars(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	ft_printf("Map stats: %d collectibles, %d exits, %d players\n",
		map->collectibles, map->exit, map->player);
	return (check_map_requirements(map));
}
