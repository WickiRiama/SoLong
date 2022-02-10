/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:01:48 by mriant            #+#    #+#             */
/*   Updated: 2022/02/10 16:58:16 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_tiles(t_vars *vars)
{
	vars->floor.mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/grass.xpm", &vars->floor.width, &vars->floor.height);
	vars->wall.mlx_img = mlx_xpm_file_to_image (vars->mlx, "./assets/tree.xpm",
			&vars->wall.width, &vars->wall.height);
	vars->collect.img[0].mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/marble.xpm", &vars->collect.img[0].width,
			&vars->collect.img[0].height);
	vars->exit.img[0].mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/cdoor.xpm", &vars->exit.img[0].width,
			&vars->exit.img[0].height);
	vars->exit.img[1].mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/odoor.xpm", &vars->exit.img[1].width,
			&vars->exit.img[1].height);
	if (!(vars->floor.mlx_img && vars->wall.mlx_img
			&& vars->collect.img[0].mlx_img && vars->exit.img[0].mlx_img
			&& vars->exit.img[1].mlx_img))
		return (-1);
	return (0);
}

int	ft_init_hero1(t_vars *vars, t_hero *hero)
{
	hero->front[0].mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/front0.xpm", &hero->front[0].width,
			&hero->front[0].height);
	hero->front[1].mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/front1.xpm", &hero->front[1].width,
			&hero->front[1].height);
	hero->front[2].mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/front2.xpm", &hero->front[2].width,
			&hero->front[2].height);
	hero->back[0].mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/back0.xpm", &hero->back[0].width, &hero->back[0].height);
	hero->back[1].mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/back1.xpm", &hero->back[1].width, &hero->back[1].height);
	hero->back[2].mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/back2.xpm", &hero->back[2].width, &hero->back[2].height);
	if (!(hero->front[0].mlx_img && hero->front[1].mlx_img
			&& hero->front[2].mlx_img && hero->back[0].mlx_img
			&& hero->back[1].mlx_img && hero->back[2].mlx_img))
		return (-1);
	return (0);
}

int	ft_init_hero2(t_vars *vars, t_hero *hero)
{
	hero->left[0].mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/left0.xpm", &hero->left[0].width, &hero->left[0].height);
	hero->left[1].mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/left1.xpm", &hero->left[1].width, &hero->left[1].height);
	hero->left[2].mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/left2.xpm", &hero->left[2].width, &hero->left[2].height);
	hero->right[0].mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/right0.xpm", &hero->right[0].width,
			&hero->right[0].height);
	hero->right[1].mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/right1.xpm", &hero->right[1].width,
			&hero->right[1].height);
	hero->right[2].mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/right2.xpm", &hero->right[2].width,
			&hero->right[2].height);
	if (!(hero->left[0].mlx_img && hero->left[1].mlx_img
			&& hero->left[2].mlx_img && hero->right[0].mlx_img
			&& hero->right[1].mlx_img && hero->right[2].mlx_img))
		return (-1);
	hero->current = hero->front;
	return (0);
}

int	ft_init_bg(t_vars *vars)
{
	vars->bg.width = vars->floor.width * vars->map.width;
	vars->bg.height = vars->floor.height * (vars->map.height + 1);
	vars->img.width = vars->floor.width * vars->map.width;
	vars->img.height = vars->floor.height * (vars->map.height + 1);
	vars->bg.mlx_img = mlx_new_image(vars->mlx, vars->bg.width,
			vars->bg.height);
	vars->img.mlx_img = mlx_new_image(vars->mlx, vars->img.width,
			vars->img.height);
	vars->digit.mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/digits.xpm", &vars->digit.width, &vars->digit.height);
	vars->text.mlx_img = mlx_xpm_file_to_image (vars->mlx,
			"./assets/text.xpm", &vars->text.width, &vars->text.height);
	if (!(vars->bg.mlx_img && vars->img.mlx_img && vars->digit.mlx_img
			&& vars->text.mlx_img))
		return (-1);
	return (0);
}
