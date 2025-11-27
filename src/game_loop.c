/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/10/23 14:45:22 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	movement(t_data	*data)
{
	if (data->moving_f)
		move(data, 'w');
	if (data->moving_b)
		move(data, 's');
	if (data->moving_l)
		move(data, 'a');
	if (data->moving_r)
		move(data, 'd');
}

static void	rotation(t_data	*data)
{
	if (data->rota_l)
		rotate_player(data, 'l');
	if (data->rota_r)
		rotate_player(data, 'r');
}

static double	time_diff_sec(struct timeval *a, struct timeval *b)
{
	return ((double)(a->tv_sec - b->tv_sec)
		+ (double)(a->tv_usec - b->tv_usec) / 1000000.0);
}

int	game_loop(t_data *data)
{
	struct timeval	now;
	double			delta;

	gettimeofday(&now, NULL);
	if (data->last_render.tv_sec == 0 && data->last_render.tv_usec == 0)
		delta = 1.0 / 60.0;
	else
		delta = time_diff_sec(&now, &data->last_render);
	data->last_render = now;
	data->last_frame_time = delta;
	mouse_look(data);
	movement(data);
	rotation(data);
	update_doors(data);
	if ((data->need_render) && should_render(data))
	{
		ray_casting(data);
		data->need_render = 0;
	}
	else
		ray_casting(data);
	return (0);
}
