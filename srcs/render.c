/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:56:12 by mriant            #+#    #+#             */
/*   Updated: 2022/02/08 19:47:02 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_img_pix_put(t_img *img, int x, int y, char *color)
{
	char	*pixel;
	int		i;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	i = 0;
	while (i < img->bpp)
	{
		if (*color)
			*pixel = *color;
		pixel ++;
		color ++;
		i += 8;
	}
}

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

	x = 0;
	while (x < tile.width)
	{
		y = 0;
		while (y < tile.height)
		{
			pixel = tile.addr + (y * tile.line_len + x * (tile.bpp / 8));
			ft_img_pix_put(&vars->img, x + i * tile.width,
				y + j * tile.height, pixel);
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
			else if (vars->map.grid[j][i] != '\n')
				ft_render_tile(vars, vars->floor, i, j);
			j += 1;
		}
		i += 1;
	}
}

int	ft_render(t_vars *vars)
{
	int	i;

	if (vars->win)
	{
		ft_render_img(vars, vars->bg, 0, 0);
		i = 0;
		while (i < vars->collect.count)
		{
			ft_render_img(vars, vars->collect.img, vars->collect.x[i],
				vars->collect.y[i]);
			i ++;
		}
		i = 0;
		while (i < vars->exit.count)
		{
			ft_render_img(vars, vars->exit.img, vars->exit.x[i],
				vars->exit.y[i]);
			i ++;
		}
		ft_render_img(vars, vars->hero.front[0], vars->hero.x, vars->hero.y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.mlx_img, 0, 0);
	}
	return (0);
}
