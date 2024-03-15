/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:34:05 by doukim            #+#    #+#             */
/*   Updated: 2024/03/15 10:59:32 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_get_map_resource(t_cub3d *info, int file_fd)
{
	int		cnt;
	char	*line;
	void	**resource_ptr;

	cnt = 0;
	while (cnt < 6)
	{
		line = get_next_line(file_fd);
		if (line == NULL)
			c3d_err_exit(info, "cub3D: failed to read file");
		if (*line == '\n')
		{
			free(line);
			continue ;
		}
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		resource_ptr = c3d_get_resource_type(info, line);
		if (resource_ptr == NULL || *resource_ptr != NULL)
			c3d_err_exit(info, "cub3D: invalid resource format");
		c3d_get_proper_resource(info, resource_ptr, line);
		free(line);
		cnt++;
	}
}

void	c3d_get_map_shape(t_cub3d *info, int file_fd)
{
	t_list	*maplist;

	c3d_get_listmap(info, file_fd, &maplist);
	c3d_cvt_dblptrmap(info, maplist);
	c3d_free_list(&maplist);
}

void	c3d_chk_map_valid(t_cub3d *info)
{
	c3d_chk_row_valid(info, info->map_info->map);
	printf("row is valid\n");
	c3d_chk_col_valid(info, info->map_info->map);
	printf("col is valid\n");
	c3d_chk_field_valid(info, info->map_info->map);
	printf("field is valid\n");
}

void	c3d_get_map(t_cub3d *info)
{
	int		file_fd;

	file_fd = open(info->filename, O_RDONLY);
	if (file_fd == -1)
		c3d_err_exit(info, "cub3D: failed to open file");
	c3d_get_map_resource(info, file_fd);

	printf("NO : [%s]\n", info->tex_no);
	printf("SO : [%s]\n", info->tex_so);
	printf("WE : [%s]\n", info->tex_we);
	printf("EA : [%s]\n", info->tex_ea);
	printf("C : [%d, %d, %d]\n", info->col_ceil->r, info->col_ceil->g, info->col_ceil->b);
	printf("F : [%d, %d, %d]\n", info->col_floor->r, info->col_floor->g, info->col_floor->b);

	c3d_get_map_shape(info, file_fd);

	for(int i = 0; i < info->map_info->height; i++)
		printf("%s\n", info->map_info->map[i]);
	printf("\n\n");
	c3d_chk_map_valid(info);
	printf("map is valid\n");
	close(file_fd);
}
