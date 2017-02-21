/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 11:26:36 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/27 11:13:13 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_p(va_list ap, t_boxpf *boxpf)
{
	char			*hex;
	t_ulong			add;
	int				len;

	add = (t_ulong)va_arg(ap, void*);
	if (boxpf->pres != 0 || add)
	{
		hex = ft_itoa_base(add, "0123456789abcdef");
		len = ft_strlen(hex);
		if (PRES > 0)
			while (boxpf->pres > len++)
				hex = JN(DP("0"), hex);
		else if (WIDTH && CHR(FLAG, '0') && !CHR(FLAG, '-'))
			while (WIDTH - 2 > len++)
				hex = JN(DP("0"), hex);
		STR = JN(DP("0x"), hex);
	}
	else
		STR = DP("0x");
}
