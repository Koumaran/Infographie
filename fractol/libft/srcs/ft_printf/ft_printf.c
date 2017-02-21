/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 17:34:21 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/28 18:34:39 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		printf_print(t_string *string)
{
	if (string->content)
	{
		write(1, string->content, string->size);
		free(string->content);
	}
	return (string->size);
}

int				ft_printf(const char *restrict fmt, ...)
{
	va_list		ap;
	t_string	string;

	if (!fmt || !*fmt)
		return (0);
	va_start(ap, fmt);
	ft_stringinit(&string);
	while (*fmt)
	{
		if ((*fmt == '%' || *fmt == '{') && *(fmt + 1))
			fmt += parse(ap, (char*)fmt, &string);
		else if (*fmt != '%' && *fmt)
			ft_stringaddc(&string, *fmt);
		fmt++;
	}
	va_end(ap);
	return (printf_print(&string));
}
