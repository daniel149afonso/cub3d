/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/07/21 14:10:40 by scuthber         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_data	*data, char direction)
{
	data->player.dir_x = cos(deg_to_rad(data->player.angle));
	data->player.dir_y = sin(deg_to_rad(data->player.angle));
	walk(data, direction);
	strafe(data, direction);
	if (is_valid_position(data))
		data->player.x = data->player.new_x;
	if (is_valid_position(data))
		data->player.y = data->player.new_y;
	data->need_render = 1;
}

void	rotate_player(t_data	*data, char direction)
{
	if (direction == 'l')
		data->player.angle -= ROTATION_SPEED;
	else if (direction == 'r')
		data->player.angle += ROTATION_SPEED;
	data->player.angle = normalize_angle(data->player.angle);
	data->need_render = 1;
}
