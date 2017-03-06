/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 13:40:11 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/31 19:40:53 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char		*check_fractol(char *str)
{
	if (!ft_strcmp(str, "Mandelbrot") || !ft_strcmp(str, "mandelbrot"))
		return (ft_strdup("mandelbrot"));
	else if (!ft_strcmp(str, "Julia") || !ft_strcmp(str, "julia"))
		return (ft_strdup("julia"));
	else
		ft_printf("%s: Wrong fractol\n", str);
	return (NULL);
}

void		init_var(t_var *var, char *str)
{
	if (!(FRACTOL = check_fractol(str)))
		return (exit(EXIT_FAILURE));
	WIDTH_WIN = 500;
	HEIGHT_WIN = 300;
	ZOOM = 100;
	var->color_tab = create_color();
	COLOR = WHITE;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH_WIN, HEIGHT_WIN, FRACTOL);
	IMG = mlx_new_image(MLX, WIDTH_WIN, HEIGHT_WIN);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
}

void		fractol(char *str)
{
	t_var		var;

	ft_bzero(&var, sizeof(t_var));
	init_var(&var, str);
	mlx_loop_hook(var.mlx, lunch_fractol, &var);
	mlx_hook(var.win, KeyPress, KeyPressMask, ft_keyhook, &var);
	mlx_loop(var.mlx);
}

int			main(int ac, char **av)
{
	int		i;

	if (ac < 2)
		ft_printf("Usage: ./fractol [Mandelbrot]\n");
	else
	{
		i = 0;
		while (++i < ac)
			fractol(av[i]);
	}
	return (0);
}
