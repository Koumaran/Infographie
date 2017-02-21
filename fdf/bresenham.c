/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:18:33 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/28 14:56:19 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			pxl_putimg(t_mlx *mlx, int x, int y, int color)
{
	int				i;
	int				dest;

	if (y < 0 || x < 0)
		return ;
	dest = y * mlx->size_line + x * (mlx->bpp / 8);
	i = -1;
	if (dest + (mlx->bpp / 8) < mlx->size_line * WIN_SIZEY)
		while (++i < mlx->bpp / 8)
		{
			if (mlx->endian == 0)
				mlx->data[dest + i] = color >> (i * 8) & 0xFF;
			else
				mlx->data[dest + i] = color >> (mlx->bpp - (i + 1) * 8) & 0xFF;
		}
}

static void		draw_vertical(t_mlx *mlx, t_bresenham *b, int color)
{
	int		i;

	i = -1;
	b->cumul = b->dy / 2;
	while (++i <= b->dy)
	{
		b->y += b->yinc;
		b->cumul += b->dx;
		if (b->cumul >= b->dy)
		{
			b->cumul -= b->dy;
			b->x += b->xinc;
		}
		if (b->y < WIN_SIZEY && b->x < mlx->size_line - 4)
			pxl_putimg(mlx, b->x, b->y, color);
	}
}

static void		draw_horizontal(t_mlx *mlx, t_bresenham *b, int color)
{
	int		i;

	i = -1;
	b->cumul = b->dx / 2;
	while (++i <= b->dx)
	{
		b->x += b->xinc;
		b->cumul += b->dy;
		if (b->cumul >= b->dx)
		{
			b->cumul -= b->dx;
			b->y += b->yinc;
		}
		if (b->y < WIN_SIZEY && b->x < mlx->size_line - 4)
			pxl_putimg(mlx, b->x, b->y, color);
	}
}

void			bresenham(t_mlx *mlx, t_point *p1, t_point *p2)
{
	t_bresenham		b;

	b.x = p1->x;
	b.y = p1->y;
	b.dx = p2->x - p1->x;
	b.dy = p2->y - p1->y;
	b.xinc = (b.dx > 0) ? 1 : -1;
	b.yinc = (b.dy > 0) ? 1 : -1;
	b.dx = abs(b.dx);
	b.dy = abs(b.dy);
	if (b.y < WIN_SIZEY && b.x < mlx->size_line - 4)
		pxl_putimg(mlx, b.x, b.y, p1->color);
	if (b.dx > b.dy)
		draw_horizontal(mlx, &b, p2->color);
	else
		draw_vertical(mlx, &b, p2->color);
}
