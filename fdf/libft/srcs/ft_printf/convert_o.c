/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 11:21:23 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/07 23:22:32 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_o(va_list ap, t_boxpf *boxpf)
{
	t_ulong		o;

	o = (TYPE == 'O') ? (t_ulong)va_arg(ap, unsigned long int) :
		get_unsigned_arg(boxpf, ap);
	if (boxpf->pres != 0 || o)
		STR = ft_itoa_base(o, "01234567");
	if (ft_strchr(FLAG, '#') && (o > 0 ||
				boxpf->pres == 0))
		STR = ft_strjoin_safe(ft_strdup("0\0"), STR);
}
