/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:34:57 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/28 16:26:16 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_var *var, int color)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (color)
	{
		r = color >> 0;
		g = color >> 8;
		b = color >> 16;
	}
	else
	{
		r = 0x000000 >> 16;
		g = 0x000000 >> 8;
		b = 0x000000 >> 0;
	}
	if (X >= 0 && X < WIDTH_WIN && Y > 0 && Y < HEIGHT_WIN)
	{
		DATA[Y * SIZELINE + X * (BPP / 8)] = r;
		DATA[Y * SIZELINE + X * (BPP / 8) + 1] = g;
		DATA[Y * SIZELINE + X * (BPP / 8) + 2] = b;
	}
}

int		lunch_fractol(t_var *var)
{
	if (!ft_strcmp(FRACTOL, "mandelbrot"))
		mandelbrot(var);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}
