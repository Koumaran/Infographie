/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 12:13:30 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/24 18:54:12 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		convert_x(va_list ap, t_boxpf *boxpf)
{
	t_ulong		x;

	x = get_unsigned_arg(boxpf, ap);
	if (boxpf->pres != 0 || x)
		STR = (TYPE == 'x') ? ft_itoa_base(x, "0123456789abcdef") :
			ft_itoa_base(x, "0123456789ABCDEF");
	boxpf->sign = (x <= 0) ? 1 : 0;
}
