/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:18:38 by scuthber          #+#    #+#             */
/*   Updated: 2025/11/27 19:18:02 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include "libft.h"
# include "keys.h"
# include "colors.h"

# define WIDTH 1280
# define HEIGHT 720
# define PI 3.1415926535
# define FOV 60
# define BASE_MOVEMENT_SPEED 5.0
# define BASE_ROTATION_SPEED 160.0
# define MOVE_SPEED 0.08
# define ROTATION_SPEED 1.1
# define LIMIT_FPS 60
# define MOUSE_SENS 0.2f
# define COLLISION_BUFFER 0.6f
# define MAX_DOORS 128
# define TILE_SIZE 64

typedef struct s_player
{
	float	x;
	float	y;
	char	tile;
	float	angle;
	float	new_x;
	float	new_y;
	float	dir_x;
	float	dir_y;
}	t_player;

typedef struct s_door
{
	int		x;
	int		y;
	double	state;
	double	speed;
	int		opening;
}	t_door;

typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
	float	tex_pos;
}	t_tex;

typedef struct s_image
{
	void	*floor;
	char	*floor_data;
	int		floor_h;
	int		floor_w;
	int		floor_bpp;
	int		floor_ll;
	int		floor_endian;
	t_tex	north;
	t_tex	south;
	t_tex	east;
	t_tex	west;
	t_tex	door;
}	t_image;

typedef struct s_mouse
{
	int	cx;
	int	cy;
	int	warp_pending;
	int	window_focused;
	int	enabled;
}	t_mouse;

typedef struct s_draw
{
	int		x;
	int		y;
	int		line_off;
	int		line_height;
	int		tex_x;
	int		tex_y;
	int		uncapped_height;
	int		draw_start;
	int		draw_end;
	float	step;
}	t_draw;

typedef struct s_ray
{
	char		hit_tile;
	int			ray;
	int			mx;
	int			my;
	int			dof;
	double		dist_hor;
	double		dist_ver;
	float		x;
	float		y;
	float		angle;
	float		x_off;
	float		y_off;
	float		tan_val;
	float		hor_hit_x;
	float		hor_hit_y;
	float		ver_hit_x;
	float		ver_hit_y;
	float		final_hit_x;
	float		final_hit_y;
}	t_ray;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	char			**map;
	char			**new_map;
	char			**final_map;
	int				x;
	int				y;
	int				rows;
	int				cols;
	int				i;
	int				j;
	int				fd;
	int				row_count;
	char			*line;
	t_player		player;
	int				p_count;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				win_width;
	int				win_height;
	int				tile_width;
	int				tile_height;
	int				mini_tile_size;
	void			*img;
	char			*img_data;
	float			px;
	float			py;
	double			dx;
	double			dy;
	int				err;
	int				e2;
	int				color;
	t_ray			*ray;
	int				moving_f;
	int				moving_b;
	int				moving_l;
	int				moving_r;
	int				rota_l;
	int				rota_r;
	int				need_render;
	struct timeval	last_render;
	double			last_frame_time;
	int				view_distance;
	t_image			image;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*door_path;
	int				floor_rgb[3];
	int				ceiling_rgb[3];
	int				floor_color;
	int				ceiling_color;
	t_mouse			mouse;
	double			cast_angle;
	t_door			doors[MAX_DOORS];
	int				door_count;
	int				left;
	int				right;
	int				top;
	int				bottom;
	double			ratio;
	double			half;
	int				mx;
	int				my;
	char			tile;
	double			state;
	double			offset;
}					t_data;

t_data	*init_data(void);
void	init_map(t_data	*data, int rows, int cols);
void	init_player(t_data	*data);
void	init_graphics(t_data	*data);
t_ray	*init_ray(void);
char	**load_map(t_data	*data, const char	*filename);
int		is_valid(t_data	*data);
int		close_game(t_data	*data);
void	move(t_data	*data, char direction);
void	rotate_player(t_data	*data, char direction);
void	put_pixel_to_img(t_data	*data, int x, int y, int color);
void	ray_casting(t_data	*data);
void	init_ray_values(t_ray	*ray, char axis);
void	horizontal_ray(t_data	*data);
void	vertical_ray(t_data	*data);
float	normalize_angle(float angle);
float	deg_to_rad(float n);
void	draw_line(t_data	*data, int x, int y);
int		check_hit(t_data	*data);
void	find_hit_point(t_ray *ray, t_data *data);
void	render_minimap(t_data	*data);
float	should_render(t_data	*data);
int		keypress_handler(int keycode, t_data	*data);
int		keyrelease_handler(int keycode, t_data	*data);
void	clear_image(t_data	*data);
void	load_xpm(t_data	*data);
int		parse_elements(t_data *data);
void	ft_free_split(char **split);
void	ft_free_2d(void **array, int rows);
int		rgb_to_int(int r, int g, int b);
void	convert_color(t_data *data);
void	free_data(t_data	*data);
void	free_gnl(t_data *data);
int		get_max_cols(char **map, int rows);
int		is_open_cell(char c);
void	update_doors(t_data *data);
void	print_map(t_data *data);
void	mouse_look(t_data	*data);
void	init_mouse(t_data	*data);
int		focus_in(t_data	*data);
int		focus_out(t_data	*data);
void	strafe(t_data	*data, char direction);
void	walk(t_data	*data, char direction);
int		is_valid_position(t_data *data);
int		check_textures(t_data *data);
void	toggle_mouse(t_data	*data);
void	select_door(t_data *data, t_tex **tex, t_draw *d);
void	select_vertical(t_data *data, t_tex **tex, t_draw *d);
void	select_horizontal(t_data *data, t_tex **tex, t_draw *d);
int		game_loop(t_data	*data);
double	get_door_state(t_data *data, int x, int y);
void	init_doors(t_data *data);
void	draw_texture_line(t_data *data, t_tex *tex, t_draw *d);
void	handle_hit(t_data	*data, char dir);
int		is_number(char **split);
char	*ft_strtrim_space(char *s);
int		parse_color_trim(char **split);

#endif
