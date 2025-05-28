/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:44:06 by hrisse            #+#    #+#             */
/*   Updated: 2025/05/28 15:44:18 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

# define TILE_SIZE 32
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		exit;
	int		player;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collectible;
	t_map	map;
	int		player_x;
	int		player_y;
	int		moves;
}			t_game;

/* Map functions */
int		parse_map(t_map *map, char *file);
int		validate_map(t_map *map);
int		allocate_map(t_map *map, char *file);
int		check_map_chars(t_map *map, int i, int j);
int		check_map_requirements(t_map *map);
char	**create_visited_map(t_map *map);
int		read_map_lines(t_map *map, char *file);

/* Game functions */
int		init_game(t_game *game);
int		handle_key(int keycode, t_game *game);
int		close_game(t_game *game);

/* Display functions */
void	draw_tile(t_game *game, void *img, int x, int y);
void	display_message(t_game *game, char *message);
void	draw_map(t_game *game);
int		load_images(t_game *game);

/* Movement functions */
void	find_player_pos(t_game *game);
int		move_player(t_game *game, int new_x, int new_y);
void	update_position(int keycode, int *x, int *y);

/* Utils */
void	free_map(t_map *map);
void	error_exit(char *message);

#endif
