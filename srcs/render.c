/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:56:12 by mriant            #+#    #+#             */
/*   Updated: 2022/02/11 17:55:47 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_tile(t_vars *vars, t_img tile, int i, int j)
{
	int		x;
	int		y;
	char	*pixel;

	x = 0;
	while (x < tile.width)
	{
		y = 0;
		while (y < tile.height)
		{
			pixel = tile.addr + (y * tile.line_len + x * (tile.bpp / 8));
			ft_img_pix_put(&vars->bg, x + i * tile.width,
				y + j * tile.height, pixel);
			y ++;
		}
		x ++;
	}
}

void	ft_render_img(t_vars *vars, t_img tile, int i, int j)
{
	int		x;
	int		y;
	char	*pixel;

	if (i < 0 || j < 0)
		return ;
	x = 0;
	while (x < tile.width)
	{
		y = 0;
		while (y < tile.height)
		{
			pixel = tile.addr + (y * tile.line_len + x * (tile.bpp / 8));
			ft_img_pix_put(&vars->img, x + i, y + j, pixel);
			y ++;
		}
		x ++;
	}
}

void	ft_render_bg(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < vars->map.width)
	{
		j = 0;
		while (j < vars->map.height)
		{
			if (vars->map.grid[j][i] == '1')
				ft_render_tile(vars, vars->wall, i, j);
			else
				ft_render_tile(vars, vars->floor, i, j);
			j += 1;
		}
		ft_render_tile(vars, vars->floor, i, j);
		i += 1;
	}
	ft_render_tile(vars, vars->text, 0, vars->map.height);
}

void	ft_render_other(t_vars *vars, t_other other)
{
	int	i;

	i = 0;
	while (i < other.count_max)
	{
		ft_render_img(vars, other.img[other.state],
			other.x[i] * vars->floor.width,
			other.y[i] * vars->floor.height);
		i ++;
	}
}

int	ft_render(t_vars *vars)
{
	if (vars->win)
	{
		ft_anim(vars);
		ft_render_img(vars, vars->bg, 0, 0);
		ft_render_other(vars, vars->collect);
		ft_render_other(vars, vars->exit);
		ft_render_other(vars, vars->foe);
		ft_render_img(vars, vars->hero.current[vars->hero.state],
			vars->hero.x, vars->hero.y);
		ft_itoimg(vars->steps, vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.mlx_img, 0, 0);
	}
	return (0);
}
