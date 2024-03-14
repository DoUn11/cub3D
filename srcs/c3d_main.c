/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:20:22 by doukim            #+#    #+#             */
/*   Updated: 2024/03/15 01:16:12 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_cub3d	info;

	c3d_init(&info);
	c3d_get_filename(&info, argc, argv);
	c3d_get_map(&info);
	c3d_mlx_init(&info);
	c3d_event_exe(&info);
}

//NWSA 동서남북인지와 	플레이어 좌표 저장좀   
//예시 
	// cub3d->player->pos_x = cub3d->map->player_x + 0.5;
	// cub3d->player->pos_y = cub3d->map->player_y + 0.5;
/*map에 동서남북 정보 만들어 줘 
	if (cub3d->map->compass == 'E')
		cub3d->player->rotate_speed = 1.570795;
	else if (cub3d->map->compass == 'S')
		cub3d->player->rotate_speed = 1.570795 * 2;
	else if (cub3d->map->compass == 'W')
		cub3d->player->rotate_speed = 1.570795 * 3;
	else if (cub3d->map->compass == 'N')
		cub3d->player->rotate_speed = 1.570795 * 4;
	c3d_rotate_right(cub3d);
	*/
//맵에서 NWSA 같이 지나갈수있는거 0으로 바꿔줄수있나여?? 

//플레이어 2명이여도 잘돌아가는듯 그거 처리점