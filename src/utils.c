#include "../includes/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (map->grid[i])
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
}

void	error_exit(char *message)
{
	ft_printf("Error: %s\n", message);
	exit(1);
}
