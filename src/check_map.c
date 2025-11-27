/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/10/22 16:01:02 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	pad_map(t_data *data)
{
	int		i;
	int		len;
	char	*new_line;

	data->cols = get_max_cols(data->map, data->rows);
	i = 0;
	while (i < data->rows)
	{
		len = (int)ft_strlen(data->map[i]);
		if (len > 0 && data->map[i][len - 1] == '\n')
			len--;
		if (len > data->cols)
			len = data->cols;
		new_line = malloc(data->cols + 1);
		if (!new_line)
			exit(1);
		ft_memcpy(new_line, data->map[i], len);
		ft_memset(new_line + len, ' ', data->cols - len);
		new_line[data->cols] = '\0';
		free(data->map[i]);
		data->map[i] = new_line;
		i++;
	}
}

/*Check les valeurs correctes*/
static int	has_correct_values(t_data *data)
{
	char	tile;

	data->p_count = 0;
	data->i = -1;
	while (++data->i < data->rows)
	{
		data->j = -1;
		while (++data->j < data->cols)
		{
			tile = data->map[data->i][data->j];
			if (tile == 'N' || tile == 'S'
				|| tile == 'E' || tile == 'W')
				data->p_count++;
			else if (tile != '0' && tile != '1' && tile != ' ' && tile != 'D')
			{
				ft_printf("Invalid tile '%c' (ASCII %d) at row %d, col %d\n",
					tile, tile, data->i, data->j);
				return (0);
			}
		}
	}
	return (data->p_count == 1);
}

static int	check_closed(t_data *data, int i, int j)
{
	if (i == 0 || j == 0 || i == data->rows - 1 || j == data->cols - 1)
		return (0);
	if (data->map[i + 1][j] == ' ' || data->map[i - 1][j] == ' ' ||
		data->map[i][j + 1] == ' ' || data->map[i][j - 1] == ' ')
		return (0);
	return (1);
}

static int	is_closed(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (is_open_cell(data->map[i][j]))
			{
				if (!check_closed(data, i, j))
				{
					ft_printf("Leak: cell (%d,%d) touches border/space\n",
						i, j);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid(t_data *data)
{
	pad_map(data);
	if (!has_correct_values(data))
	{
		ft_printf("Error\nIncorrect values\n");
		return (0);
	}
	if (!is_closed(data))
	{
		ft_printf("Error\nMap not closed\n");
		return (0);
	}
	if (check_textures(data))
		return (0);
	return (1);
}
