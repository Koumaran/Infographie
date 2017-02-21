/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 09:19:18 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/05 20:20:28 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		add_color(char *str, t_point *map)
{
	char	*hexa;

	if (ft_strchr(str, ','))
	{
		hexa = ft_strsub(str, ft_strchri(str, ',') + 1, ft_strlen(str));
		if (*hexa != '0' || *(hexa + 1) != 'x')
		{
			ft_strdel(&hexa);
			get_error(4, NULL);
		}
		map->color = ft_atoi_base(hexa, "0123456789ABCDEF");
		ft_strdel(&hexa);
	}
	else
	{
		map->color = 0;
		if (*str != '-' && (*str < '0' || *str > '9'))
			get_error(4, NULL);
		while (*(++str))
			if (*str < '0' || *str > '9')
				get_error(4, NULL);
	}
}

static void		split_in_point(t_mlx *mlx, char **str, int len)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	x = 0;
	y = 0;
	if ((mlx->map = (t_point*)ft_memalloc(sizeof(t_point) * len)) == NULL)
		get_error(3, NULL);
	while (++i < len)
	{
		mlx->map[i].z = ft_getnbr(str[i]);
		mlx->map[i].x = x++;
		mlx->map[i].y = y;
		add_color(str[i], &mlx->map[i]);
		if ((i + 1) % mlx->size_x == 0)
		{
			y++;
			x = 0;
		}
		ft_strdel(&str[i]);
	}
}

void			get_file(t_mlx *mlx, const int fd)
{
	char		*line;
	char		*str;

	str = NULL;
	while (get_next_line(fd, &line))
	{
		mlx->size_y++;
		mlx->size_x = (mlx->size_x == 0) ?
			ft_nb_of_word(line, ' ') : mlx->size_x;
		if (mlx->size_x > (int)ft_strlen(line))
			get_error(2, NULL);
		str = ft_strjoin_safe(str, line);
		str = ft_putchar_str(str, ' ');
	}
	if (mlx->size_x == 0)
		get_error(4, NULL);
	split_in_point(mlx, ft_strsplit(str, ' '), mlx->size_x * mlx->size_y);
	ft_strdel(&str);
}
