/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:19:04 by daniel149af       #+#    #+#             */
/*   Updated: 2025/10/23 14:42:07 by scuthber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	distance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

/*Mets à jour l'etat(open or close) de la porte en fonction
de la distance au joueur*/
void	update_doors(t_data *data)
{
	int		i;
	double	dist;
	t_door	*d;

	i = -1;
	while (++i < data->door_count)
	{
		d = &data->doors[i];
		dist = distance(data->player.x, data->player.y,
				d->x + 0.5, d->y + 0.5);
		if (dist < 2.0)
			d->opening = 1;
		else if (dist > 3.0)
			d->opening = 0;
		if (d->opening && d->state < 1.0)
			d->state += 0.04;
		else if (!d->opening && d->state > 0.0)
			d->state -= 0.04;
		if (d->state < 0.0)
			d->state = 0.0;
		if (d->state > 1.0)
			d->state = 1.0;
	}
}

void	init_doors(t_data *data)
{
	int	y;
	int	x;

	data->door_count = 0;
	y = -1;
	while (++y < data->rows)
	{
		x = -1;
		while (++x < data->cols)
		{
			if (data->map[y][x] == 'D' && data->door_count < MAX_DOORS)
			{
				data->doors[data->door_count].x = x;
				data->doors[data->door_count].y = y;
				data->doors[data->door_count].state = 0.0;
				data->doors[data->door_count].opening = 0;
				data->door_count++;
			}
		}
	}
}

double	get_door_state(t_data *data, int x, int y)
{
	int	i;

	i = -1;
	while (++i < data->door_count)
	{
		if (data->doors[i].x == x && data->doors[i].y == y)
			return (data->doors[i].state);
	}
	return (0.0);
}
