/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 13:40:11 by jsivanes          #+#    #+#             */
/*   Updated: 2017/03/14 18:51:25 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char		*check_fractol(char *str)
{
	if (!ft_strcmp(str, "Mandelbrot") || !ft_strcmp(str, "mandelbrot"))
		return (ft_strdup("mandelbrot"));
	if (!ft_strcmp(str, "Julia") || !ft_strcmp(str, "julia"))
		return (ft_strdup("julia"));
	if (!ft_strcmp(str, "Buddhabrot") || !ft_strcmp(str, "buddhabrot"))
		return (ft_strdup("buddhabrot"));
	if (!ft_strcmp(str, "Burningship") || !ft_strcmp(str, "burningship"))
		return (ft_strdup("burningship"));
	if (!ft_strcmp(str, "Sierpinski") || !ft_strcmp(str, "sierpinski"))
		return (ft_strdup("sierpinski"));
	ft_printf("%s: Wrong fractol\n", str);
	ft_printf("Usage: ./fractol [Mandelbrot | Julia | Buddhabrot | ");
	ft_printf("Burningship | Sierpinski]\n");
	return (NULL);
}

void		init_window(t_var *var)
{
	Y = HEIGHT_WIN;
	while (++Y < HEIGHT_WIN + 50)
	{
		X = -1;
		while (++X < WIDTH_WIN)
			mlx_pixel_put(MLX, WIN, X, Y, 0x0);
	}
	mlx_string_put(MLX, WIN, 0, HEIGHT_WIN + 10, 0xFFFFFF, "NAME:");
	mlx_string_put(MLX, WIN, 50, HEIGHT_WIN + 10, 0xFFFFFF, FRACTOL);
	mlx_string_put(MLX, WIN, 200, HEIGHT_WIN + 10, 0xFFFFFF, "COLOR:");
	mlx_string_put(MLX, WIN, 270, HEIGHT_WIN + 10, 0xFFFFFF, \
			get_color_name(COLOR));
	mlx_string_put(MLX, WIN, 400, HEIGHT_WIN + 10, 0xFFFFFF, "ZOOM:");
	mlx_string_put(MLX, WIN, 500, HEIGHT_WIN + 10, 0xFFFFFF, ft_itoa(ZOOM));
	mlx_string_put(MLX, WIN, 0, HEIGHT_WIN + 30, 0xFFFFFF, "M_COLOR:");
	mlx_string_put(MLX, WIN, 100, HEIGHT_WIN + 30, 0xFFFFFF, ft_itoa(M_COLOR));
	mlx_string_put(MLX, WIN, 200, HEIGHT_WIN + 30, 0xFFFFFF, "I_MAX:");
	mlx_string_put(MLX, WIN, 300, HEIGHT_WIN + 30, 0xFFFFFF, ft_itoa(I_MAX));
	mlx_string_put(MLX, WIN, 400, HEIGHT_WIN + 30, 0xFFFFFF, "PLAY:");
	mlx_string_put(MLX, WIN, 500, HEIGHT_WIN + 30, 0xFFFFFF, ft_itoa(PLAY));
}

void		init_var(t_var *var, char *str)
{
	if (!(FRACTOL = check_fractol(str)))
		return (exit(EXIT_FAILURE));
	WIDTH_WIN = 600;
	HEIGHT_WIN = 450;
	COLOR = RED;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH_WIN, HEIGHT_WIN + 50, "FRACTOL");
	IMG = mlx_new_image(MLX, WIDTH_WIN, HEIGHT_WIN);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	init_window(var);
}

void		fractol(char *str)
{
	t_var		*var;

	if (!(var = (t_var*)ft_memalloc(sizeof(t_var))))
		return (exit(EXIT_FAILURE));
	init_var(var, str);
	mlx_loop_hook(MLX, lunch_fractol, var);
	mlx_hook(WIN, KeyPress, KeyPressMask, ft_keyhook, var);
	mlx_hook(WIN, ButtonPress, ButtonPressMask, ft_mousehook, var);
	mlx_hook(WIN, MotionNotify, ButtonMotionMask, ft_motion_mousehook, var);
	mlx_loop(MLX);
}

int			main(int ac, char **av)
{
	int		i;

	if (ac > 1)
	{
		i = 0;
		while (++i < ac)
		{
			if (fork())
				fractol(av[i]);
		}
	}
	else
	{
		ft_printf("Usage: ./fractol [Mandelbrot | Julia | Buddhabrot | ");
		ft_printf("Burningship | Sierpinski]\n");
	}
	return (0);
}
