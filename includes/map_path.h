/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromatitien <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:01:35 by afromatitien      #+#    #+#             */
/*   Updated: 2025/05/24 12:01:35 by afromatitien     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PATH_H
# define MAP_PATH_H

# include "so_long.h"

int		check_reachable_items(t_map *map, char **visited);
void	free_visited(char **visited, int height);

#endif
