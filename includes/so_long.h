/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:58:38 by mriant            #+#    #+#             */
/*   Updated: 2022/02/02 17:04:47 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}				t_map;

typedef struct s_hero
{
	t_img	front_0;
	t_img	front_1;
	t_img	front_2;
	t_img	back_0;
	t_img	back_1;
	t_img	back_2;
	t_img	left_0;
	t_img	left_1;
	t_img	left_2;
	t_img	right_0;
	t_img	right_1;
	t_img	right_2;
	int		x;
	int		y;
}				t_hero;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	t_img	floor;
	t_img	wall;
	t_img	bg;
	t_hero	hero;
}				t_vars;

int		key_release(int keycode, t_vars *vars);
int		closex(t_vars *vars);
void	img_pix_put(t_img *img, int x, int y, char *color);
void	render_bg(t_vars *vars);
int		render(t_vars *vars);
int		ft_build_map(char *m_path, t_vars *vars);

#endif
