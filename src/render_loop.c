/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:02:46 by daniel149af       #+#    #+#             */
/*   Updated: 2025/10/23 14:42:44 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	time_diff_sec(struct timeval *a, struct timeval *b)
{
	return ((double)(a->tv_sec - b->tv_sec)
		+ (double)(a->tv_usec - b->tv_usec) / 1000000.0);
}

int	render_frame(void *arg)
{
	t_data			*data;
	struct timeval	now;
	double			delta;

	data = (t_data *)arg;
	gettimeofday(&now, NULL);
	if (data->last_render.tv_sec == 0 && data->last_render.tv_usec == 0)
		delta = 1.0 / 60.0;
	else
		delta = time_diff_sec(&now, &data->last_render);
	data->last_render = now;
	data->last_frame_time = delta;
	update_doors(data);
	ray_casting(data);
	return (0);
}
