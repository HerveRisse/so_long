/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:50:35 by hrisse            #+#    #+#             */
/*   Updated: 2025/05/28 15:50:40 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/get_next_line.h"

static int	process_line(t_map *map, char *line, int i)
{
	char	*temp;

	if (!line)
		return (0);
	temp = ft_strchr(line, '\n');
	if (temp)
		*temp = '\0';
	map->grid[i] = ft_strdup(line);
	free(line);
	if (!map->grid[i])
	{
		ft_printf("Error\nMemory allocation failed\n");
		return (0);
	}
	if (i == 0)
		map->width = ft_strlen(map->grid[i]);
	else if ((int)ft_strlen(map->grid[i]) != map->width)
	{
		ft_printf("Error\nMap must be rectangular\n");
		return (0);
	}
	return (1);
}

static int	check_extra_content(int fd, t_map *map, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
	{
		ft_printf("Error\nExtra content after map\n");
		free(line);
		close(fd);
		return (0);
	}
	map->grid[i] = NULL;
	close(fd);
	return (1);
}

static int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		perror("Cannot open map file");
		return (-1);
	}
	return (fd);
}

static int	process_map_line(t_map *map, int fd, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (!line && i < map->height - 1)
	{
		ft_printf("Error\nUnexpected end of file\n");
		close(fd);
		return (0);
	}
	if (!process_line(map, line, i))
	{
		close(fd);
		return (0);
	}
	return (1);
}

int	read_map_lines(t_map *map, char *filename)
{
	int	fd;
	int	i;

	fd = open_map_file(filename);
	if (fd < 0)
		return (0);
	i = 0;
	while (i < map->height)
	{
		if (!process_map_line(map, fd, i))
			return (0);
		i++;
	}
	return (check_extra_content(fd, map, i));
}
