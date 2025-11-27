/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/10/17 17:36:38 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Détermine où le rayon a touché (mur, porte, etc.).*/
void	find_hit_point(t_ray *ray, t_data *data)
{
	int	mx;
	int	my;

	if (ray->dist_hor <= 0.001)
		ray->dist_hor = 100000;
	if (ray->dist_ver <= 0.001)
		ray->dist_ver = 100000;
	if (ray->dist_ver < ray->dist_hor)
	{
		ray->final_hit_x = ray->ver_hit_x;
		ray->final_hit_y = ray->ver_hit_y;
	}
	else
	{
		ray->final_hit_x = ray->hor_hit_x;
		ray->final_hit_y = ray->hor_hit_y;
	}
	mx = (int)(ray->final_hit_x / data->tile_width);
	my = (int)(ray->final_hit_y / data->tile_height);
	if (my >= 0 && my < data->rows && mx >= 0 && mx < data->cols)
		ray->hit_tile = data->map[my][mx];
	else
		ray->hit_tile = ' ';
}

static void	select_door_next(t_data *data, t_tex **tex, t_draw *d)
{
	if (data->ratio < data->half)
		data->ratio = (data->ratio / (data->half - data->state * 0.5)) * 0.5;
	else
		data->ratio = 0.5 + ((data->ratio - (data->half + data->state * 0.5))
				/ (1.0 - (data->half + data->state * 0.5))) * 0.5;
	if (data->ratio < 0.0)
		data->ratio = 0.0;
	if (data->ratio > 1.0)
		data->ratio = 1.0;
	d->tex_x = (int)(data->ratio * (*tex)->width);
	if (d->tex_x < 0)
		d->tex_x = 0;
	if (d->tex_x >= (*tex)->width)
		d->tex_x = (*tex)->width - 1;
}

/*Choisit la texture de la porte et calcule quelle colonne de la tex afficher*/
void	select_door(t_data *data, t_tex **tex, t_draw *d)
{
	data->mx = (int)(data->ray->final_hit_x / data->tile_width);
	data->my = (int)(data->ray->final_hit_y / data->tile_height);
	data->state = get_door_state(data, data->mx, data->my);
	*tex = &data->image.door;
	if (data->ray->dist_ver < data->ray->dist_hor)
		data->offset = fmod(data->ray->final_hit_y, data->tile_height);
	else
		data->offset = fmod(data->ray->final_hit_x, data->tile_width);
	data->ratio = data->offset / data->tile_width;
	data->half = 0.5;
	if (data->ratio > (data->half - data->state * 0.5)
		&& data->ratio < (data->half + data->state * 0.5))
	{
		d->tex_x = -1;
		return ;
	}
	select_door_next(data, tex, d);
}

/*Choisit la texture Est ou Ouest (mur vertical).*/
void	select_vertical(t_data *data, t_tex **tex, t_draw *d)
{
	double	offset;

	if (cos(deg_to_rad(data->ray->angle)) > 0)
		*tex = &data->image.east;
	else
		*tex = &data->image.west;
	offset = fmod(data->ray->final_hit_y, data->tile_height);
	d->tex_x = (int)((offset / data->tile_height) * (*tex)->width);
}

/*Choisit la texture Nord ou Sud (mur horizontal).*/
void	select_horizontal(t_data *data, t_tex **tex, t_draw *d)
{
	double	offset;

	if (sin(deg_to_rad(data->ray->angle)) > 0)
		*tex = &data->image.south;
	else
		*tex = &data->image.north;
	offset = fmod(data->ray->final_hit_x, data->tile_width);
	d->tex_x = (int)((offset / data->tile_width) * (*tex)->width);
}
