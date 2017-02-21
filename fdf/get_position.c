/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 21:38:20 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/05 21:03:28 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_point(t_mlx *mlx, t_point *p, int pos)
{
	p->z = mlx->map[pos].z * mlx->higth;
	p->x = (CTEX * mlx->map[pos].x - CTEY * mlx->map[pos].y) * mlx->zoom
		+ (WIN_SIZEX / 2) + mlx->moveh;
	p->y = (-p->z + (CTEX / 2) * mlx->map[pos].x +
				(CTEY / 2) * mlx->map[pos].y) *
		mlx->zoom + (WIN_SIZEY / 2) - mlx->movev;
	if (mlx->map[pos].color == 0)
	{
		if (p->z < 0)
			p->color = 153;
		if (p->z >= 0 && p->z < 6)
			p->color = 3381504;
		if (p->z >= 6 && p->z < 20)
			p->color = 6697728;
		if (p->z >= 20)
			p->color = 16777215;
	}
	else
		p->color = mlx->map[pos].color;
}
