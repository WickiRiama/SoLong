/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:31:55 by mriant            #+#    #+#             */
/*   Updated: 2022/02/07 18:12:02 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_loop_end(vars->mlx);
	return (0);
}

void	ft_clean_all(t_vars *vars)
{
	int	ret;

	mlx_destroy_image(vars->mlx, vars->img.mlx_img);
	mlx_destroy_image(vars->mlx, vars->floor.mlx_img);
	mlx_destroy_image(vars->mlx, vars->bg.mlx_img);
	mlx_destroy_image(vars->mlx, vars->wall.mlx_img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	ret = 0;
	while (vars->map.grid[ret])
	{
		free(vars->map.grid[ret]);
		ret ++;
	}
	free(vars->map.grid);
}

int	ft_preloop(t_vars *vars)
{
	if (ft_build_map(av[1], vars) == -1)
		return (-1);
	vars->mlx = mlx_init();
	if (!(vars->mlx))
	{
		printf("Error\nCould'nt initialize MLX\n");
		return (-1);
	}
	vars->win = mlx_new_window(vars->mlx, vars->map.width * 48,
			vars->map.height * 48, "So long");
	if (!(vars->win))
	{
		printf("Error\nCould'nt initialize window\n");
		return (-1);
	}
	if (ft_set_img(vars) == -1)
	{
		printf("Eroor\nCouldn't process images\n");
		return (-1);
	}
	render_bg(vars);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		ret;

	if (ac != 2)
	{
		printf("Error\nPass the path to the map as argument.\n");
		return (-1);
	}
	ret = ft_preloop(&vars);
	if (ret == -1)
		return (-1);
	mlx_key_hook(vars.win, key_release, &vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_hook(vars.win, 17, 0, mlx_loop_end, &vars);
	mlx_loop(vars.mlx);
	ft_clean_all(&vars);
	return (0);
}
