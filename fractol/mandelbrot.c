/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:36:00 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/31 19:09:24 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot(t_var *var)
{
	double		tmp;
	int			i;

	X1 = -2.1;
	X2 = 0.6;
	Y1 = -1.2;
	Y2 = 1.2;
	if (PLAY)
	{
		I_MAX = (I_MAX) ? I_MAX + 1: 20;
		I_MAX = (I_MAX > 80) ? 20 : I_MAX;
	}
	I_MAX = (!PLAY) ? 50 : I_MAX;
	ZOOM_X = (WIDTH_WIN / (X2 - X1) + ZOOM);
	ZOOM_Y = (HEIGHT_WIN / (Y2 - Y1) + ZOOM);
	X = -1;
	while (++X < WIDTH_WIN)
	{
		Y = -1;
		while (++Y < HEIGHT_WIN)
		{
			CR = X / ZOOM_X + X1;
			CI = Y / ZOOM_Y + Y1;
			ZR = 0;
			ZI = 0;
			i = -1;
			while ((ZR * ZR + ZI * ZI) < 4 && ++i < I_MAX)
			{
				tmp = ZR;
				ZR = ZR * ZR - ZI * ZI + CR;
				ZI = 2 * ZI * tmp + CI;
			}
			if (i == I_MAX)
				put_pixel(var, BLACK);
			else
				put_pixel(var, i * COLOR / I_MAX);
		}
	}
}
