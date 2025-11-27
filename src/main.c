/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:10:15 by scuthber          #+#    #+#             */
/*   Updated: 2025/10/23 18:44:04 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_format_valid(char	*filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension)
		return (0);
	if (ft_strncmp(".cub", extension, 4) == 0)
		return (1);
	else
		return (0);
}

static int	validate_data(t_data	*data, char	**argv)
{
	if (!is_format_valid(argv[1]))
	{
		ft_printf("Error\nFormat file not .cub\n");
		free_data(data);
		return (0);
	}
	data->map = load_map(data, argv[1]);
	if (!data->map)
	{
		free_data(data);
		return (0);
	}
	if (!is_valid(data))
	{
		free_data(data);
		return (0);
	}
	data->win_width = data->cols * data->tile_width;
	data->win_height = data->rows * data->tile_height;
	return (1);
}

static int	init(t_data	*data, char	**av)
{
	init_map(data, 0, 0);
	if (!validate_data(data, av))
		return (0);
	init_player(data);
	init_doors(data);
	convert_color(data);
	init_graphics(data);
	init_mouse(data);
	data->ray = init_ray();
	load_xpm(data);
	ray_casting(data);
	return (1);
}

int	main(int ac, char	**av)
{
	t_data	*data;

	data = NULL;
	if (ac == 2)
	{
		data = init_data();
		if (!init(data, av))
			return (1);
		mlx_hook(data->mlx_win, 2, 1L << 0, keypress_handler, data);
		mlx_hook(data->mlx_win, 3, 1L << 1, keyrelease_handler, data);
		mlx_hook(data->mlx_win, 9, 1L << 21, focus_in, data);
		mlx_hook(data->mlx_win, 10, 1L << 21, focus_out, data);
		mlx_loop_hook(data->mlx, game_loop, data);
		mlx_do_key_autorepeaton(data->mlx);
		mlx_hook(data->mlx_win, 17, 0, close_game, data);
		mlx_loop(data->mlx);
		return (0);
	}
	printf("./cub3D <maps/map.cub>");
	return (1);
}
