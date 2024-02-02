/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:17:44 by doukim            #+#    #+#             */
/*   Updated: 2024/02/03 00:02:00 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define L_ARROW 123
# define R_ARROW 124
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define MAPWIDTH 24
# define MAPHEIGHT 24
# define WIDTH 640
# define HEIGHT 480

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		img_width;
	int		img_height;
	int		bpp;
	int		size_l;
	int		endian;
}	t_img;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rotate_speed;
}	t_player;

typedef struct s_press
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
	int	key_r;
	int	key_l;
}	t_press;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	t_img		*img;
	char		*filename;
	char		*tex_no;
	char		*tex_so;
	char		*tex_ea;
	char		*tex_we;
	t_map		*map_info;
	t_rgb		*col_floor;
	t_rgb		*col_ceil;
	t_player	*player;
	t_press		*press;
}	t_cub3d;

void	c3d_init(t_cub3d *info);
void	c3d_get_map(t_cub3d *info);
void	c3d_err_exit(t_cub3d *info, char *str);
void	c3d_get_filename(t_cub3d *info, int argc, char *argv[]);

void	**c3d_get_resource_type(t_cub3d *info, char *line);
void	c3d_skip_one_word(char **line);
int		c3d_get_splited_idx(t_cub3d *info, char **splited_rgb, int idx);
t_rgb	*c3d_get_rgb_resource(t_cub3d *info, char *line);
char	*c3d_get_path_resource(t_cub3d *info, char *line);
void	c3d_get_proper_resource(t_cub3d *info, void **resource_ptr, char *line);

char	*c3d_get_map_first_line(t_cub3d *info, int file_fd);
void	c3d_get_listmap(t_cub3d *info, int file_fd, t_list **maplist);
void	c3d_get_map_info(t_cub3d *info, t_list *maplist);
void	c3d_cvt_dblptrmap(t_cub3d *info, t_list *maplist);

void	c3d_free_list(t_list **list);


#endif