/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 18:06:00 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/28 12:59:28 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/header/libft.h"
# include "libft/header/ft_printf.h"
# include "sources/minilibx_macos/mlx.h"

# define WIN_SIZEX 2048
# define WIN_SIZEY 1152
# define CTEX 0.6
# define CTEY 0.8

typedef	struct	s_point
{
	int			x;
	int			y;
	int			z;
	t_ulong		color;
}				t_point;

typedef struct	s_bresenham
{
	int			x;
	int			y;
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
	int			cumul;
}				t_bresenham;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			size_y;
	int			size_x;
	int			bpp;
	int			size_line;
	int			endian;
	char		*data;
	double		zoom;
	int			movev;
	int			moveh;
	double		higth;
	t_point		*map;
}				t_mlx;

void			fdf(t_mlx *mlx, int len);
void			create_image(t_mlx *mlx);
void			get_error(int out, char *file);
void			get_file(t_mlx *mlx, const int fd);
void			get_point(t_mlx *mlx, t_point *p, int pos);
int				ft_keyhook(int keycode, t_mlx *mlx);
void			pxl_putimg(t_mlx *mlx, int x, int y, int color);
void			bresenham(t_mlx *mlx, t_point *p1, t_point *p2);

#endif
