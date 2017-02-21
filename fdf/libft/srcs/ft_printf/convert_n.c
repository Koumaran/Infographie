/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 17:57:51 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/14 13:30:38 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_n(va_list ap, t_boxpf *boxpf, int size)
{
	t_long		*n;
	int			i;
	char		*s;

	if (ft_strequ(boxpf->length, "hh"))
	{
		s = (char*)va_arg(ap, char*);
		i = 0;
		while (i < size - 1)
			s[i++] = ' ';
		s[i] = '\0';
		return ;
	}
	if (ft_strequ(boxpf->length, "h"))
		n = (t_long*)va_arg(ap, short int*);
	else if (ft_strequ(boxpf->length, "l"))
		n = (t_long*)va_arg(ap, long int*);
	else if (ft_strequ(boxpf->length, "ll"))
		n = va_arg(ap, t_long*);
	else
		n = (t_long*)va_arg(ap, int*);
	*n = size;
}
