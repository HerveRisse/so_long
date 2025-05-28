/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:49:04 by hrisse            #+#    #+#             */
/*   Updated: 2025/05/28 15:49:10 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/get_next_line.h"

static int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
		{
			ft_printf("Error\nMap must be surrounded by walls\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
		{
			ft_printf("Error\nMap must be surrounded by walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_rectangle(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->grid[i]) != map->width)
		{
			ft_printf("Error\nMap must be rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_map(t_map *map)
{
	int	i;
	int	j;

	if (!check_rectangle(map))
		return (0);
	if (!check_walls(map))
		return (0);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!check_map_chars(map, i, j))
			{
				ft_printf("Error\nInvalid character in map\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (check_map_requirements(map));
}

/*
** Reads and parses the map file
** Validates it according to game rules
** Returns 1 if successful, 0 if error
*/
int	parse_map(t_map *map, char *file)
{
	if (!read_map_lines(map, file))
		return (0);
	return (validate_map(map));
}
