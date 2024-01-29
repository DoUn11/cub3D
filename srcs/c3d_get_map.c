/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:34:05 by doukim            #+#    #+#             */
/*   Updated: 2024/01/29 18:36:04 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_get_map(t_cub3d *info)
{
	int		file_fd;
	
	file_fd = open(info->filename, O_RDONLY);
	if (file_fd == -1)
		c3d_err_exit("cub3D: failed to open file");
	
}