/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:20:11 by doukim            #+#    #+#             */
/*   Updated: 2024/01/30 17:01:33 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_err_exit(t_cub3d *info, char *str)
{
	write(2, str, ft_strlen(str));
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	exit(-1);
}