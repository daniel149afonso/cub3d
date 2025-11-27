/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/09/20 21:03:33 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keypress_handler(int keycode, t_data	*data)
{
	if (keycode == KEY_ESC)
		close_game(data);
	if (keycode == KEY_W || keycode == KEY_UP)
		data->moving_f = 1;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		data->moving_b = 1;
	if (keycode == KEY_A)
		data->moving_l = 1;
	if (keycode == KEY_D)
		data->moving_r = 1;
	if (keycode == KEY_LEFT)
		data->rota_l = 1;
	if (keycode == KEY_RIGHT)
		data->rota_r = 1;
	if (keycode == KEY_M)
		toggle_mouse(data);
	return (0);
}

int	keyrelease_handler(int keycode, t_data	*data)
{
	if (keycode == KEY_ESC)
		close_game(data);
	if (keycode == KEY_W || keycode == KEY_UP)
		data->moving_f = 0;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		data->moving_b = 0;
	if (keycode == KEY_A)
		data->moving_l = 0;
	if (keycode == KEY_D)
		data->moving_r = 0;
	if (keycode == KEY_LEFT)
		data->rota_l = 0;
	if (keycode == KEY_RIGHT)
		data->rota_r = 0;
	return (0);
}
