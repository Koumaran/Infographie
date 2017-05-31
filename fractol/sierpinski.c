/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:40:45 by jsivanes          #+#    #+#             */
/*   Updated: 2017/03/14 18:40:49 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_sierpinski2(t_var *var)
{
	int			square;

	square = TRIANGLE ? 2 : 3;
	ZI = fabsl(X + POS_X - NX);
	ZR = fabsl(Y + POS_Y - NY);
	I = -1;
	while (((int)ZI % square != 1 || (int)ZR % square != 1) && ++I < I_MAX)
	{
		ZI /= square;
		ZR /= square;
	}
	if (I != I_MAX)
		put_pixel(var, BLACK);
	else
		put_pixel(var, M_COLOR ? (I * COLOR / I_MAX) : I * COLOR);
}

void		ft_sierpinski(t_var *var)
{
	I_MAX = IM + 10;
	X = -1;
	while (++X < WIDTH_WIN)
	{
		Y = -1;
		while (++Y < HEIGHT_WIN)
			ft_sierpinski2(var);
	}
}
