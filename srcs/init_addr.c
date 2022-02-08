/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_addr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:36:46 by mriant            #+#    #+#             */
/*   Updated: 2022/02/08 15:37:40 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_addr_hero1(t_hero *hero)
{
	hero->front[0].addr = mlx_get_data_addr(hero->front[0].mlx_img,
			&hero->front[0].bpp, &hero->front[0].line_len,
			&hero->front[0].endian);
	hero->front[1].addr = mlx_get_data_addr(hero->front[1].mlx_img,
			&hero->front[1].bpp, &hero->front[1].line_len,
			&hero->front[1].endian);
	hero->front[2].addr = mlx_get_data_addr(hero->front[2].mlx_img,
			&hero->front[2].bpp, &hero->front[2].line_len,
			&hero->front[2].endian);
	hero->back[0].addr = mlx_get_data_addr(hero->back[0].mlx_img,
			&hero->back[0].bpp, &hero->back[0].line_len, &hero->back[0].endian);
	hero->back[1].addr = mlx_get_data_addr(hero->back[1].mlx_img,
			&hero->back[1].bpp, &hero->back[1].line_len, &hero->back[1].endian);
	hero->back[2].addr = mlx_get_data_addr(hero->back[2].mlx_img,
			&hero->back[2].bpp, &hero->back[2].line_len, &hero->back[2].endian);
	if (!(hero->front[0].addr && hero->front[1].addr && hero->front[2].addr
			&& hero->back[0].addr && hero->back[1].addr && hero->back[2].addr))
		return (-1);
	return (0);
}

int	ft_addr_hero2(t_hero *hero)
{
	hero->left[0].addr = mlx_get_data_addr(hero->left[0].mlx_img,
			&hero->left[0].bpp, &hero->left[0].line_len, &hero->left[0].endian);
	hero->left[1].addr = mlx_get_data_addr(hero->left[1].mlx_img,
			&hero->left[1].bpp, &hero->left[1].line_len, &hero->left[1].endian);
	hero->left[2].addr = mlx_get_data_addr(hero->left[2].mlx_img,
			&hero->left[2].bpp, &hero->left[2].line_len, &hero->left[2].endian);
	hero->right[0].addr = mlx_get_data_addr(hero->right[0].mlx_img,
			&hero->right[0].bpp, &hero->right[0].line_len,
			&hero->right[0].endian);
	hero->right[1].addr = mlx_get_data_addr(hero->right[1].mlx_img,
			&hero->right[1].bpp, &hero->right[1].line_len,
			&hero->right[1].endian);
	hero->right[2].addr = mlx_get_data_addr(hero->right[2].mlx_img,
			&hero->right[2].bpp, &hero->right[2].line_len,
			&hero->right[2].endian);
	if (!(hero->left[0].addr && hero->left[1].addr && hero->left[2].addr
			&& hero->right[0].addr && hero->right[1].addr
			&& hero->right[2].addr))
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
	vars->collect.img.addr = mlx_get_data_addr(vars->collect.img.mlx_img,
			&vars->collect.img.bpp, &vars->collect.img.line_len,
			&vars->collect.img.endian);
	vars->exit.img.addr = mlx_get_data_addr(vars->exit.img.mlx_img,
			&vars->exit.img.bpp, &vars->exit.img.line_len,
			&vars->exit.img.endian);
	if (!(vars->floor.addr && vars->wall.addr && vars->img.addr
			&& vars->bg.addr && vars->collect.img.addr && vars->exit.img.addr))
		return (-1);
	return (0);
}

int	ft_set_img(t_vars *vars)
{
	int	ret1;
	int	ret2;
	int	ret3;

	ret1 = ft_init_tiles(vars);
	ret2 = ft_init_hero1(vars, &(vars->hero));
	ret3 = ft_init_hero2(vars, &(vars->hero));
	if (ret1 == -1 || ret2 == -1 || ret3 == -1)
		return (-1);
	ret1 = ft_init_bg(vars);
	if (ret1 == -1)
		return (-1);
	ret1 = ft_addr_tiles(vars);
	ret2 = ft_addr_hero1(&(vars->hero));
	ret3 = ft_addr_hero2(&(vars->hero));
	if (ret1 == -1 || ret2 == -1 || ret3 == -1)
		return (-1);
	return (0);
}
