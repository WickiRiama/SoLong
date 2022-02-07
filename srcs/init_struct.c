/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:33:20 by mriant            #+#    #+#             */
/*   Updated: 2022/02/07 17:55:21 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_null_map(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
}

void	ft_null_img(t_img *img)
{
	img->mlx_img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}

void	ft_null_hero(t_hero *hero)
{
	hero->front_0 = NULL;
	hero->front_1 = NULL;
	hero->front_2 = NULL;
	hero->back_0 = NULL;
	hero->back_1 = NULL;
	hero->back_2 = NULL;
	hero->left_0 = NULL;
	hero->left_1 = NULL;
	hero->left_2 = NULL;
	hero->right_0 = NULL;
	hero->right_1 = NULL;
	hero->right_2 = NULL;
	hero->x = 0;
	hero->y = 0;
}

void	ft_null_other(t_other *other)
{
	other->count = 0;
	other->pos = NULL;
}

void	ft_init_struct(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	ft_null_map(&(vars->map));
	ft_null_img(&(vars->img));
	ft_null_img(&(vars->floor));
	ft_null_img(&(vars->wall));
	ft_null_img(&(vars->bg));
	ft_null_hero(&(vars->hero));
	ft_null_other(&(vars->collect));
	ft_null_other(&(vars->exit));
}
