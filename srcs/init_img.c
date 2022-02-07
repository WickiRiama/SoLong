/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:01:48 by mriant            #+#    #+#             */
/*   Updated: 2022/02/07 13:50:23 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_tiles(t_vars vars)
{
	vars->floor.mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/grass.xpm", &vars->floor.width, &vars->floor.height);
	vars->wall.mlx_img = mlx_xpm_file_to_image (vars->mlx, "./assets/tree.xpm",
			&vars->wall.width, &vars->wall.height);
	if (!vars->floor.mlx_img || !vars->wall.mlx_img)
		return (-1);
	return (0);
}

int	ft_init_hero1(t_hero *hero)
{
	hero->front0.mlx_img = mlx_xpm_file_to_image (vars->heromlx,
			"./assets/front0.xpm", &hero->front0.width, &hero->front0.height);
	hero->front1.mlx_img = mlx_xpm_file_to_image (hero->mlx,
			"./assets/front1.xpm", &hero->front1.width, &hero->front1.height);
	hero->front2.mlx_img = mlx_xpm_file_to_image (hero->mlx,
			"./assets/front2.xpm", &hero->front2.width, &hero->front2.height);
	hero->back0.mlx_img = mlx_xpm_file_to_image (hero->mlx,
			"./assets/back0.xpm", &hero->back0.width, &hero->back0.height);
	hero->back1.mlx_img = mlx_xpm_file_to_image (hero->mlx,
			"./assets/back1.xpm", &hero->back1.width, &hero->back1.height);
	hero->back2.mlx_img = mlx_xpm_file_to_image (hero->mlx,
			"./assets/back2.xpm", &hero->back2.width, &hero->back2.height);
	if (!(hero->front0.mlx_img && hero->front1.mlx_img && hero->front2.mlx_img
			&& hero->back0.mlx_img && hero->back1.mlx_img
			&& hero->back2.mlx_img))
		return (-1);
	return (0);
}

int	ft_init_hero2(t_hero hero)
{
	hero->left0.mlx_img = mlx_xpm_file_to_image (hero->mlx,
			"./assets/left0.xpm", &hero->left0.width, &hero->left0.height);
	hero->left1.mlx_img = mlx_xpm_file_to_image (hero->mlx,
			"./assets/left1.xpm", &hero->left1.width, &hero->left1.height);
	hero->left2.mlx_img = mlx_xpm_file_to_image (hero->mlx,
			"./assets/left2.xpm", &hero->left2.width, &hero->left2.height);
	hero->right0.mlx_img = mlx_xpm_file_to_image (hero->mlx,
			"./assets/left0.xpm", &hero->right0.width, &hero->right0.height);
	hero->right1.mlx_img = mlx_xpm_file_to_image (hero->mlx,
			"./assets/left1.xpm", &hero->right1.width, &hero->right1.height);
	hero->right2.mlx_img = mlx_xpm_file_to_image (hero->mlx,
			"./assets/left2.xpm", &hero->right2.width, &hero->right2.height);
	if (!(hero->left0.mlx_img && hero->left1.mlx_img && hero->left2.mlx_img
			&& hero->right0.mlx_img && hero->right1.mlx_img
			&& hero->right2.mlx_img))
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
