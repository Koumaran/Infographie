/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_trade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 10:53:46 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/28 14:55:36 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf(t_mlx *mlx, int len)
{
	int			i;
	t_point		p1;
	t_point		p2;

	i = -1;
	while (++i < len)
	{
		get_point(mlx, &p1, i);
		if (i - 1 >= 0 && i % mlx->size_x != 0)
		{
			get_point(mlx, &p2, i - 1);
			bresenham(mlx, &p1, &p2);
		}
		if (i - mlx->size_x >= 0)
		{
			get_point(mlx, &p2, i - mlx->size_x);
			bresenham(mlx, &p1, &p2);
		}
	}
}

void		create_image(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, WIN_SIZEX, WIN_SIZEY);
	mlx->data = mlx_get_data_addr(mlx->img,
			&mlx->bpp, &mlx->size_line, &mlx->endian);
	fdf(mlx, mlx->size_x * mlx->size_y);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img);
}
