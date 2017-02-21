/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 18:37:16 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/28 18:34:36 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_b(va_list ap, t_boxpf *boxpf)
{
	t_ulong		b;

	b = get_unsigned_arg(boxpf, ap);
	if (PRES != 0 || b)
		STR = ft_itoa_base(b, "01");
	if (CHR(FLAG, '#') && (b > 0 || PRES == 0))
		STR = JN(DP("0"), STR);
}
