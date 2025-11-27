/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/09/26 16:51:18 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	deg_to_rad(float n)
{
	return (n * PI / 180.0);
}

float	normalize_angle(float angle)
{
	while (angle < 0)
		angle += 360;
	while (angle >= 360)
		angle -= 360;
	return (angle);
}

float	should_render(t_data	*data)
{
	struct timeval	current_time;
	double			elapsed;

	gettimeofday(&current_time, NULL);
	if (data->last_render.tv_sec == 0 && data->last_render.tv_usec == 0)
	{
		data->last_render = current_time;
		return (1);
	}
	elapsed = (current_time.tv_sec - data->last_render.tv_sec)
		+ (current_time.tv_usec - data->last_render.tv_usec)
		/ 1000000.0;
	if (elapsed >= 1 / LIMIT_FPS)
	{
		data->last_render = current_time;
		data->last_frame_time = elapsed;
		return (1);
	}
	return (0);
}

void	clear_image(t_data	*data)
{
	ft_memset(data->img_data, 0, data->win_height
		* data->line_length);
}

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rows)
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
}
