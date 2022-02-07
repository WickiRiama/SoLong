/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:31:55 by mriant            #+#    #+#             */
/*   Updated: 2022/02/07 14:17:30 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_loop_end(vars->mlx);
	return (0);
}

int	closex(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, char *color)
{
	char	*pixel;
	int		i;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	i = 0;
	while (i < img->bpp)
	{
		*pixel = *color;
		pixel ++;
		color ++;
		i += 8;
	}
}

void	render_tile(t_vars *vars, t_img tile, int i, int j)
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
			img_pix_put(&vars->bg, x + i * tile.width,
				y + j * tile.height, pixel);
			y ++;
		}
		x ++;
	}
}

void	render_img(t_vars *vars, t_img tile, int i, int j)
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
			img_pix_put(&vars->img, x + i * tile.width,
				y + j * tile.height, pixel);
			y ++;
		}
		x ++;
	}
}

void	render_bg(t_vars *vars)
{
	int		i;
	int		j;

		i = 0;
	while (i < vars->map.width)
	{
		j = 0;
		while (j < vars->map.height)
		{
			if (vars->map.grid[j][i] == '1')
				render_tile(vars, vars->wall, i, j);
			else if (vars->map.grid[j][i] != '\n')
				render_tile(vars, vars->floor, i, j);
			j += 1;
		}
		i += 1;
	}
}

int	render(t_vars *vars)
{
	if (vars->win)
	{
		render_img(vars, vars->bg, 0, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.mlx_img, 0, 0);
	}
	return (0);
}

int	main(int ac, char ** av)
{
	t_vars	vars;
	int		ret;

	if (ac != 2)
	{
		printf("Error\nPass the path to the map as argument.\n");
		return (-1);
	}
	ret = ft_build_map(av[1], &vars);
	if (ret == -1)
		return (-1);
	vars.mlx = mlx_init();
	if (!(vars.mlx))
	{
		perror("Error\nCould'nt initialize MLX\n");
		return (-1);
	}
	vars.win = mlx_new_window(vars.mlx, vars.map.width * 48, vars.map.height * 48, "So long");
	if (!(vars.win))
	{
		printf("Error\nCould'nt initialize window\n");
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (-1);
	}
	ret = ft_set_img(&vars);
	if (ret == -1)
	{
		printf("Eroor\nCouldn't process images\n");
		return (-1);
	}
	render_bg(&vars);
	mlx_key_hook(vars.win, key_release, &vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_hook(vars.win, 17, 0, closex, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_image(vars.mlx, vars.img.mlx_img);
	mlx_destroy_image(vars.mlx, vars.floor.mlx_img);
	mlx_destroy_image(vars.mlx, vars.bg.mlx_img);
	mlx_destroy_image(vars.mlx, vars.wall.mlx_img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	ret = 0;
	while (vars.map.grid[ret])
	{
		free(vars.map.grid[ret]);
		ret ++;
	}
	free(vars.map.grid);
	return (0);
}
