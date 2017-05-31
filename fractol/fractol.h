/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 13:40:33 by jsivanes          #+#    #+#             */
/*   Updated: 2017/03/14 18:26:07 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include "keycode.h"
# include <math.h>
# include <pthread.h>
# include <OpenCL/opencl.h>

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define PURPLE 0xFF00FF
# define SKY 0x00FFFF

# define MLX var->mlx
# define WIN var->win
# define IMG var->img
# define DATA var->data
# define BPP var->bpp
# define SIZELINE var->sizeline
# define ENDIAN var->endian
# define WIDTH_WIN var->width_win
# define HEIGHT_WIN var->height_win
# define FRACTOL var->fractol
# define I_MAX var->iteration_max
# define I var->i
# define X var->x
# define X1 var->x1
# define X2 var->x2
# define Y var->y
# define Y1 var->y1
# define Y2 var->y2
# define ZOOM var->zoom
# define CR var->cr
# define CI var->ci
# define ZR var->zr
# define ZI var->zi
# define COLOR var->color
# define ZOOM_X var->zoom_x
# define ZOOM_Y var->zoom_y
# define M_COLOR var->m_color
# define TMP_D var->tmp_d
# define V var->v
# define POS_X var->pos_x
# define POS_Y var->pos_y
# define PLAY var->play
# define IM var->im
# define NX var->nx
# define NY var->ny
# define TRIANGLE var->triangle

typedef struct		s_var
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	int				width_win;
	int				height_win;
	char			*fractol;
	int				iteration_max;
	int				im;
	int				i;
	int				x;
	double			pos_x;
	double			x1;
	double			x2;
	int				y;
	double			pos_y;
	double			y1;
	double			y2;
	double			tmp_d;
	double			zoom;
	double			cr;
	double			ci;
	double			zr;
	double			zi;
	double			zoom_x;
	double			zoom_y;
	double			nx;
	double			ny;
	double			v;
	int				m_color;
	int				color;
	int				play;
	int				triangle;
}					t_var;

char				*get_color_name(int color);
int					lunch_fractol(t_var *var);
void				ft_mandelbrot(t_var *var);
void				ft_julia(t_var *var);
void				ft_buddhabrot(t_var *var);
void				ft_burningship(t_var *var);
void				ft_sierpinski(t_var *var);
void				put_pixel(t_var *var, int color);
int					ft_keyhook(int keycode, t_var *var);
int					ft_mousehook(int button, int x, int y, t_var *var);
int					ft_motion_mousehook(int x, int y, t_var *var);
void				ft_reset_fract(t_var *var);
void				init_window(t_var *var);
void				exit_fractol(t_var *var);
#endif
