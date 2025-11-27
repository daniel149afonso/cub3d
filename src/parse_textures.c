/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:29:20 by daniel149af       #+#    #+#             */
/*   Updated: 2025/10/23 16:00:37 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	remove_newline(char *s)
{
	int	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
	{
		s[len - 1] = '\0';
		len--;
	}
}

static int	parse_texture(t_data *data, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split || !split[0] || !split[1])
		return (0);
	remove_newline(split[1]);
	if (!ft_strncmp(split[0], "NO", 2))
		data->no_path = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "SO", 2))
		data->so_path = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "WE", 2))
		data->we_path = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "EA", 2))
		data->ea_path = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "DO", 2))
		data->door_path = ft_strdup(split[1]);
	else
	{
		ft_free_split(split);
		return (0);
	}
	ft_free_split(split);
	return (1);
}

static int	parse_color(int *rgb, char *line)
{
	char	**split;
	int		i;

	split = ft_split(line + 1, ',');
	if (!split)
		return (0);
	if (!parse_color_trim(split))
		return (ft_free_split(split), 0);
	i = 0;
	while (i < 3)
	{
		rgb[i] = ft_atoi(split[i]);
		if (rgb[i] < 0)
			return (ft_free_split(split), 0);
		if (rgb[i] > 255)
			return (ft_free_split(split), 0);
		i++;
	}
	ft_free_split(split);
	return (1);
}

static int	parse_elements_line(t_data	*data)
{
	if (!ft_strncmp(data->line, "NO", 2) || !ft_strncmp(data->line, "SO", 2)
		|| !ft_strncmp(data->line, "WE", 2) || !ft_strncmp(data->line, "EA", 2)
		|| !ft_strncmp(data->line, "DO", 2))
	{
		if (!parse_texture(data, data->line))
			return (free_gnl(data), 0);
		free(data->line);
		return (1);
	}
	if (data->line[0] == 'F')
	{
		if (!parse_color(data->floor_rgb, data->line))
			return (free_gnl(data), 0);
		free(data->line);
		return (1);
	}
	if (data->line[0] == 'C')
	{
		if (!parse_color(data->ceiling_rgb, data->line))
			return (free_gnl(data), 0);
		free(data->line);
		return (1);
	}
	return (-1);
}

int	parse_elements(t_data *data)
{
	int	result;

	while (1)
	{
		data->line = get_next_line(data->fd);
		if (!data->line)
			break ;
		if (ft_strncmp(data->line, "\n", 1) == 0)
		{
			free(data->line);
			continue ;
		}
		result = parse_elements_line(data);
		if (result == -1)
			return (1);
		if (result == 0)
			return (0);
	}
	return (0);
}
