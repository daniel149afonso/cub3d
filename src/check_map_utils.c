/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/10/17 19:02:13 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_open_cell(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == 'D');
}

int	get_max_cols(char **map, int rows)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (i < rows)
	{
		len = (int)ft_strlen(map[i]);
		if (map[i][len - 1] == '\n')
			len--;
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

static int	check_file_exists(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	check_syntax(const char *path)
{
	int	len;

	len = ft_strlen(path);
	if (ft_strnstr(path, ".xpm", len))
	{
		if (!ft_strncmp(&path[len - 4], ".xpm", 4))
			return (0);
		return (1);
	}
	return (1);
}

int	check_textures(t_data *data)
{
	if (!data->no_path || !data->so_path || !data->ea_path
		|| !data->we_path || !data->door_path)
	{
		ft_printf("Error\nMissing texture(s)\n");
		return (1);
	}
	if (!check_file_exists(data->no_path)
		|| !check_file_exists(data->so_path)
		|| !check_file_exists(data->ea_path)
		|| !check_file_exists(data->we_path)
		|| !check_file_exists(data->door_path))
	{
		ft_printf("Error\nInvalid texture path\n");
		return (1);
	}
	if (check_syntax(data->no_path)
		|| check_syntax(data->so_path)
		|| check_syntax(data->ea_path)
		|| check_syntax(data->we_path)
		|| check_syntax(data->door_path))
	{
		ft_printf("Error\nInvalid syntax. It should be .xpm\n");
		return (1);
	}
	return (0);
}
