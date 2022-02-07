/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:12:15 by mriant            #+#    #+#             */
/*   Updated: 2022/02/07 17:32:24 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_map(int i, int j, char *p, t_vars *vars)
{
	if ((i == 0 || i == var->map.width - 1 || j == 0
			|| j == vars->map.height - 1) && c != '1')
		return (-1);
	if (!(c == '1' || c == '0' || c == 'C' || c == 'E'))
		return (-1);
	if (c == 'E')
		vars->exit.count ++;
	if (c == 'C')
		vars->collect.count ++;
	if (c == 'P')
		(*p)++;
	j ++;
	return (0);
}

void	ft_init_pos(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map.grid[i])
	{
		j = 0;
		while (vars->map.grid[i][j])
		{
			if (vars->map.grid[i][j] == 'P')
			{
				vars->hero.x = j;
				vars->hero.y = i;
			}
			if (vars->map.grid[i][j] == 'C')
				vars->collect.count ++;
			if (vars->map.grid[i][j] == 'E')
				vars->exit.count ++;
		}
	}
}
