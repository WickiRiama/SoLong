/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:01:48 by mriant            #+#    #+#             */
/*   Updated: 2022/02/07 12:06:29 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_tiles(t_vars vars)
{
	vars->floor.mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/grass.xpm", &vars->floor.width, &vars->floor.height);
	vars->wall.mlx_img = mlx_xpm_file_to_image (vars->mlx, "./assets/tree.xpm",
			&vars->wall.width, &vars->wall.height);
	vars->front0.mlx_img = mlx_xpm_file_to_image (vars->mlx, "./assets/front0.xpm",
			&vars->front0.width, &vars->front0.height);
	vars->front1.mlx_img = mlx_xpm_file_to_image (vars->mlx, "./assets/front1.xpm",
			&vars->front1.width, &vars->front1.height);
	vars->front2.mlx_img = mlx_xpm_file_to_image (vars->mlx, "./assets/front2.xpm",
			&vars->front2.width, &vars->front2.height);
	vars->back0.mlx_img = mlx_xpm_file_to_image (vars->mlx, "./assets/back0.xpm",
			&vars->back0.width, &vars->back0.height);
	vars->back1.mlx_img = mlx_xpm_file_to_image (vars->mlx, "./assets/back1.xpm",
			&vars->back1.width, &vars->back1.height);
	vars->back2.mlx_img = mlx_xpm_file_to_image (vars->mlx, "./assets/back2.xpm",
			&vars->back2.width, &vars->back2.height);
	vars->left0.mlx_img = mlx_xpm_file_to_image (vars->mlx, "./assets/left0.xpm",
			&vars->left0.width, &vars->left0.height);
	vars->left1.mlx_img = mlx_xpm_file_to_image (vars->mlx, "./assets/left1.xpm",
			&vars->left1.width, &vars->left1.height);
	vars->left2.mlx_img = mlx_xpm_file_to_image (vars->mlx, "./assets/left2.xpm",
			&vars->left2.width, &vars->left2.height);
	vars->right0.mlx_img = mlx_xpm_file_to_image (vars->mlx, "./assets/left0.xpm",
			&vars->right0.width, &vars->right0.height);
	vars->right1.mlx_img = mlx_xpm_file_to_image (vars->mlx, "./assets/left1.xpm",
			&vars->right1.width, &vars->right1.height);
	vars->right2.mlx_img = mlx_xpm_file_to_image (vars->mlx, "./assets/left2.xpm",
			&vars->right2.width, &vars->right2.height);
	if (!vars->floor.mlx_img || !vars->wall.mlx_img)
		return (-1);
	return (0);
}

int	ft_init_bg(t_vars *vars)
{
	vars->bg.width = vars->floor.width * vars->map.width;
	vars->bg.height = vars->floor.height * vars->map.height;
	vars->img.width = vars->floor.width * vars->map.width;
	vars->img.height = vars->floor.height * vars->map.height;
	vars->bg.mlx_img = mlx_new_image(vars->mlx, vars->bg.width,
			vars->bg.height);
	vars->img.mlx_img = mlx_new_image(vars->mlx, vars->img.width,
			vars->img.height);
	if (!vars->bg.mlx_img || !vars->img.mlx_img)
		return (-1);
	return (0);
}

int	ft_addr_tiles(t_vars *vars)
{
	vars->floor.addr = mlx_get_data_addr(vars->floor.mlx_img, &vars->floor.bpp,
			&vars->floor.line_len, &vars->floor.endian);
	vars->wall.addr = mlx_get_data_addr(vars->wall.mlx_img, &vars->wall.bpp,
			&vars->wall.line_len, &vars->wall.endian);
	vars->img.addr = mlx_get_data_addr(vars->img.mlx_img, &vars->img.bpp,
			&vars->img.line_len, &vars->img.endian);
	vars->bg.addr = mlx_get_data_addr(vars->bg.mlx_img, &vars->bg.bpp,
			&vars->bg.line_len, &vars->bg.endian);
	if (!(vars->floor.addr && vars->wall.addr && vars->img.addr
			&& vars->bg.addr))
		return (-1);
	return (0);
}

int	ft_set_img(t_vars *vars)
{
	int	ret;

	ret = ft_init_tiles(vars);
	ret = ft_init_bg(vars);
	ret = ft_addr_tiles(vars);
}
