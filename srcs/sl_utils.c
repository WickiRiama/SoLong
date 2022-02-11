/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:18:55 by mriant            #+#    #+#             */
/*   Updated: 2022/02/11 18:04:06 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_img_pix_put(t_img *img, int x, int y, char *color)
{
	char	*pixel;
	int		i;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	i = 0;
	while (i < img->bpp)
	{
		if (*color)
			*pixel = *color;
		pixel ++;
		color ++;
		i += 8;
	}
}

void	ft_anim(t_vars *vars)
{
	if (vars->delay == 0 && vars->hero.state != 0)
	{
		vars->delay = 10;
		vars->hero.state = (vars->hero.state + 1) % 3;
		vars->hero.x += vars->hero.move[0] * vars->floor.width / 3;
		vars->hero.y += vars->hero.move[1] * vars->floor.height / 3;
	}
	else
		vars->delay --;
	ft_check_collect(vars);
	ft_check_exit(vars);
	ft_check_foe(vars);
}

int	ft_set_img(t_vars *vars)
{
	int	ret1;
	int	ret2;
	int	ret3;
	int	ret4;

	ret1 = ft_init_tiles(vars);
	ret2 = ft_init_hero1(vars, &(vars->hero));
	ret3 = ft_init_hero2(vars, &(vars->hero));
	if (ret1 == -1 || ret2 == -1 || ret3 == -1)
		return (-1);
	ret4 = ft_init_bg(vars);
	if (ret4 == -1)
		return (-1);
	ret1 = ft_addr_tiles(vars);
	ret2 = ft_addr_hero1(&(vars->hero));
	ret3 = ft_addr_hero2(&(vars->hero));
	ret4 = ft_addr_bg(vars);
	if (ret1 == -1 || ret2 == -1 || ret3 == -1 || ret4 == -1)
		return (-1);
	return (0);
}
