/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/09/08 21:49:19 by scuthber      ###   ########.fr          */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	focus_in(t_data	*data)
{
	data->mouse.window_focused = 1;
	mlx_mouse_hide(data->mlx, data->mlx_win);
	mlx_mouse_move(data->mlx, data->mlx_win,
		data->mouse.cx,
		data->mouse.cy);
	data->mouse.warp_pending = 1;
	return (0);
}

int	focus_out(t_data	*data)
{
	data->mouse.window_focused = 0;
	mlx_mouse_show(data->mlx, data->mlx_win);
	return (0);
}

void	toggle_mouse(t_data	*data)
{
	data->mouse.enabled = !data->mouse.enabled;
	if (data->mouse.enabled)
	{
		mlx_mouse_hide(data->mlx, data->mlx_win);
		mlx_mouse_move(data->mlx, data->mlx_win, data->mouse.cx,
			data->mouse.cy);
		data->mouse.warp_pending = 1;
	}
	else
		mlx_mouse_show(data->mlx, data->mlx_win);
}

void	mouse_look(t_data	*data)
{
	int			dx;
	const int	cx = data->mouse.cx;
	const int	cy = data->mouse.cy;

	if (!data->mouse.window_focused || !data->mouse.enabled)
		return ;
	mlx_mouse_get_pos(data->mlx, data->mlx_win, &data->x, &data->y);
	if (data->mouse.warp_pending)
	{
		data->mouse.warp_pending = 0;
		return ;
	}
	dx = data->x - cx;
	if (dx)
	{
		data->player.angle = normalize_angle(
				data->player.angle + dx * MOUSE_SENS);
		data->need_render = 1;
	}
	if (data->x != cx || data->y != cy)
	{
		data->mouse.warp_pending = 1;
		mlx_mouse_move(data->mlx, data->mlx_win, cx, cy);
	}
}

void	init_mouse(t_data	*data)
{
	data->mouse.cx = data->win_width / 2;
	data->mouse.cy = data->win_height / 2;
	data->mouse.warp_pending = 0;
	data->mouse.window_focused = 1;
	data->mouse.enabled = 1;
	mlx_mouse_hide(data->mlx, data->mlx_win);
	mlx_mouse_move(data->mlx, data->mlx_win,
		data->mouse.cx, data->mouse.cy);
}
