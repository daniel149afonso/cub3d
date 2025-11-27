/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/09/25 18:57:04 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_pxl(t_data	*data, int player_x, int player_y)
{
	int	steps;
	int	step;
	int	line_x;
	int	line_y;

	steps = data->mini_tile_size;
	step = -1;
	while (++step <= steps)
	{
		line_x = player_x + ((data->dx - player_x) * step) / steps;
		line_y = player_y + ((data->dy - player_y) * step) / steps;
		put_pixel_to_img(data, line_x, line_y, COLOR_GREEN);
	}
}

static void	draw_player_at_position(t_data *data, int map_x, int map_y)
{
	int	radius;
	int	player_x;
	int	player_y;

	player_x = map_x + (int)(data->player.x * data->mini_tile_size);
	player_y = map_y + (int)(data->player.y * data->mini_tile_size);
	radius = data->mini_tile_size / 3;
	data->i = -radius - 1;
	while (++data->i <= radius)
	{
		data->j = -radius - 1;
		while (++data->j <= radius)
			if (pow(data->i, 2) + pow(data->j, 2) <= pow(radius, 2))
				put_pixel_to_img(data, player_x + data->j,
					player_y + data->i, COLOR_RED);
	}
	data->dx = player_x + cos(data->player.angle * PI / 180.0)
		* data->mini_tile_size;
	data->dy = player_y + sin(data->player.angle * PI / 180)
		* data->mini_tile_size;
	draw_pxl(data, player_x, player_y);
}

static void	set_color(t_data	*data, int x, int y)
{
	if (data->map[y][x] == '1')
		data->color = COLOR_WHITE;
	else if (data->map[y][x] == 'D')
		data->color = COLOR_DARK_YELLOW;
	else
		data->color = COLOR_BLACK;
}

void	render_minimap(t_data	*data)
{
	int				map_x;
	int				map_y;

	data->mini_tile_size = 10;
	map_y = 20;
	map_x = WIDTH - data->cols * data->mini_tile_size - map_y;
	data->y = -1;
	while (++data->y < data->rows)
	{
		data->x = -1;
		while (++data->x < data->cols)
		{
			set_color(data, data->x, data->y);
			data->i = -1;
			while (++data->i < data->mini_tile_size)
			{
				data->j = -1;
				while (++data->j < data->mini_tile_size)
					put_pixel_to_img(data, map_x + data->x
						* data->mini_tile_size + data->j, map_y + data->y
						* data->mini_tile_size + data->i, data->color);
			}
		}
	}
	draw_player_at_position(data, map_x, map_y);
}
