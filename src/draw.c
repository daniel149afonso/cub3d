/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/09/30 19:41:39 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	convert_color(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (data->ceiling_rgb[i] < 0 || data->floor_rgb[i] <= 0)
		{
			ft_printf("Error\nMissing floor or ceiling color\n");
			free_data(data);
			exit(1);
		}
	}
	data->floor_color = rgb_to_int(data->floor_rgb[0],
			data->floor_rgb[1], data->floor_rgb[2]);
	data->ceiling_color = rgb_to_int(data->ceiling_rgb[0],
			data->ceiling_rgb[1], data->ceiling_rgb[2]);
}

void	put_pixel_to_img(t_data	*data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < data->win_width && y >= 0
		&& y < data->win_height)
	{
		dst = data->img_data + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static int	calc_cur(t_data	*data, int n, int cur_n, char axis)
{
	int	dn;

	if (cur_n == n)
		return (cur_n);
	if (axis == 'x')
		dn = data->dy;
	else if (axis == 'y')
		dn = data->dx;
	data->err += dn;
	if (cur_n < n)
		cur_n++;
	else
		cur_n--;
	return (cur_n);
}

void	draw_line(t_data	*data, int x, int y)
{
	int	cur_x;
	int	cur_y;

	cur_x = data->px;
	cur_y = data->py;
	data->dx = abs(x - cur_x);
	data->dy = -abs(y - cur_y);
	data->err = data->dx + data->dy;
	while (cur_x != x || cur_y != y)
	{
		put_pixel_to_img(data, cur_x, cur_y, data->color);
		if (cur_x == x && cur_y == y)
			break ;
		data->e2 = 2 * data->err;
		if (data->e2 >= data->dy && cur_x != x)
		{
			cur_x = calc_cur(data, x, cur_x, 'x');
		}
		if (data->e2 <= data->dx && cur_y != y)
		{
			cur_y = calc_cur(data, y, cur_y, 'y');
		}
	}
}
