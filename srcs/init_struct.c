/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:33:20 by mriant            #+#    #+#             */
/*   Updated: 2022/02/11 15:03:24 by mriant           ###   ########.fr       */
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
	ft_null_img(&hero->front[0]);
	ft_null_img(&hero->front[1]);
	ft_null_img(&hero->front[2]);
	ft_null_img(&hero->back[0]);
	ft_null_img(&hero->back[1]);
	ft_null_img(&hero->back[2]);
	ft_null_img(&hero->left[0]);
	ft_null_img(&hero->left[1]);
	ft_null_img(&hero->left[2]);
	ft_null_img(&hero->right[0]);
	ft_null_img(&hero->right[1]);
	ft_null_img(&hero->right[2]);
	hero->current = NULL;
	hero->x = 0;
	hero->y = 0;
	hero->state = 0;
	hero->move[0] = 0;
	hero->move[1] = 0;
}

void	ft_null_other(t_other *other)
{
	other->count = 0;
	other->count_max = 0;
	other->x = NULL;
	other->y = NULL;
	other->state = 0;
	ft_null_img(&other->img[0]);
	ft_null_img(&other->img[1]);
}

void	ft_init_struct(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->steps = 0;
	vars->delay = 0;
	ft_null_map(&(vars->map));
	ft_null_img(&(vars->img));
	ft_null_img(&(vars->floor));
	ft_null_img(&(vars->wall));
	ft_null_img(&(vars->bg));
	ft_null_img(&vars->digit);
	ft_null_img(&vars->text);
	ft_null_hero(&(vars->hero));
	ft_null_other(&(vars->collect));
	ft_null_other(&(vars->exit));
}
