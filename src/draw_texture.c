/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:24:13 by scuthber          #+#    #+#             */
/*   Updated: 2025/10/23 15:50:32 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Calcule les pixels de l'image*/
static int	get_pixel(t_tex *tex, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (-1);
	dst = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

static void	put_pxl(t_data	*data, t_draw	*d)
{
	data->y = d->line_off - 1;
	while (++data->y < d->line_off + d->line_height && data->y < HEIGHT)
	{
		if (data->y < HEIGHT / 2)
			put_pixel_to_img(data, d->x, data->y, data->ceiling_color);
		else
			put_pixel_to_img(data, d->x, data->y, data->floor_color);
	}
}

static void	draw_pixel(t_data *data, t_tex *tex, t_draw *d)
{
	data->y = d->draw_start - 1;
	while (++data->y <= d->draw_end)
	{
		d->tex_y = (int)tex->tex_pos;
		if (d->tex_y >= tex->height)
			d->tex_y = tex->height - 1;
		if (d->tex_y < 0)
			d->tex_y = 0;
		data->color = get_pixel(tex, d->tex_x, d->tex_y);
		if (data->color == 0xFF00FF)
			data->color = data->ceiling_color;
		if (data->color != -1)
			put_pixel_to_img(data, d->x, data->y, data->color);
		tex->tex_pos += d->step;
	}
}

/*Dessine la colonne verticale de pixels correspondant au rayon.*/
void	draw_texture_line(t_data *data, t_tex *tex, t_draw *d)
{
	if (d->tex_x == -1)
	{
		put_pxl(data, d);
		return ;
	}
	d->draw_start = d->line_off;
	if (d->draw_start < 0)
		d->draw_start = 0;
	d->draw_end = d->line_off + d->line_height;
	if (d->draw_end >= HEIGHT)
		d->draw_end = HEIGHT - 1;
	d->step = (float)tex->height / d->line_height;
	if (d->line_height > HEIGHT)
		tex->tex_pos = ((d->line_height - HEIGHT) / 2) * d->step;
	else
	{
		tex->tex_pos = 0;
		if (d->line_off < 0)
			tex->tex_pos = -d->line_off * d->step;
	}
	draw_pixel(data, tex, d);
}
