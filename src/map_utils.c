#include "../includes/so_long.h"

/* Count number of lines in file */
static int  count_lines(char *file)
{
    int         fd;
    int         lines;
    char        *line;

    lines = 0;
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    while ((line = get_next_line(fd)))
    {
        lines++;
        free(line);
    }
    close(fd);
    return (lines);
}

/* Allocate memory for map structure */
int         allocate_map(t_map *map, char *file)
{
    int     height;

    height = count_lines(file);
    if (height <= 0)
        return (0);
    map->grid = (char **)malloc(sizeof(char *) * (height + 1));
    if (!map->grid)
        return (0);
    map->height = height;
    map->width = 0;
    map->collectibles = 0;
    map->exit = 0;
    map->player = 0;
    return (1);
}

/* Check and count map characters */
int         check_map_chars(t_map *map, int i, int j)
{
    if (map->grid[i][j] == 'C')
        map->collectibles++;
    else if (map->grid[i][j] == 'E')
        map->exit++;
    else if (map->grid[i][j] == 'P')
        map->player++;
    else if (map->grid[i][j] != '0' && map->grid[i][j] != '1' && map->grid[i][j] != 'X')
    {
        ft_printf("Invalid character '%c' at position (%d,%d)\n",
            map->grid[i][j], j, i);
        return (0);
    }
    return (1);
}