/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:31:55 by mriant            #+#    #+#             */
/*   Updated: 2022/02/15 13:58:30 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_preloop(t_vars *vars, char **av)
{
	ft_init_struct(vars);
	vars->mlx = mlx_init();
	if (!(vars->mlx))
	{
		ft_printf("Error\nCould'nt initialize MLX\n");
		return (-1);
	}
	if (ft_build_map(av[1], vars) == -1 || ft_init_pos(vars) == -1)
		return (-1);
	vars->win = mlx_new_window(vars->mlx, vars->map.width * 48,
			(vars->map.height + 1) * 48, "Granny lost her marbles");
	if (!(vars->win))
	{
		ft_printf("Error\nCould'nt initialize window\n");
		return (-1);
	}
	if (ft_set_img(vars) == -1)
	{
		ft_printf("Eroor\nCouldn't process images\n");
		return (-1);
	}
	ft_render_bg(vars);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
	{
		ft_printf("Error\nPass the path to the map as argument.\n");
		return (-1);
	}
	if (ft_preloop(&vars, av) == -1)
	{
		ft_clean_all(&vars);
		return (-1);
	}
	mlx_hook(vars.win, 17, 0, mlx_loop_end, (&vars)->mlx);
	mlx_hook(vars.win, 02, (1L << 0), ft_key_press, &vars);
	mlx_key_hook(vars.win, ft_key_release, &vars);
	mlx_loop_hook(vars.mlx, ft_render, &vars);
	mlx_loop(vars.mlx);
	ft_clean_all(&vars);
	return (0);
}
