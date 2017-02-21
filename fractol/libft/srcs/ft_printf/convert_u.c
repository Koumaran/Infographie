/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 12:32:15 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/14 16:00:25 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_u(va_list ap, t_boxpf *boxpf)
{
	t_ulong		u;
	char		*decimal;

	u = (TYPE == 'U') ? (t_ulong)va_arg(ap, unsigned long int) :
		get_unsigned_arg(boxpf, ap);
	if (boxpf->pres != 0 || u)
	{
		decimal = ft_itoa_base(u, "0123456789");
		if (decimal && CHR(FLAG, '\''))
			STR = add_apos(decimal, ft_strlen(decimal));
		else
			STR = decimal;
	}
}
