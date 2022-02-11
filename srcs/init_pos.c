/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:12:15 by mriant            #+#    #+#             */
/*   Updated: 2022/02/11 17:50:28 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_assets(unsigned int i, unsigned int j, int *p, t_vars *vars)
{
	char	c;

	c = vars->map.grid[i][j];
	if ((i == 0 || i == vars->map.height - 1 || j == 0
			|| j == vars->map.width - 1) && c != '1')
		return (-1);
	if (!(c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P' || c == 'F'))
		return (-1);
	if (c == 'E')
		vars->exit.count ++;
	if (c == 'C')
		vars->collect.count ++;
	if (c == 'F')
		vars->foe.count ++;
	if (c == 'P')
	{
		(*p)++;
		vars->hero.x = j;
		vars->hero.y = i;
	}
	return (0);
}

int	ft_alloc_pos(t_vars *vars)
{
	vars->collect.x = malloc(sizeof(int) * vars->collect.count);
	vars->collect.y = malloc(sizeof(int) * vars->collect.count);
	vars->exit.x = malloc(sizeof(int) * vars->exit.count);
	vars->exit.y = malloc(sizeof(int) * vars->exit.count);
	vars->foe.x = malloc(sizeof(int) * vars->foe.count);
	vars->foe.y = malloc(sizeof(int) * vars->foe.count);
	if (!(vars->collect.x && vars->collect.y && vars->exit.x && vars->exit.y
			&& vars->foe.x && vars->foe.y))
	{
		printf("Error\nMalloc error\n");
		return (-1);
	}
	return (0);
}

void	ft_set_pos(t_other *other, int i, int j)
{
	other->x[other->count_max] = j;
	other->y[other->count_max] = i;
	other->count_max ++;
}

int	ft_init_pos(t_vars *vars)
{
	int	i;
	int	j;

	if (ft_alloc_pos(vars) == -1)
		return (-1);
	i = 0;
	while (vars->map.grid[i])
	{
		j = 0;
		while (vars->map.grid[i][j])
		{
			if (vars->map.grid[i][j] == 'C')
				ft_set_pos(&vars->collect, i, j);
			if (vars->map.grid[i][j] == 'E')
				ft_set_pos(&vars->exit, i, j);
			if (vars->map.grid[i][j] == 'F')
				ft_set_pos(&vars->foe, i, j);
			j ++;
		}
		i ++;
	}
	return (0);
}
