/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/10/17 16:52:09 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_position(t_data *data)
{
	double	margin;
	double	x;
	double	y;

	margin = 0.15;
	x = data->player.new_x;
	y = data->player.new_y;
	data->left = (int)(x - margin);
	data->right = (int)(x + margin);
	data->top = (int)(y - margin);
	data->bottom = (int)(y + margin);
	if (data->left < 0 || data->right >= data->cols || data->top < 0
		|| data->bottom >= data->rows)
		return (0);
	if (data->map[data->top][data->left] == '1'
		|| data->map[data->top][data->right] == '1'
		|| data->map[data->bottom][data->left] == '1'
		|| data->map[data->bottom][data->right] == '1')
		return (0);
	return (1);
}

void	walk(t_data	*data, char direction)
{
	if (direction == 'w')
	{
		data->player.new_x = data->player.x + data->player.dir_x
			* MOVE_SPEED;
		data->player.new_y = data->player.y + data->player.dir_y
			* MOVE_SPEED;
	}
	else if (direction == 's')
	{
		data->player.new_x = data->player.x - data->player.dir_x
			* MOVE_SPEED;
		data->player.new_y = data->player.y - data->player.dir_y
			* MOVE_SPEED;
	}
}

void	strafe(t_data	*data, char direction)
{
	if (direction == 'a')
	{
		data->player.new_x = data->player.x
			+ (sin(deg_to_rad(data->player.angle))) * MOVE_SPEED;
		data->player.new_y = data->player.y
			+ (-cos(deg_to_rad(data->player.angle))) * MOVE_SPEED;
	}
	else if (direction == 'd')
	{
		data->player.new_x = data->player.x
			+ (-sin(deg_to_rad(data->player.angle))) * MOVE_SPEED;
		data->player.new_y = data->player.y
			+ (cos(deg_to_rad(data->player.angle))) * MOVE_SPEED;
	}
}
