/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:30:45 by chanspar          #+#    #+#             */
/*   Updated: 2024/02/06 20:33:08 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_mlx_init(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	if (!cub3d->mlx)
		c3d_err_exit(cub3d, "cub3D: mlx_init failed\n");
	cub3d->win = mlx_new_window(cub3d->mlx, WIDTH, HEIGHT, "cub3d");
	if (!cub3d->win)
		c3d_err_exit(cub3d, "cub3D: mlx_win failed\n");
	cub3d->img = malloc(sizeof(t_img));
	if (!cub3d->img)
		c3d_err_exit(cub3d, "cub3D: malloc failed\n");
	cub3d->press = malloc(sizeof(t_press));
	if (!cub3d->press)
		c3d_err_exit(cub3d, "cub3D: malloc failed\n");
	cub3d->player = malloc(sizeof(t_player));
	if (!cub3d->player)
		c3d_err_exit(cub3d, "cub3D: malloc failed\n");
	cub3d->ray = malloc(sizeof(t_ray));
	if (!cub3d->ray)
		c3d_err_exit(cub3d, "cub3D: malloc failed\n");
	c3d_memeset_struct(cub3d);
	c3d_init_buf(cub3d);
	cub3d->img->img = NULL;
}

int	c3d_close_win(t_cub3d *cub3d)
{
	mlx_destroy_image(cub3d->mlx, cub3d->img->img);
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	exit(0);
}

void	c3d_player_set(t_cub3d *cub3d)
{
	// cub3d->player->pos_x = 
	// cub3d->player->pos_y = 
	cub3d->player->pos_x = 5.0;
	cub3d->player->pos_y = 5.5;

	cub3d->player->dir_x = 0.0;
	cub3d->player->dir_y = -1.0;
	cub3d->player->plane_x = 0.66;
	cub3d->player->plane_y = 0.0;
	// if (N w a s)
		// c3d_rotate_right() or c3d_rotate_left
	cub3d->player->move_speed = 0.05;
	cub3d->player->rotate_speed = 0.05;
}

int	main_loop(t_cub3d *cub3d)
{
	int	x;

	x = 0;
	c3d_clear_img(cub3d);
	c3d_draw_cf(cub3d);
	if (cub3d->re_buf == 1)
		c3d_init_buf(cub3d);
	while (x < WIDTH)
	{
		c3d_ray_init(cub3d, x);
		c3d_dda(cub3d);
		c3d_cal_wall(cub3d);
		// c3d_draw_wall(cub3d, x);
		x++;
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img->img, 0, 0);
	c3d_key_hook(cub3d);
	return (0);
}

void	c3d_event_exe(t_cub3d *cub3d)
{
	c3d_load_texture(cub3d);
	c3d_cf_color(cub3d);
	// c3d_player_set(cub3d);
	mlx_hook(cub3d->win, 17, 0L, &c3d_close_win, cub3d);
	mlx_hook(cub3d->win, 2, 0L, &c3d_key_press, cub3d);
	mlx_hook(cub3d->win, 3, 0L, &c3d_key_release, cub3d);
	mlx_loop_hook(cub3d->mlx, &main_loop, cub3d);
	mlx_loop(cub3d->mlx);
}


