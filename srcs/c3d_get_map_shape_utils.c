/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_get_map_shape_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:55:08 by doukim            #+#    #+#             */
/*   Updated: 2024/01/29 22:55:59 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*c3d_get_map_first_line(t_cub3d *info, int file_fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(file_fd);
		if (line == NULL)
			c3d_err_exit(info, "cub3D: invalid map format");
		if (*line == '\n')
		{
			free(line);
			continue ;
		}
		return (line);
	}
}
void	c3d_get_listmap(t_cub3d *info, int file_fd, t_list *maplist)
{
	char	*line;
	t_list	*new_node;
	
	maplist = NULL;
	while (1)
	{
		if (maplist == NULL)
			line = c3d_get_map_first_line(info, file_fd);
		else
			line = get_next_line(file_fd);
		if (line == NULL)
			return ;
		new_node = ft_lstnew(line);
		if (new_node == NULL)
			c3d_err_exit(info, "cub3D: malloc failed");
		ft_lstadd_back(&maplist, ft_lstnew(line));
	}
}
void	c3d_get_map_info(t_cub3d *info, t_list *maplist)
{
	t_list	*tmp;
	int		idx;
	int		line_width;

	tmp = maplist;
	while (tmp)
	{
		line_width = ft_strlen((char *)(tmp->content));
		if (line_width > info->map_info->width)
			info->map_info->width = line_width;
		info->map_info->height++;
		tmp = tmp->next;
	}
	info->map_info->map = (char **)malloc(8 * info->map_info->height);
	if (info->map_info->map == NULL)
		c3d_err_exit(info, "cub3D: malloc failed");
	idx = 0;
	while (idx < info->map_info->height)
	{
		info->map_info->map[idx] = (char *)malloc(info->map_info->width + 1);
		if (info->map_info->map[idx] == NULL)
			c3d_err_exit(info, "cub3D: malloc failed");
		idx++;
	}
}

void	c3d_cvt_dblptrmap(t_cub3d *info, t_list *maplist)
{
	t_list	*tmp;
	int		idx;
	int		idx2;

	c3d_get_map_info(info, maplist);
	tmp = maplist;
	idx2 = 0;
	while (tmp)
	{
		idx = 0;
		while (((char *)(tmp->content))[idx])
		{
			info->map_info->map[idx2][idx] = ((char *)(tmp->content))[idx];
			idx++;
		}
		while (idx < info->map_info->width)
		{
			info->map_info->map[idx2][idx] = ' ';
			idx++;
		}
		((char *)(tmp->content))[idx] = '\0';
		tmp = tmp->next;
		idx2++;
	}
}