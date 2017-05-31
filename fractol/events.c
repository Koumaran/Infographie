/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 19:18:12 by jsivanes          #+#    #+#             */
/*   Updated: 2017/03/14 18:53:34 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_motion_mousehook(int x, int y, t_var *var)
{
	if (PLAY)
		V = ((double)x - WIDTH_WIN / 4) / 10000;
	y = 0;
	return (0);
}

int				ft_mousehook(int button, int x, int y, t_var *var)
{
	if ((button == 1 || button == 4) && \
			(x < WIDTH_WIN && x > 0 && y > 0 && y < HEIGHT_WIN))
	{
		ZOOM += ZOOM < 200 ? 50 : 100;
		NX += WIDTH_WIN / 2 - x;
		NY += HEIGHT_WIN / 2 - y;
	}
	if ((button == 2 || button == 5) && \
			(x < WIDTH_WIN && x > 0 && y < HEIGHT_WIN && y > 0))
	{
		if (ZOOM > 0)
			ZOOM -= ZOOM < 200 ? 50 : 100;
		NX += WIDTH_WIN / 2 - x;
		NY += HEIGHT_WIN / 2 - y;
	}
	return (0);
}

static void		ft_switchfrac(int keycode, t_var *var)
{
	keycode == ALPHA1 ? FRACTOL = ft_str_replace(FRACTOL, "mandelbrot") : 0;
	keycode == ALPHA2 ? FRACTOL = ft_str_replace(FRACTOL, "julia") : 0;
	keycode == ALPHA3 ? FRACTOL = ft_str_replace(FRACTOL, "buddhabrot") : 0;
	keycode == ALPHA4 ? FRACTOL = ft_str_replace(FRACTOL, "burningship") : 0;
	keycode == ALPHA5 ? FRACTOL = ft_str_replace(FRACTOL, "sierpinski") : 0;
	keycode == ALPHA6 ? FRACTOL = ft_str_replace(FRACTOL, "sierpinski2") : 0;
	keycode == ALPHA7 ? FRACTOL = ft_str_replace(FRACTOL, "rabit julia") : 0;
}

static void		ft_key_move(int keycode, t_var *var)
{
	if (keycode == LEFT)
		POS_X -= ZOOM < 300 ? 0.1 : 0.01;
	if (keycode == RIGTH)
		POS_X += ZOOM < 300 ? 0.1 : 0.01;
	if (keycode == UP)
		POS_Y -= ZOOM < 300 ? 0.1 : 0.01;
	if (keycode == DOWN)
		POS_Y += ZOOM < 300 ? 0.1 : 0.01;
	if (keycode == PADPLUS)
		ZOOM += ZOOM < 200 ? 50 : 100;
	if (keycode == PADLESS)
		ZOOM -= ZOOM > -100 ? 50 : 0;
}

int				ft_keyhook(int keycode, t_var *var)
{
	if (keycode == ESC)
		exit_fractol(var);
	ft_key_move(keycode, var);
	ft_switchfrac(keycode, var);
	if (keycode == TOUCH_M)
		M_COLOR = M_COLOR ? 0 : 1;
	if (keycode == SPACE)
		PLAY = PLAY ? 0 : 1;
	keycode == PAD_1 ? COLOR = RED : COLOR;
	keycode == PAD_2 ? COLOR = GREEN : COLOR;
	keycode == PAD_3 ? COLOR = BLUE : COLOR;
	keycode == PAD_4 ? COLOR = YELLOW : COLOR;
	keycode == PAD_5 ? COLOR = PURPLE : COLOR;
	keycode == PAD_6 ? COLOR = SKY : COLOR;
	keycode == ALPHA_ && I_MAX > 1 ? --IM : 0;
	keycode == ALPHAEGAL ? ++IM : 0;
	keycode == TOUCH_DEL ? ft_reset_fract(var) : 0;
	return (0);
}
