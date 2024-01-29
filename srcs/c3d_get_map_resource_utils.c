/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_get_map_resource.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:01:26 by doukim            #+#    #+#             */
/*   Updated: 2024/01/29 22:02:03 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	**c3d_get_resource_type(t_cub3d *info, char *line)
{
	while (*line == ' ' || (9 <= *line && *line <= 13))
		line++;
	if (!ft_strncmp(line, "NO ", 3))
		return (&info->tex_no);
	if (!ft_strncmp(line, "SO ", 3))
		return (&info->tex_so);
	if (!ft_strncmp(line, "WE ", 3))
		return (&info->tex_we);
	if (!ft_strncmp(line, "EA ", 3))
		return (&info->tex_ea);
	if (!ft_strncmp(line, "F ", 2))
		return (&info->col_floor);
	if (!ft_strncmp(line, "C ", 2))
		return (&info->col_ceil);
	return (NULL);
}
void	c3d_skip_one_word(char **line)
{
	while (*line && **line == ' ' || (9 <= **line && **line <= 13))
		*line++;
	while (*line && !(**line == ' ' || (9 <= **line && **line <= 13)))
		*line++;
	while (*line && **line == ' ' || (9 <= **line && **line <= 13))
		*line++;
}

int	c3d_get_splited_idx(t_cub3d *info, char **splited_rgb, int idx)
{
	int	ret;
	
	if (splited_rgb[idx] == NULL)
		c3d_err_exit(info, "cub3D: invalid resource format");
	ret = ft_atoi(splited_rgb[idx]);
	free(splited_rgb[idx]);
	return (ret);
}
t_rgb	*c3d_get_rgb_resource(t_cub3d *info, char *line)
{
	char	**splited_rgb;
	int		idx;
	t_rgb	*ret;

	ret = (t_rgb *)malloc(sizeof(t_rgb));
	if (ret == NULL)
		c3d_err_exit(info, "cub3D: malloc failed");
	splited_rgb = ft_split(line, ',');
	if (splited_rgb == NULL)
		c3d_err_exit(info, "cub3D: malloc failed");
	idx = 0;
	ret->r = c3d_get_splited_idx(info, splited_rgb, idx++);
	ret->g = c3d_get_splited_idx(info, splited_rgb, idx++);
	ret->b = c3d_get_splited_idx(info, splited_rgb, idx++);
	if (splited_rgb[idx] != NULL)
		c3d_err_exit(info, "cub3D: invalid resource format");
	free(splited_rgb);
	return (ret);
}
char	*c3d_get_path_resource(t_cub3d *info, char *line)
{
	char	**splited_path;
	int		idx;
	char	*ret;

	splited_path = ft_split(line, ' ');
	if (splited_path == NULL)
		c3d_err_exit(info, "cub3D: malloc failed");
	if (splited_path[0] == NULL)
		c3d_err_exit(info, "cub3D: invalid resource format");
	ret = ft_strdup(splited_path[0]);
	if (splited_path[1] != NULL)
		c3d_err_exit(info, "cub3D: invalid resource format");
	free(splited_path[0]);
	free(splited_path);
	return (ret);
}

void	c3d_get_proper_resource(t_cub3d *info, void **resource_ptr, char *line)
{
	c3d_skip_one_word(&line);
	if (resource_ptr == &info->col_ceil || resource_ptr == &info->col_floor)
		*resource_ptr = c3d_get_rgb_resource(info, line);
	else
		*resource_ptr = c3d_get_path_resource(info, line);
}