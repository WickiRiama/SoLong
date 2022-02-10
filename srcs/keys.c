/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:53:33 by mriant            #+#    #+#             */
/*   Updated: 2022/02/10 18:46:34 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_collect(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->collect.count_max)
	{
		if (vars->hero.x == vars->collect.x[i]
			&& vars->hero.y == vars->collect.y[i])
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
			if (vars->hero.x == vars->exit.x[i]
				&& vars->hero.y == vars->exit.y[i])
			{
				printf("Congratulations !\n");
				mlx_loop_end(vars->mlx);
				return ;
			}
			i ++;
		}
	}
}

int	ft_key_release(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_loop_end(vars->mlx);
	return (0);
}

void	ft_move(t_vars *vars, int x, int y)
{
	if (vars->map.grid[vars->hero.y + y][vars->hero.x + x] != '1')
	{
		vars->steps ++;
		vars->hero.x += x;
		vars->hero.y += y;
		printf("steps : %d\n", vars->steps);
	}
}

int	ft_key_press(int keycode, t_vars *vars)
{
	if (keycode == 122)
	{
		ft_move(vars, 0, -1);
		vars->hero.current = vars->hero.back;
	}
	if (keycode == 113)
	{
		ft_move(vars, -1, 0);
		vars->hero.current = vars->hero.left;
	}
	if (keycode == 115)
	{
		ft_move(vars, 0, 1);
		vars->hero.current = vars->hero.front;
	}
	if (keycode == 100)
	{
		ft_move(vars, 1, 0);
		vars->hero.current = vars->hero.right;
	}
	return (0);
}
