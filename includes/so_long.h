/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:58:38 by mriant            #+#    #+#             */
/*   Updated: 2022/02/11 15:56:51 by mriant           ###   ########.fr       */
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
	size_t	width;
	size_t	height;
}				t_map;

typedef struct s_hero
{
	t_img	front[3];
	t_img	back[3];
	t_img	left[3];
	t_img	right[3];
	t_img	*current;
	int		x;
	int		y;
	int		state;
	int		move[2];
}				t_hero;

typedef struct s_other
{
	int		count;
	int		count_max;
	int		*x;
	int		*y;
	int		state;
	t_img	img[2];
}				t_other;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			steps;
	int			delay;
	t_map		map;
	t_img		img;
	t_img		floor;
	t_img		wall;
	t_img		bg;
	t_img		digit;
	t_img		text;
	t_hero		hero;
	t_other		collect;
	t_other		exit;
}				t_vars;

int		ft_addr_bg(t_vars *vars);
int		ft_addr_hero1(t_hero *hero);
int		ft_addr_hero2(t_hero *hero);
int		ft_addr_tiles(t_vars *vars);
int		ft_alloc_pos(t_vars *vars);
void	ft_anim(t_vars *vars);
int		ft_build_map(char *m_path, t_vars *vars);
void	ft_check_collect(t_vars *vars);
void	ft_check_exit(t_vars *vars);
int		ft_check_map(t_vars *vars, char **grid);
void	ft_clean_all(t_vars *vars);
int		ft_count_assets(unsigned int i, unsigned int j, int *p, t_vars *vars);
void	ft_img_pix_put(t_img *img, int x, int y, char *color);
int		ft_init_bg(t_vars *vars);
int		ft_init_hero1(t_vars *vars, t_hero *hero);
int		ft_init_hero2(t_vars *vars, t_hero *hero);
int		ft_init_pos(t_vars *vars);
void	ft_init_struct(t_vars *vars);
int		ft_init_tiles(t_vars *vars);
void	ft_itoimg(int n, t_vars *vars);
int		ft_key_press(int keycode, t_vars *vars);
int		ft_key_release(int keycode, t_vars *vars);
void	ft_null_hero(t_hero *hero);
void	ft_null_img(t_img *img);
void	ft_null_map(t_map *map);
void	ft_null_other(t_other *other);
int		ft_parse_grid(t_list **first, t_vars *vars);
int		ft_preloop(t_vars *vars, char **av);
t_list	*ft_read_grid(int fd);
int		ft_render(t_vars *vars);
void	ft_render_bg(t_vars *vars);
void	ft_render_digits(t_vars *vars, int i, int digit);
void	ft_render_img(t_vars *vars, t_img tile, int i, int j);
void	ft_render_other(t_vars *vars, t_other other);
void	ft_render_tile(t_vars *vars, t_img tile, int i, int j);
int		ft_set_img(t_vars *vars);
int		ft_set_map(int fd, t_vars *vars);
void	ft_set_pos(t_other *other, int i, int j, int *n);

#endif
