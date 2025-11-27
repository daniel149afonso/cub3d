/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/10/21 18:49:39 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Check les collision mûrs et l'etat porte
si porte state >= 90% ouvert la porte devient passable*/
int	check_hit(t_data *data)
{
	data->mx = (int)(data->ray->x / data->tile_width);
	data->my = (int)(data->ray->y / data->tile_height);
	if (data->my < 0 || data->my >= data->rows || data->mx < 0
		|| data->mx >= data->cols)
		return (1);
	data->tile = data->map[data->my][data->mx];
	if (data->tile == '1')
		return (1);
	if (data->tile == 'D')
	{
		data->state = get_door_state(data, data->mx, data->my);
		if (data->ray->dist_ver < data->ray->dist_hor)
			data->offset = fmod(data->ray->y, data->tile_height);
		else
			data->offset = fmod(data->ray->x, data->tile_width);
		data->ratio = data->offset / data->tile_width;
		data->half = 0.5;
		if (data->ratio > (data->half - data->state * 0.5)
			&& data->ratio < (data->half + data->state * 0.5))
			return (0);
		if (data->state < 0.8)
			return (1);
		return (1);
	}
	return (0);
}

static int	door_hit(t_data	*data, char dir)
{
	data->tile = data->map[data->my][data->mx];
	if (data->tile == 'D')
	{
		data->state = get_door_state(data, data->mx, data->my);
		if (dir == 'h')
			data->offset = fmod(data->ray->x, data->tile_width);
		else
			data->offset = fmod(data->ray->y, data->tile_height);
		data->ratio = data->offset / data->tile_width;
		data->half = 0.5;
		if (data->ratio > (data->half - data->state * 0.5)
			&& data->ratio < (data->half + data->state * 0.5))
		{
			data->ray->x += data->ray->x_off;
			data->ray->y += data->ray->y_off;
			data->ray->dof++;
			return (-1);
		}
	}
	data->dx = data->ray->x - data->px;
	data->dy = data->ray->y - data->py;
	return (1);
}

void	handle_hit(t_data	*data, char dir)
{
	data->mx = (int)(data->ray->x / data->tile_width);
	data->my = (int)(data->ray->y / data->tile_height);
	if (data->mx < 0 || data->mx >= data->cols || data->my < 0
		|| data->my >= data->rows)
	{
		data->dx = data->ray->x - data->px;
		data->dy = data->ray->y - data->py;
	}
	else
		if (door_hit(data, dir) == -1)
			return ;
	if (dir == 'h')
	{
		data->ray->hor_hit_x = data->ray->x;
		data->ray->hor_hit_y = data->ray->y;
		data->ray->dist_hor = sqrt(data->dx * data->dx + data->dy * data->dy);
	}
	else if (dir == 'v')
	{
		data->ray->ver_hit_x = data->ray->x;
		data->ray->ver_hit_y = data->ray->y;
		data->ray->dist_ver = sqrt(data->dx * data->dx + data->dy * data->dy);
	}
	data->ray->dof = data->view_distance;
}
