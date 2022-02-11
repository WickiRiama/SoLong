/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:31:01 by mriant            #+#    #+#             */
/*   Updated: 2022/02/11 17:54:59 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clean_img(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.mlx_img);
	mlx_destroy_image(vars->mlx, vars->floor.mlx_img);
	mlx_destroy_image(vars->mlx, vars->bg.mlx_img);
	mlx_destroy_image(vars->mlx, vars->wall.mlx_img);
	mlx_destroy_image(vars->mlx, vars->digit.mlx_img);
	mlx_destroy_image(vars->mlx, vars->text.mlx_img);
	mlx_destroy_image(vars->mlx, vars->hero.front[0].mlx_img);
	mlx_destroy_image(vars->mlx, vars->hero.front[1].mlx_img);
	mlx_destroy_image(vars->mlx, vars->hero.front[2].mlx_img);
	mlx_destroy_image(vars->mlx, vars->hero.back[0].mlx_img);
	mlx_destroy_image(vars->mlx, vars->hero.back[1].mlx_img);
	mlx_destroy_image(vars->mlx, vars->hero.back[2].mlx_img);
	mlx_destroy_image(vars->mlx, vars->hero.left[0].mlx_img);
	mlx_destroy_image(vars->mlx, vars->hero.left[1].mlx_img);
	mlx_destroy_image(vars->mlx, vars->hero.left[2].mlx_img);
	mlx_destroy_image(vars->mlx, vars->hero.right[0].mlx_img);
	mlx_destroy_image(vars->mlx, vars->hero.right[1].mlx_img);
	mlx_destroy_image(vars->mlx, vars->hero.right[2].mlx_img);
	mlx_destroy_image(vars->mlx, vars->collect.img[0].mlx_img);
	mlx_destroy_image(vars->mlx, vars->foe.img[0].mlx_img);
	mlx_destroy_image(vars->mlx, vars->exit.img[0].mlx_img);
	mlx_destroy_image(vars->mlx, vars->exit.img[1].mlx_img);
}

void	ft_clean_all(t_vars *vars)
{
	int	ret;

	ft_clean_img(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->collect.x);
	free(vars->collect.y);
	free(vars->exit.x);
	free(vars->exit.y);
	free(vars->foe.x);
	free(vars->foe.y);
	free(vars->mlx);
	ret = 0;
	while (vars->map.grid[ret])
	{
		free(vars->map.grid[ret]);
		ret ++;
	}
	free(vars->map.grid);
}
