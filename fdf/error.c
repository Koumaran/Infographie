/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 21:56:05 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/05 20:53:06 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_error(int out, char *file)
{
	if (out == 0)
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
	else if (out == 1)
	{
		ft_putstr("No file ");
		ft_putendl(file);
	}
	else if (out == 2)
		ft_putstr("Foudn wrong line length. Exiting.\n");
	else if (out == 3)
		ft_putstr("Error malloc\n");
	else if (out == 4)
		ft_putstr("Wrong file\n");
	exit(0);
}
