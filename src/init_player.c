/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/10/07 15:59:40 by scuthber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_angle(char c)
{
	if (c == 'N')
		return (270);
	else if (c == 'S')
		return (90);
	else if (c == 'E')
		return (0);
	else if (c == 'W')
		return (180);
	return (0);
}

static int	find_player(t_data	*data, int row)
{
	int		col;
	char	c;

	col = -1;
	while (++col < data->cols)
	{
		c = data->map[row][col];
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			data->player.x = col + 0.5;
			data->player.y = row + 0.5;
			data->player.angle = get_angle(c);
			data->map[row][col] = '0';
			return (1);
		}
	}
	return (0);
}

void	init_player(t_data *data)
{
	char	row;

	row = -1;
	while (++row < data->rows)
	{
		if (find_player(data, row))
			return ;
	}
}
