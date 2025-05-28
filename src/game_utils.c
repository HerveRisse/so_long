/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:48:11 by hrisse            #+#    #+#             */
/*   Updated: 2025/05/28 15:48:16 by hrisse           ###   ########.fr       */
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
