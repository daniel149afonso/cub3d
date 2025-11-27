/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/10/17 17:13:07 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Choisit quelle fonction ci-dessus appeler (porte / vertical / horizontal).*/
static void	select_texture(t_data *data, t_tex **tex, t_draw *d)
{
	if (data->ray->hit_tile == 'D')
		select_door(data, tex, d);
	else if (data->ray->dist_ver < data->ray->dist_hor)
		select_vertical(data, tex, d);
	else
		select_horizontal(data, tex, d);
	if (d->tex_x < 0)
		d->tex_x = 0;
	if (d->tex_x >= (*tex)->width)
		d->tex_x = (*tex)->width - 1;
}

static void	draw_wall_tex(t_data *data, int x, int line_off, int line_height)
{
	t_tex	*tex;
	t_draw	d;

	d.x = x;
	d.line_off = line_off;
	d.line_height = line_height;
	select_texture(data, &tex, &d);
	draw_texture_line(data, tex, &d);
}

static void	calc_wall(t_data *data, int x)
{
	int		line_height;
	int		line_off;
	float	wall_dist;

	data->cast_angle = (normalize_angle(data->player.angle - data->ray->angle));
	if (data->ray->dist_ver < data->ray->dist_hor)
		wall_dist = data->ray->dist_ver * cos(deg_to_rad(data->cast_angle));
	else
		wall_dist = data->ray->dist_hor * cos(deg_to_rad(data->cast_angle));
	if (wall_dist < 0.1)
		wall_dist = 0.1;
	line_height = (data->tile_height * HEIGHT) / wall_dist;
	line_off = (HEIGHT / 2) - (line_height / 2);
	data->y = -1;
	while (++data->y < HEIGHT)
	{
		if (data->y < line_off)
			put_pixel_to_img(data, x, data->y, data->ceiling_color);
		else if (data->y >= line_off && data->y < line_off + line_height)
			draw_wall_tex(data, x, line_off, line_height);
		else
			put_pixel_to_img(data, x, data->y, data->floor_color);
	}
}

void	ray_casting(t_data	*data)
{
	float	angle_step;
	float	half_fov;

	clear_image(data);
	data->px = data->player.x * data->tile_width;
	data->py = data->player.y * data->tile_height;
	half_fov = FOV / 2.0;
	angle_step = (float)FOV / (WIDTH - 1);
	data->i = -1;
	while (++data->i < WIDTH)
	{
		data->ray->angle = normalize_angle(data->player.angle - half_fov
				+ angle_step
				* data->i);
		data->ray->dist_hor = 100000;
		data->ray->dist_ver = 100000;
		vertical_ray(data);
		horizontal_ray(data);
		find_hit_point(data->ray, data);
		calc_wall(data, data->i);
	}
	render_minimap(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
