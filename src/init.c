/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/10/21 18:50:14 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	ft_memset(data, 0, sizeof(t_data));
	return (data);
}

t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	return (ray);
}

void	init_map(t_data	*data, int rows, int cols)
{
	data->i = -1;
	while (++data->i < 2)
	{
		data->ceiling_rgb[++data->i] = -1;
		data->floor_rgb[++data->i] = -1;
	}
	data->cols = cols;
	data->rows = rows;
}

void	init_graphics(t_data	*data)
{
	data->win_width = WIDTH;
	data->win_height = HEIGHT;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->win_width,
			data->win_height, "cub3D");
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->img_data = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->tile_width = TILE_SIZE;
	data->tile_height = TILE_SIZE;
	if (data->rows >= data->cols)
		data->view_distance = data->rows;
	else
		data->view_distance = data->cols;
}

/*Initialise les valeurs pour un rayon horizontal (h) ou vertical (v)*/
void	init_ray_values(t_ray	*ray, char axis)
{
	ray->dof = 0;
	if (axis == 'h')
	{
		ray->dist_hor = 100000;
		ray->tan_val = 1.0 / tan(deg_to_rad(ray->angle));
	}
	else if (axis == 'v')
	{
		ray->dist_ver = 100000;
		ray->tan_val = tan(deg_to_rad(ray->angle));
	}
}
