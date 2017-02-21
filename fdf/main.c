/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:08:32 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/15 20:27:47 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		expose_hook(t_mlx *mlx)
{
	create_image(mlx);
	return (0);
}

static t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)ft_memalloc(sizeof(t_mlx));
	ft_bzero(mlx, sizeof(mlx));
	mlx->zoom = 10;
	mlx->higth = 1;
	return (mlx);
}

int				main(int ac, char **av)
{
	t_mlx	*mlx;
	int		fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			get_error(1, av[1]);
		mlx = init_mlx();
		get_file(mlx, fd);
		close(fd);
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, WIN_SIZEX, WIN_SIZEY, av[1]);
		mlx_loop_hook(mlx->mlx, expose_hook, mlx);
		mlx_hook(mlx->win, 2, 3, ft_keyhook, mlx);
		mlx_loop(mlx->mlx);
	}
	else
		get_error(0, av[1]);
	return (0);
}
