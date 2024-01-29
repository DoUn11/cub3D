/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:31:20 by doukim            #+#    #+#             */
/*   Updated: 2024/01/29 18:32:53 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_init(t_cub3d *info)
{
	ft_memset(info, 0, sizeof(t_cub3d));
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 2000, 1200, "cud3D");
}