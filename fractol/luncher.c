/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:34:57 by jsivanes          #+#    #+#             */
/*   Updated: 2017/03/14 18:56:12 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_pixel(t_var *var, int color)
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

void		ft_reset_fract(t_var *var)
{
	ZOOM = 0;
	POS_X = 0;
	POS_Y = 0;
	NX = 0;
	NY = 0;
	IM = 0;
	V = 0;
}

char		*get_color_name(int color)
{
	if (color == RED)
		return ("RED");
	if (color == GREEN)
		return ("GREEN");
	if (color == BLUE)
		return ("BLUE");
	if (color == YELLOW)
		return ("YELLOW");
	if (color == PURPLE)
		return ("PURPLE");
	if (color == SKY)
		return ("SKY");
	return (NULL);
}

void		exit_fractol(t_var *var)
{
	mlx_destroy_window(MLX, WIN);
	ft_strdel(&FRACTOL);
	free(var);
	exit(EXIT_SUCCESS);
}

int			lunch_fractol(t_var *var)
{
	TRIANGLE = !ft_strcmp(FRACTOL, "sierpinski2") ? 1 : 0;
	if (!ft_strcmp(FRACTOL, "mandelbrot"))
		ft_mandelbrot(var);
	else if (!ft_strcmp(FRACTOL, "julia") || !ft_strcmp(FRACTOL, "rabit julia"))
		ft_julia(var);
	else if (!ft_strcmp(FRACTOL, "buddhabrot"))
		ft_buddhabrot(var);
	else if (!ft_strcmp(FRACTOL, "burningship"))
		ft_burningship(var);
	else if (!ft_strcmp(FRACTOL, "sierpinski") || \
			!ft_strcmp(FRACTOL, "sierpinski2"))
		ft_sierpinski(var);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	init_window(var);
	return (0);
}
