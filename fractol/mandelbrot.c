/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:36:00 by jsivanes          #+#    #+#             */
/*   Updated: 2017/03/14 18:40:38 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_mandelbrot2(t_var *var)
{
	CR = (X + (ZOOM ? ZOOM : 1) - NX) / ZOOM_X + X1;
	CI = (Y + (ZOOM ? ZOOM : 1) - NY) / ZOOM_Y + Y1;
	ZR = 0 + V * 10;
	ZI = 0 + V / 2;
	I = -1;
	while ((ZR * ZR + ZI * ZI) < 4 && ++I < I_MAX)
	{
		TMP_D = ZR;
		ZR = ZR * ZR - ZI * ZI + CR;
		ZI = 2 * ZI * TMP_D + CI;
	}
	if (I == I_MAX)
		put_pixel(var, BLACK);
	else
		put_pixel(var, M_COLOR ? (I * COLOR / I_MAX) : I * COLOR);
}

void			ft_mandelbrot(t_var *var)
{
	X1 = -2.1 + POS_X;
	X2 = 0.6 + POS_X;
	Y1 = -1.2 + POS_Y;
	Y2 = 1.2 + POS_Y;
	I_MAX = IM + 50;
	ZOOM_X = (WIDTH_WIN / (X2 - X1) + (ZOOM ? ZOOM : 1));
	ZOOM_Y = (HEIGHT_WIN / (Y2 - Y1) + (ZOOM ? ZOOM : 1));
	X = -1;
	while (++X < WIDTH_WIN)
	{
		Y = -1;
		while (++Y < HEIGHT_WIN)
			ft_mandelbrot2(var);
	}
}
