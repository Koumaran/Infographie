/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 14:17:03 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/13 16:35:06 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <sys/types.h>
#include <inttypes.h>
#include <stddef.h>

t_long			get_arg(t_boxpf *boxpf, va_list ap)
{
	if (ft_strequ(boxpf->length, "hh"))
		return ((t_long)(signed char)(va_arg(ap, int)));
	if (ft_strequ(boxpf->length, "h"))
		return ((t_long)(short)(va_arg(ap, int)));
	if (ft_strequ(boxpf->length, "ll"))
		return ((t_long)(va_arg(ap, long long)));
	if (ft_strequ(boxpf->length, "l"))
		return ((t_long)(va_arg(ap, long)));
	if (ft_strequ(boxpf->length, "j"))
		return ((t_long)(va_arg(ap, intmax_t)));
	if (ft_strequ(boxpf->length, "t") || ft_strequ(boxpf->length, "I"))
		return ((t_long)(va_arg(ap, ptrdiff_t)));
	if (ft_strequ(boxpf->length, "z"))
		return ((t_long)(va_arg(ap, long)));
	if (ft_strequ(boxpf->length, "q") || ft_strequ(boxpf->length, "I64"))
		return ((t_long)(va_arg(ap, quad_t)));
	return ((t_long)(va_arg(ap, int)));
}

t_ulong			get_unsigned_arg(t_boxpf *boxpf, va_list ap)
{
	if (ft_strequ(boxpf->length, "hh"))
		return ((t_ulong)(unsigned char)(va_arg(ap, int)));
	if (ft_strequ(boxpf->length, "h"))
		return ((t_ulong)(unsigned short)(va_arg(ap, int)));
	if (ft_strequ(boxpf->length, "ll"))
		return ((t_ulong)(va_arg(ap, unsigned long long)));
	if (ft_strequ(boxpf->length, "l"))
		return ((t_ulong)(va_arg(ap, unsigned long)));
	if (ft_strequ(boxpf->length, "j"))
		return ((t_ulong)(va_arg(ap, uintmax_t)));
	if (ft_strequ(boxpf->length, "t"))
		return ((t_ulong)(va_arg(ap, ptrdiff_t)));
	if (ft_strequ(boxpf->length, "z") || ft_strequ(boxpf->length, "I"))
		return ((t_ulong)(va_arg(ap, size_t)));
	if (ft_strequ(boxpf->length, "q") || ft_strequ(boxpf->length, "I64"))
		return ((t_ulong)(va_arg(ap, u_quad_t)));
	return ((t_ulong)(va_arg(ap, unsigned int)));
}

long double		get_float_arg(t_boxpf *boxpf, va_list ap)
{
	if (ft_strequ(boxpf->length, "L"))
		return (va_arg(ap, long double));
	if (ft_strequ(boxpf->length, "l"))
		return ((long double)(va_arg(ap, double)));
	return ((long double)(va_arg(ap, double)));
}
