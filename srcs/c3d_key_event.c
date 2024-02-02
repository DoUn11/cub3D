/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_key_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:30:14 by chanspar          #+#    #+#             */
/*   Updated: 2024/02/02 19:43:56 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main_loop(t_cub3d *cub3d)
{
	c3d_floor_ceiling();
	c3d_raycaseting();
	c3d_draw_img();
	c3d_key_hook(cub3d);
	return (0);
}

int	c3d_close_win(t_cub3d *cub3d)
{
	mlx_destroy_image(cub3d->mlx, cub3d->img);
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	exit(0);
}

int	c3d_key_hook(t_cub3d *cub3d)
{
	if (cub3d->press->key_w || cub3d->press->key_s \
	|| cub3d->press->key_a || cub3d->press->key_d)
		c3d_move_player(cub3d);
	else if (cub3d->press->key_l || cub3d->press->key_r)
		c3d_rotate_player(cub3d);
	return (0);
}

int	c3d_key_press(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_W)
		cub3d->press->key_w = 1;
	if (keycode == KEY_A)
		cub3d->press->key_a = 1;
	if (keycode == KEY_S)
		cub3d->press->key_s = 1;
	if (keycode == KEY_D)
		cub3d->press->key_d = 1;
	if (keycode == L_ARROW)
		cub3d->press->key_l = 1;
	if (keycode == R_ARROW)
		cub3d->press->key_r = 1;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(cub3d->mlx, cub3d->img);
		mlx_destroy_window(cub3d->mlx, cub3d->win);
		exit(0);
	}
	return (0);
}

int	c3d_key_release(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_W)
		cub3d->press->key_w = 0;
	if (keycode == KEY_A)
		cub3d->press->key_a = 0;
	if (keycode == KEY_S)
		cub3d->press->key_s = 0;
	if (keycode == KEY_D)
		cub3d->press->key_d = 0;
	if (keycode == L_ARROW)
		cub3d->press->key_l = 0;
	if (keycode == R_ARROW)
		cub3d->press->key_r = 0;
	return (0);
}

void	c3d_event_exe(t_cub3d *cub3d)
{
	mlx_hook(cub3d->win, 17, 0L, &c3d_close_win, cub3d);
	mlx_hook(cub3d->win, 2, 0L, &c3d_key_press, cub3d);
	mlx_hook(cub3d->win, 3, 0L, &c3d_key_release, cub3d);
	mlx_loop_hook(cub3d->mlx, &main_loop, cub3d);
	mlx_loop(cub3d->mlx);
}
