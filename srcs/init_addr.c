/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_addr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:36:46 by mriant            #+#    #+#             */
/*   Updated: 2022/02/07 14:09:40 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_addr_hero1(t_hero *hero)
{
	hero->front0.addr = mlx_get_data_addr(hero->front0.mlx_img,
			&hero->front0.bpp, &hero->front0.line_len, &hero->front0.endian);
	hero->front1.addr = mlx_get_data_addr(hero->front1.mlx_img,
			&hero->front1.bpp, &hero->front1.line_len, &hero->front1.endian);
	hero->front2.addr = mlx_get_data_addr(hero->front2.mlx_img,
			&hero->front2.bpp, &hero->front2.line_len, &hero->front2.endian);
	hero->back0.addr = mlx_get_data_addr(hero->back0.mlx_img,
			&hero->back0.bpp, &hero->back0.line_len, &hero->back0.endian);
	hero->back1.addr = mlx_get_data_addr(hero->back1.mlx_img,
			&hero->back1.bpp, &hero->back1.line_len, &hero->back1.endian);
	hero->back2.addr = mlx_get_data_addr(hero->back2.mlx_img,
			&hero->back2.bpp, &hero->back2.line_len, &hero->back2.endian);
	if (!(hero->front0.addr && hero->front1.addr && hero->front2.addr
			&& hero->back0.addr && hero->back1.addr && hero->back2.addr))
		return (-1);
	return (0);
}

int	ft_addr_hero2(t_hero *hero)
{
	hero->left0.addr = mlx_get_data_addr(hero->left0.mlx_img,
			&hero->left0.bpp, &hero->left0.line_len, &hero->left0.endian);
	hero->left1.addr = mlx_get_data_addr(hero->left1.mlx_img,
			&hero->left1.bpp, &hero->left1.line_len, &hero->left1.endian);
	hero->left2.addr = mlx_get_data_addr(hero->left2.mlx_img,
			&hero->left2.bpp, &hero->left2.line_len, &hero->left2.endian);
	hero->right0.addr = mlx_get_data_addr(hero->right0.mlx_img,
			&hero->right0.bpp, &hero->right0.line_len, &hero->right0.endian);
	hero->right1.addr = mlx_get_data_addr(hero->right1.mlx_img,
			&hero->right1.bpp, &hero->right1.line_len, &hero->right1.endian);
	hero->right2.addr = mlx_get_data_addr(hero->right2.mlx_img,
			&hero->right2.bpp, &hero->right2.line_len, &hero->right2.endian);
	if (!(hero->left0.addr && hero->left1.addr && hero->left2.addr
			&& hero->right0.addr && hero->right1.addr && hero->right2.addr))
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
	int	ret1;
	int	ret2;
	int	ret3;

	ret1 = ft_init_tiles(vars);
	ret2 = ft_init_hero1(&(vars->hero));
	ret3 = ft_init_hero2(&(vars->hero));
	if (!(ret1 && ret2 && ret3))
		return (-1);
	ret1 = ft_init_bg(vars);
	if (!ret1)
		return (-1);
	ret1 = ft_addr_tiles(vars);
	ret2 = ft_addr_hero1(&(vars->hero));
	ret3 = ft_addr_hero2(&(vars->hero));
	if (!(ret1 && ret2 && ret3))
		return (-1);
	return (0);
}
