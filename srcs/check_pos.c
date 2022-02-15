/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:57:50 by mriant            #+#    #+#             */
/*   Updated: 2022/02/15 11:13:14 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_collect(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->collect.count_max)
	{
		if (vars->hero.x == vars->collect.x[i] * vars->floor.width
			&& vars->hero.y == vars->collect.y[i] * vars->floor.height)
		{
			vars->collect.x[i] = -1;
			vars->collect.y[i] = -1;
			vars->collect.count --;
			return ;
		}
		i ++;
	}
	if (vars->collect.count == 0)
		vars->exit.state = 1;
}

void	ft_check_exit(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->exit.state == 1)
	{
		while (i < vars->exit.count)
		{
			if (vars->hero.x == vars->exit.x[i] * vars->floor.width
				&& vars->hero.y == vars->exit.y[i] * vars->floor.height)
			{
				ft_printf("Congratulations !\n");
				mlx_loop_end(vars->mlx);
				return ;
			}
			i ++;
		}
	}
}

void	ft_check_foe(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->foe.count_max)
	{
		if (vars->hero.x == vars->foe.x[i] * vars->floor.width
			&& vars->hero.y == vars->foe.y[i] * vars->floor.height)
		{
			ft_printf("Try again !\n");
			mlx_loop_end(vars->mlx);
			return ;
		}
		i ++;
	}
}
