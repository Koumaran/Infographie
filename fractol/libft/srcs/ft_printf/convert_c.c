/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 10:57:53 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/30 14:23:09 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_c(va_list ap, t_boxpf *boxpf)
{
	char			*a;
	wchar_t			x;
	unsigned char	c;

	if (TYPE == 'C' || ft_strequ(boxpf->length, "l"))
	{
		x = va_arg(ap, wint_t);
		a = ft_strnew(4);
		unicode_to_utf8(a, x);
		if (x == 0)
			RET = 1;
		STR = ft_strdup((char*)a);
		free(a);
	}
	else
	{
		c = (unsigned char)va_arg(ap, int);
		if (c == 0)
			RET = 1;
		STR = ft_putchar_str(STR, (char)c);
	}
}
