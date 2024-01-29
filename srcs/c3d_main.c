/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:20:22 by doukim            #+#    #+#             */
/*   Updated: 2024/01/29 20:59:53 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char *argv[])
{
	t_cub3d	info;

	c3d_init(&info);
	c3d_get_filename(&info, argc, argv);
	c3d_get_map(&info);
	//c3d_mlx_loop();
}