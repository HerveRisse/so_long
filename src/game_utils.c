/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromatitien <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:01:35 by afromatitien      #+#    #+#             */
/*   Updated: 2025/05/24 12:01:35 by afromatitien     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_position(int keycode, int *x, int *y)
{
	if (keycode == KEY_W)
		(*y)--;
	else if (keycode == KEY_S)
		(*y)++;
	else if (keycode == KEY_A)
		(*x)--;
	else if (keycode == KEY_D)
		(*x)++;
}
