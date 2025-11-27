/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/10/01 14:25:05 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_wall_texture(t_data *data, t_tex *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(data->mlx,
			path, &tex->width, &tex->height);
	if (!tex->img)
	{
		free_data(data);
		perror("Texture path");
		exit(1);
	}
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bpp, &tex->line_len,
			&tex->endian);
}

void	load_xpm(t_data	*data)
{
	load_wall_texture(data, &data->image.north, data->no_path);
	load_wall_texture(data, &data->image.east, data->ea_path);
	load_wall_texture(data, &data->image.west, data->we_path);
	load_wall_texture(data, &data->image.south, data->so_path);
	load_wall_texture(data, &data->image.door, data->door_path);
}
