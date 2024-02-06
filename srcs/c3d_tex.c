/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:10:53 by chanspar          #+#    #+#             */
/*   Updated: 2024/02/06 17:51:20 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_init_load_img(t_cub3d *cub3d, int **texture, int i)
{
	int	j;

	j = 0;
	while (j < cub3d->img->img_width * cub3d->img->img_height)
	{
		texture[i][j] = 0;
		j++;
	}
}

void	c3d_load_img(t_cub3d *cub3d, int **texture, char *path, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	cub3d->img->img = mlx_xpm_file_to_image(cub3d->mlx, path, \
	&cub3d->img->img_width, &cub3d->img->img_height);
	texture[i] = malloc(sizeof(int) * \
	(cub3d->img->img_width * cub3d->img->img_height));
	if (!texture[i])
		c3d_err_exit(cub3d, "cub3D: mlx_init failed\n");
	c3d_init_load_img(cub3d, texture, i);
	cub3d->img->addr = mlx_get_data_addr(cub3d->img->img, \
	&cub3d->img->bpp, &cub3d->img->size_l, &cub3d->img->endian);
	while (y < cub3d->img->img_height)
	{
		while (x < cub3d->img->img_width)
		{
			texture[i][cub3d->img->img_width * y + x] = \
			cub3d->img->addr[cub3d->img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(cub3d->mlx, cub3d->img->img);
}

void	c3d_load_texture(t_cub3d *cub3d)
{
	c3d_load_img(cub3d, cub3d->texture, cub3d->tex_ea, 0);
	c3d_load_img(cub3d, cub3d->texture, cub3d->tex_we, 1);
	c3d_load_img(cub3d, cub3d->texture, cub3d->tex_so, 2);
	c3d_load_img(cub3d, cub3d->texture, cub3d->tex_no, 3);
}
