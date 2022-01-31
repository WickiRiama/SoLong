/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:31:55 by mriant            #+#    #+#             */
/*   Updated: 2022/01/31 17:22:42 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
		mlx_loop_end(vars->mlx);
	}
	return (0);
}

int	closex(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	mlx_loop_end(vars->mlx);
	return (0);
}

int	resize(t_vars *vars)
{
	(void) vars;
	printf("Not possible\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!(vars.mlx))
	{
		printf("Error\nCould'nt initialize MLX\n");
		return (-1);
	}
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	if (!(vars.win))
	{
		printf("Error\nCould'nt initialize window\n");
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (-1);
	}
	mlx_key_hook(vars.win, close, &vars);
	mlx_hook(vars.win, 17, 0, closex, &vars);
	mlx_hook(vars.win, 25, 0, resize, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return (0);
}
