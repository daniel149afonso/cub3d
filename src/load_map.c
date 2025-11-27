/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/10/23 18:20:48 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	process_line(t_data	*data, int *cols)
{
	int	len;

	data->new_map = ft_realloc(data->map, data->row_count * sizeof(char *),
			(data->row_count + 1) * sizeof(char *));
	if (!data->new_map)
	{
		ft_printf("Error\nMemory alloc fail\n");
		return (0);
	}
	data->map = data->new_map;
	data->map[data->row_count] = data->line;
	if (data->row_count == 0 && cols)
	{
		len = (int)ft_strlen(data->line);
		if (len > 0 && data->line[len - 1] == '\n')
			len--;
		*cols = len;
	}
	data->row_count++;
	return (1);
}

/*Traite la 1 ere ligne puis les suivantes*/
static int	read_map_lines(t_data *data, int *cols)
{
	if (data->line)
	{
		if (!process_line(data, cols))
			return (0);
		data->line = NULL;
	}
	data->line = get_next_line(data->fd);
	while (data->line)
	{
		if (!process_line(data, cols))
			return (0);
		data->line = NULL;
		data->line = get_next_line(data->fd);
	}
	return (1);
}

static void	end_of_map(t_data	*data)
{
	data->final_map = ft_realloc(data->map, data->row_count * sizeof(char *),
			(data->row_count + 1) * sizeof(char *));
	if (data->final_map)
	{
		data->map = data->final_map;
		data->map[data->row_count] = NULL;
	}
}

char	**load_map(t_data *data, const char *filename)
{
	data->fd = open(filename, O_RDONLY);
	if (data->fd < 0)
	{
		ft_printf("Error\nCan't open file. Does your file exist?\n");
		return (NULL);
	}
	if (!parse_elements(data))
	{
		ft_printf("Error\nParse elements failed\n");
		return (NULL);
	}
	if (!read_map_lines(data, &data->cols))
	{
		ft_printf("Error\nRead map failed\n");
		return (NULL);
	}
	end_of_map(data);
	data->rows = data->row_count;
	close(data->fd);
	return (data->map);
}
