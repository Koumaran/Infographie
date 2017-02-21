/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:42:44 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/13 16:48:03 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*flag_0_neg2(t_boxpf *boxpf, int size, int len, char c)
{
	char	*tmp;

	tmp = ft_strnew(len);
	if (CHR("dDi", TYPE) == NULL || !TYPE)
		while (len--)
			tmp[len] = (CHR(FLAG, '0') && !CHR(FLAG, '-')) ? '0' : ' ';
	else
		while (len--)
			tmp[len] = (CHR(FLAG, '0') && !CHR(FLAG, '-') &&
					(PRES < 0 || PRES > size)) ? '0' : ' ';
	if (!TYPE && c)
	{
		TYPE = c;
		len = ft_strlen(tmp);
		tmp[len - (CHR(FLAG, '-') ? len : 1)] = c;
	}
	return (tmp);
}

void			flag_0_neg(t_boxpf *boxpf, int size, char c)
{
	char	*tmp;
	int		len;

	if ((WIDTH - RET) > size)
	{
		len = (WIDTH - RET) - size;
		if ((CHR(FLAG, '-') != NULL) && (boxpf->sign || CHR(FLAG, '+'))
				&& CHR("dDi", TYPE))
			len--;
		if (CHR(FLAG, ' ') && (!TYPE || (CHR("dDi", TYPE)))
				&& !boxpf->sign && !CHR(FLAG, '+') && *STR)
			len--;
		tmp = flag_0_neg2(boxpf, size, len, c);
		STR = JN((CHR(FLAG, '-')) ? STR : tmp, (CHR(FLAG, '-')) ? tmp : STR);
	}
}

void			precision(t_boxpf *boxpf)
{
	int		width;
	int		len;
	char	*tmp;

	width = boxpf->pres;
	len = ft_strlen(STR);
	if (TYPE == 's' || TYPE == 'S')
	{
		if (width < len)
		{
			tmp = ft_strsub(STR, 0, width);
			free(STR);
			STR = tmp;
		}
	}
	else if (TYPE && TYPE != '%')
		while (width > len && *STR)
		{
			tmp = ft_strdup((ft_strchr("dDioOuUxX", TYPE)) ? "0" : " ");
			STR = ft_strjoin_safe(tmp, STR);
			width--;
		}
}
