/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:51:12 by hrisse            #+#    #+#             */
/*   Updated: 2025/05/28 15:51:19 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/get_next_line.h"

/*
** Counts number of lines in map file
** Returns 0 if file cannot be opened
*/
static int	count_lines(char *file)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

/*
** Validates map character and updates counters
** Returns 1 if valid, 0 otherwise
*/
int	check_map_chars(t_map *map, int i, int j)
{
	char	c;

	c = map->grid[i][j];
	if (c == '0' || c == '1')
		return (1);
	else if (c == 'C')
		map->collectibles++;
	else if (c == 'E')
		map->exit++;
	else if (c == 'P')
		map->player++;
	else
	{
		ft_printf("Error\nInvalid character '%c' at position (%d,%d)\n",
			c, i, j);
		return (0);
	}
	return (1);
}

/*
** Initializes map structure and counters
** Returns 1 if successful, 0 if error
*/
int	allocate_map(t_map *map, char *file)
{
	map->height = count_lines(file);
	if (map->height < 3)
		return (0);
	map->grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (0);
	map->collectibles = 0;
	map->exit = 0;
	map->player = 0;
	return (1);
}
