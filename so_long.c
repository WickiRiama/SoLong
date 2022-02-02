/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:31:55 by mriant            #+#    #+#             */
/*   Updated: 2022/02/02 13:47:55 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

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

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_img	img;
	t_img	floor;
}				t_vars;

int	close(int keycode, t_vars *vars)
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

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	render_bg(t_img *floor, t_vars *vars)
{
	int	i;
	int	j;

		i = 0;
	while (i < 640)
	{
		j = 0;
		while (j < 480)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, floor->mlx_img, i, j);
			j += floor->height;
		}
		i += floor->width;
	}
}

int	render(t_vars *vars)
{
	if (vars->win)
	{
		render_bg(&vars->floor, vars);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!(vars.mlx))
	{
		perror("Error\nCould'nt initialize MLX\n");
		return (-1);
	}
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	if (!(vars.win))
	{
		printf("Error\nCould'nt initialize window\n");
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (-1);
	}
	//vars.img.mlx_img = mlx_new_image(vars.mlx, 640, 480);
	//vars.img.addr = mlx_get_data_addr(vars.img.mlx_img, &vars.img.bpp,
	//		&vars.img.line_len, &vars.img.endian);
	vars.floor.mlx_img = mlx_xpm_file_to_image (vars.mlx, "./assets/grass.xpm", &vars.floor.width, &vars.floor.height);
	mlx_key_hook(vars.win, close, &vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_hook(vars.win, 17, 0, closex, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_image(vars.mlx, vars.floor.mlx_img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return (0);
}
