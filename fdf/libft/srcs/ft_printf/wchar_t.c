/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:30:59 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/13 16:51:26 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_wstrlen(wchar_t *wstr)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (!wstr)
		return (0);
	while (wstr[i])
	{
		if ((int)wstr[i] < 128)
			ret += 1;
		else if ((int)wstr[i] < 2048)
			ret += 2;
		else if ((int)wstr[i] < 65535)
			ret += 3;
		else
			ret += 4;
		i++;
	}
	return (ret);
}

int			ft_wcharlen(wchar_t w)
{
	if ((int)w < 128)
		return (1);
	else if ((int)w < 2048)
		return (2);
	else if ((int)w < 65535)
		return (3);
	return (4);
}

int			ft_wstrnconv(char *b, wchar_t *wstr, int n)
{
	int		i;
	int		tmp;
	int		len;

	len = 0;
	i = -1;
	while (wstr[++i] && n)
	{
		if (len + ft_wcharlen(wstr[i]) > n)
			break ;
		tmp = unicode_to_utf8(b + len, wstr[i]);
		len += tmp;
	}
	return (len);
}

int			unicode_to_utf8(char *b, wchar_t w)
{
	if ((int)w < 128)
		*b = (char)(w);
	else if ((int)w < 2048)
	{
		*b = (char)((w >> 6) | 0xC0);
		*(b + 1) = (char)((w & 0x3F) | 0x80);
		return (2);
	}
	else if ((int)w < 65535)
	{
		*b = (char)(((w >> 12)) | 0xE0);
		*(b + 1) = (char)(((w >> 6) & 0x3F) | 0x80);
		*(b + 2) = (char)((w & 0x3F) | 0x80);
		return (3);
	}
	else
	{
		*b = (char)(((w >> 18)) | 0xF0);
		*(b + 1) = (char)(((w >> 12) & 0x3F) | 0x80);
		*(b + 2) = (char)(((w >> 6) & 0x3F) | 0x80);
		*(b + 3) = (char)((w & 0x3F) | 0x80);
		return (4);
	}
	return (((*b != '\0') ? 1 : 0));
}
