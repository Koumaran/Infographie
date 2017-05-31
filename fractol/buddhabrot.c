/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:16:17 by jsivanes          #+#    #+#             */
/*   Updated: 2017/03/14 18:16:56 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_buddhabrot2(t_var *var)
{
	CI = (X + (ZOOM ? ZOOM : 1) - NX) / ZOOM_X + X1;
	CR = (Y + (ZOOM ? ZOOM : 1) - NY) / ZOOM_Y + Y1;
	ZR = 0;
	ZI = 0;
	I = -1;
	while ((ZR * ZR + ZI * ZI < 4) && ++I < I_MAX)
	{
		TMP_D = ZR;
		ZR = ZR * ZR - ZI * ZI + CR;
		ZI = 2 * ZI * TMP_D + CI;
	}
	if (I != I_MAX)
		put_pixel(var, BLACK);
	else
		put_pixel(var, M_COLOR ? (I * COLOR / I_MAX) : I * COLOR);
}

void			ft_buddhabrot(t_var *var)
{
	X1 = -2.1 + POS_X;
	X2 = 0.6 + POS_X;
	Y1 = -1.2 + POS_Y;
	Y2 = 1.2 + POS_Y;
	I_MAX = IM + 100;
	ZOOM_X = (WIDTH_WIN / (X2 - X1) + (ZOOM ? ZOOM : 1));
	ZOOM_Y = (HEIGHT_WIN / (Y2 - Y1) + (ZOOM ? ZOOM : 1));
	X = -1;
	while (++X < WIDTH_WIN)
	{
		Y = -1;
		while (++Y < HEIGHT_WIN)
			ft_buddhabrot2(var);
	}
}
