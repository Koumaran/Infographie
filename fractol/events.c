/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 19:18:12 by jsivanes          #+#    #+#             */
/*   Updated: 2017/01/08 21:45:10 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		add_helper(void)
{
	ft_printf("\nFRACTOL:\n\nMove Option:\n\tup :\tup arrow\n\tdown :\t");
	ft_printf("down arrow\n\tleft :\tleft arrow\n\tright :\tright arrow\n\n");
	ft_printf("Zoom Option:\n\tin :\t+\n\tout :\t-\n\n");
	ft_printf("Size Option:\n\tincrease :\t2\n\tdecrease :\t1\n");
}

static void		exit_fractol(t_var *var)
{
	mlx_destroy_window(MLX, WIN);
	ft_strdel(&FRACTOL);
	exit(EXIT_SUCCESS);
}

int				ft_keyhook(int keycode, t_var *var)
{
	dprintf(1, "Keycode=%d\n", keycode);
	if (keycode == ESC)
		exit_fractol(var);
	if (keycode == HELP)
		add_helper();
	if (keycode == SPACE)
		PLAY = (PLAY) ? 0 : 1;
	return (0);
}
