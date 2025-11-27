/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/10/03 15:03:21 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_mlx(t_data *data)
{
	if (!data->mlx)
		return ;
	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		data->img = NULL;
		data->img_data = NULL;
	}
	if (data->mlx_win)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		data->mlx_win = NULL;
	}
	free(data->mlx);
	data->mlx = NULL;
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_free_2d(void **array, int rows)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	ft_free_textures(t_data *data)
{
	if (data->no_path)
		free(data->no_path);
	if (data->so_path)
		free(data->so_path);
	if (data->ea_path)
		free(data->ea_path);
	if (data->we_path)
		free(data->we_path);
	if (data->door_path)
		free(data->door_path);
	if (data->image.north.img)
		mlx_destroy_image(data->mlx, data->image.north.img);
	if (data->image.south.img)
		mlx_destroy_image(data->mlx, data->image.south.img);
	if (data->image.east.img)
		mlx_destroy_image(data->mlx, data->image.east.img);
	if (data->image.west.img)
		mlx_destroy_image(data->mlx, data->image.west.img);
	if (data->image.door.img)
		mlx_destroy_image(data->mlx, data->image.door.img);
}

void	free_data(t_data	*data)
{
	if (!data)
		return ;
	if (data->fd > 0)
		close(data->fd);
	if (data->ray)
		free(data->ray);
	if (data->map)
		ft_free_split(data->map);
	if (data->line)
		free(data->line);
	ft_free_textures(data);
	ft_free_mlx(data);
	free(data);
	data = NULL;
}
