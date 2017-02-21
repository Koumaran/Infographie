/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_touch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 19:59:52 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/05 21:23:08 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		add_helper(void)
{
	ft_printf("\nFDF:\n\nMove Option:\n\tup :\tup arrow\n\tdown :\t");
	ft_printf("down arrow\n\tleft :\tleft arrow\n\tright :\tright arrow\n\n");
	ft_printf("Zoom Option:\n\tin :\t+\n\tout :\t-\n\n");
	ft_printf("Size Option:\n\tincrease :\t2\n\tdecrease :\t1\n");
}

static void		quitter(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx);
	exit(0);
}

int				ft_keyhook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		quitter(mlx);
	if (keycode == 4)
		add_helper();
	mlx->moveh = (keycode == 124) ? mlx->moveh + 10 : mlx->moveh;
	mlx->moveh = (keycode == 123) ? mlx->moveh - 10 : mlx->moveh;
	mlx->movev = (keycode == 125) ? mlx->movev - 10 : mlx->movev;
	mlx->movev = (keycode == 126) ? mlx->movev + 10 : mlx->movev;
	mlx->zoom = (keycode == 69) ? mlx->zoom + 1 : mlx->zoom;
	if (keycode == 78)
		mlx->zoom -= (mlx->zoom > 0) ? 1 : 0;
	mlx->higth = (keycode == 83) ? mlx->higth - 0.1 : mlx->higth;
	mlx->higth = (keycode == 84) ? mlx->higth + 0.1 : mlx->higth;
	return (0);
}
