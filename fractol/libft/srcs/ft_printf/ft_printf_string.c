/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:23:37 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/15 19:29:51 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		printf_print(t_string *string, t_string *string_p)
{
	if (string_p->content)
	{
		ft_stringadd(string, string_p->content, string_p->size);
		free(string_p->content);
	}
	return (string_p->size);
}

int				ft_printf_string(t_string *string,\
				const char *restrict fmt, ...)
{
	va_list		ap;
	t_string	string_p;

	if (!fmt || !*fmt)
		return (0);
	va_start(ap, fmt);
	ft_stringinit(&string_p);
	while (*fmt)
	{
		if ((*fmt == '%' || *fmt == '{') && *(fmt + 1))
			fmt += parse(ap, (char*)fmt, &string_p);
		else if (*fmt != '%' && *fmt)
			ft_stringaddc(&string_p, *fmt);
		fmt++;
	}
	va_end(ap);
	return (printf_print(string, &string_p));
}
