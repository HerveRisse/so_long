/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:43:47 by hrisse            #+#    #+#             */
/*   Updated: 2025/05/28 15:43:57 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PATH_H
# define MAP_PATH_H

# include "so_long.h"

int		check_reachable_items(t_map *map, char **visited);
void	free_visited(char **visited, int height);

#endif
