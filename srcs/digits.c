/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:26:33 by mriant            #+#    #+#             */
/*   Updated: 2022/02/10 18:25:50 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_digits(t_vars *vars, int i, int digit)
{
	int		x;
	int		y;
	char	*pixel;

	if (i < 0)
		return ;
	x = digit * vars->digit.width / 10;
	while (x < (digit + 1) * vars->digit.width / 10)
	{
		y = 0;
		while (y < vars->digit.height)
		{
			pixel = vars->digit.addr + (y * vars->digit.line_len
					+ x * (vars->digit.bpp / 8));
			ft_img_pix_put(&vars->img, x - digit * vars->digit.width / 10
				+ vars->text.width + i * vars->digit.width / 10, y
				+ vars->map.height * vars->digit.height, pixel);
			y ++;
		}
		x ++;
	}
}

void	ft_itoimg(int n, t_vars *vars)
{
	int		i;
	int		digit;
	char	*s;
	int		len_max;

	s = ft_itoa(n);
	if (!s)
		return ;
	len_max = (vars->img.width - vars->text.width) / (vars->digit.width / 10);
	i = 0;
	while (s[i] && i < len_max)
	{
		digit = s[i] - '0';
		ft_render_digits(vars, i, digit);
		i ++;
	}
	free(s);
}
