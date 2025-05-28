/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:50:20 by hrisse            #+#    #+#             */
/*   Updated: 2025/05/28 15:50:26 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

static void	check_adjacent(t_map *map, int x, int y, char **visited)
{
	if (x >= 0 && y >= 0 && x < map->width && y < map->height
		&& visited[y][x] != '1')
	{
		visited[y][x] = '1';
		if (map->grid[y][x] == 'C')
			map->collectibles--;
		else if (map->grid[y][x] == 'E')
			map->exit--;
		check_adjacent(map, x + 1, y, visited);
		check_adjacent(map, x - 1, y, visited);
		check_adjacent(map, x, y + 1, visited);
		check_adjacent(map, x, y - 1, visited);
	}
}

void	free_visited(char **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

static void	find_start_position(t_map *map, int *x, int *y)
{
	*x = 0;
	*y = 0;
	while (*y < map->height)
	{
		*x = 0;
		while (*x < map->width)
		{
			if (map->grid[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

int	check_reachable_items(t_map *map, char **visited)
{
	int	start_x;
	int	start_y;
	int	initial_collectibles;
	int	initial_exit;

	initial_collectibles = map->collectibles;
	initial_exit = map->exit;
	find_start_position(map, &start_x, &start_y);
	check_adjacent(map, start_x, start_y, visited);
	if (map->collectibles > 0 || map->exit > 0)
	{
		ft_printf("Error\nNot all items are reachable\n");
		free_visited(visited, map->height);
		return (0);
	}
	map->collectibles = initial_collectibles;
	map->exit = initial_exit;
	return (1);
}
