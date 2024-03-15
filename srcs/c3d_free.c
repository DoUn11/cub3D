/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:26:20 by doukim            #+#    #+#             */
/*   Updated: 2024/03/15 11:14:40 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_free_list(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *list;
	while (tmp)
	{
		free(tmp->data);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*list = NULL;
	return ;
}

void	c3d_free_end(t_cub3d *info)
{
	int	i;

	i = 0;
	free(info->filename);
	free(info->map_info);
	c3d_unload_texture(info);
	if (info->img->img)
		mlx_destroy_image(info->mlx, info->img->img);
	mlx_destroy_window(info->mlx, info->win);
	free(info->mlx);
	free(info->img);
	free(info->press);
	free(info->player);
	free(info->ray);
	exit(0);
}
