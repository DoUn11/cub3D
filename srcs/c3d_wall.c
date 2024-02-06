/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:29:47 by chanspar          #+#    #+#             */
/*   Updated: 2024/02/06 20:32:32 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_cal_wall(t_cub3d *cub3d)
{
	t_wall	wall;

	wall.wall_height = (int)(HEIGHT / cub3d->ray->perpwalldist);
	wall.wall_start = -wall.wall_height / 2 + HEIGHT / 2;
	if (wall.wall_start < 0)
		wall.wall_start = 0;
	wall.wall_end = wall.wall_height / 2 + HEIGHT / 2;
	if (wall.wall_end >= HEIGHT)
		wall.wall_end = HEIGHT - 1;
	// wall.tex_num = 동서남북중 어떤건지 파악해야됨..
	if (cub3d->ray->side == 0)
		wall.wall_x = cub3d->player->pos_y + \
		cub3d->ray->perpwalldist * cub3d->ray->raydir_y;
	else
		wall.wall_x = cub3d->player->pos_x + \
		cub3d->ray->perpwalldist * cub3d->ray->raydir_x;
	wall.wall_x -= floor(wall.wall_x);
	wall.x_coor = (int)(wall.wall_x * (double)(cub3d->img->img_width));
	if ((cub3d->ray->side == 0 && cub3d->ray->raydir_x > 0) \
	|| (cub3d->ray->side == 1 && cub3d->ray->raydir_y < 0))
		wall.x_coor = cub3d->img->img_width - wall.x_coor - 1;
}

// void	c3d_draw_wall(t_cub3d *cub3d, int x)
// {
// 	int	y;

// 	y = cub3d->texture->wall_start;
// 	cub3d->texture->step = 1.0 * cub3d->texture->height / cub3d->texture->wall_height;
// 	cub3d->texture->pos = (cub3d->texture->wall_start - HEIGHT / 2 + cub3d->texture->wall_height / 2) * cub3d->texture->step;
// 	while (y < cub3d->texture->wall_end)
// 	{
// 		cub3d->texture->y_coor = (int)cub3d->texture->pos & (cub3d->texture->height - 1);
// 		cub3d->texture->pos += cub3d->texture->step;
// 		c3d_pixel_put(cub3d, x, y, 0);
// 		y++;
// 	}
// }
