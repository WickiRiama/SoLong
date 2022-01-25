/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:31:55 by mriant            #+#    #+#             */
/*   Updated: 2022/01/25 16:19:16 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_data;

void	my_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int *trgb)
{
	return (trgb[0] << 24 | trgb[1] << 16 | trgb[2] << 8 | trgb[3]);
}

void	shift_colors(int (*trgb)[4], int i)
{
	if (i < 126)
		(*trgb)[3] ++;
	else if (i < 255)
	{
		(*trgb)[3] ++;
		(*trgb)[2] ++;
	}
	else if (i < 381)
	{
		(*trgb)[3] --;
		(*trgb)[2] ++;
		(*trgb)[1] ++;
	}
	else if (i < 511)
	{
		(*trgb)[3] --;
		(*trgb)[2] --;
		(*trgb)[1] ++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		i;
	int				j;
	int		trgb[4];
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1000, "Granny lost her cats");
	img.img = mlx_new_image(mlx, 1920, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len, &img.endian);
	i = 0;
	trgb[0] = 0;
	trgb[1] = 0;
	trgb[2] = 0;
	trgb[3] = 0;
	while (i < 1920)
	{
		j = 0;
		while (j < 1000)
		{
			my_pixel_put(&img, i, j, create_trgb(trgb));
			j ++;
		}
		i ++;
		shift_colors(&trgb, i);
	}
 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
