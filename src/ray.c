/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/10/21 18:49:06 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_pos(t_data *data, char dir)
{
	if (check_hit(data))
		handle_hit(data, dir);
	else
	{
		data->ray->x += data->ray->x_off;
		data->ray->y += data->ray->y_off;
		data->ray->dof++;
	}
}

static void	set_default(t_data	*data)
{
	data->ray->x = data->px;
	data->ray->y = data->py;
	data->ray->dof = data->view_distance;
}

void	horizontal_ray(t_data	*data)
{
	init_ray_values(data->ray, 'h');
	if (sin(deg_to_rad(data->ray->angle)) > 0.001)
	{
		data->ray->y = ((int)(data->py / data->tile_height) + 1)
			* data->tile_height;
		data->ray->x = data->px + (data->ray->y - data->py)
			* data->ray->tan_val;
		data->ray->y_off = data->tile_height;
		data->ray->x_off = data->tile_height * data->ray->tan_val;
	}
	else if (sin(deg_to_rad(data->ray->angle)) < -0.001)
	{
		data->ray->y = ((int)(data->py / data->tile_height))
			* data->tile_height - 0.0001;
		data->ray->x = data->px + (data->ray->y - data->py)
			* data->ray->tan_val;
		data->ray->y_off = -data->tile_height;
		data->ray->x_off = -data->tile_height * data->ray->tan_val;
	}
	else
		set_default(data);
	while (data->ray->dof < data->view_distance)
		calc_pos(data, 'h');
}

void	vertical_ray(t_data	*data)
{
	init_ray_values(data->ray, 'v');
	if (cos(deg_to_rad(data->ray->angle)) > 0.001)
	{
		data->ray->x = ((int)(data->px / data->tile_width) + 1)
			* data->tile_width;
		data->ray->y = data->py + (data->ray->x - data->px)
			* data->ray->tan_val;
		data->ray->x_off = data->tile_width;
		data->ray->y_off = data->tile_width * data->ray->tan_val;
	}
	else if (cos(deg_to_rad(data->ray->angle)) < -0.001)
	{
		data->ray->x = ((int)(data->px / data->tile_width))
			* data->tile_width - 1.0;
		data->ray->y = data->py + (data->ray->x - data->px)
			* data->ray->tan_val;
		data->ray->x_off = -data->tile_width;
		data->ray->y_off = -data->tile_width * data->ray->tan_val;
	}
	else
		set_default(data);
	while (data->ray->dof < data->view_distance)
		calc_pos(data, 'v');
}
