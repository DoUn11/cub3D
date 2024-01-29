/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:17:44 by doukim            #+#    #+#             */
/*   Updated: 2024/01/29 18:41:22 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"

typedef struct s_rgb;
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_cub3d
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*filename;
	char	*tex_no;
	char	*tex_so;
	char	*tex_ea;
	char	*tex_we;
	t_rgb	floor;
	t_rgb	ceil;
}	t_cub3d;

void	c3d_err_exit(char *str);

void	c3d_get_filename(t_cub3d *info, int argc, char *argv[]);

#endif