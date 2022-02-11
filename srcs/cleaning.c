/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:31:01 by mriant            #+#    #+#             */
/*   Updated: 2022/02/11 19:17:49 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clean_img(t_vars *vars, t_img img)
{
	if (img.mlx_img)
		mlx_destroy_image(vars->mlx, img.mlx_img);
}

void	ft_destroy_img(t_vars *vars)
{
	ft_clean_img(vars, vars->img);
	ft_clean_img(vars, vars->floor);
	ft_clean_img(vars, vars->bg);
	ft_clean_img(vars, vars->wall);
	ft_clean_img(vars, vars->digit);
	ft_clean_img(vars, vars->text);
	ft_clean_img(vars, vars->hero.front[0]);
	ft_clean_img(vars, vars->hero.front[1]);
	ft_clean_img(vars, vars->hero.front[2]);
	ft_clean_img(vars, vars->hero.back[0]);
	ft_clean_img(vars, vars->hero.back[1]);
	ft_clean_img(vars, vars->hero.back[2]);
	ft_clean_img(vars, vars->hero.left[0]);
	ft_clean_img(vars, vars->hero.left[1]);
	ft_clean_img(vars, vars->hero.left[2]);
	ft_clean_img(vars, vars->hero.right[0]);
	ft_clean_img(vars, vars->hero.right[1]);
	ft_clean_img(vars, vars->hero.right[2]);
	ft_clean_img(vars, vars->collect.img[0]);
	ft_clean_img(vars, vars->foe.img[0]);
	ft_clean_img(vars, vars->exit.img[0]);
	ft_clean_img(vars, vars->exit.img[1]);
}

void	ft_clean_all(t_vars *vars)
{
	int	ret;

	ft_destroy_img(vars);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	free(vars->collect.x);
	free(vars->collect.y);
	free(vars->exit.x);
	free(vars->exit.y);
	free(vars->foe.x);
	free(vars->foe.y);
	free(vars->mlx);
	if (vars->map.grid)
	{
		ret = 0;
		while (vars->map.grid[ret])
		{
			free(vars->map.grid[ret]);
			ret ++;
		}
		free(vars->map.grid);
	}
}
