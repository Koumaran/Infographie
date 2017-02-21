/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 11:47:10 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/13 16:47:18 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		convert_ls(wchar_t *s, t_boxpf *boxpf)
{
	char		*str;
	int			len;

	if (!s)
		s = L"(null)";
	len = ft_wstrlen(s);
	str = ft_strnew(len);
	ft_wstrnconv(str, s, ((PRES >= 0 && len > PRES) ? PRES : len));
	STR = ft_strdup(str);
	ft_strdel(&str);
}

void			convert_s(va_list ap, t_boxpf *boxpf)
{
	char	*s;

	if (TYPE == 'S' || ft_strequ(boxpf->length, "l"))
		convert_ls(va_arg(ap, wchar_t*), boxpf);
	else
	{
		s = va_arg(ap, char*);
		if (!s)
			s = "(null)";
		STR = (boxpf->pres >= 0 && boxpf->pres < (int)ft_strlen(s)) ?
			ft_strsub(s, 0, boxpf->pres) : ft_strdup(s);
	}
}
