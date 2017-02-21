/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 19:09:57 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/14 15:52:58 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*put_apos(char *str, int i)
{
	char	*tmp;
	int		len;
	int		y;

	len = ft_strlen(str) + 1;
	tmp = ft_strnew(len);
	tmp[i] = ',';
	y = 0;
	i = 0;
	while (len-- > 0)
	{
		if (tmp[i])
			i++;
		else
			tmp[i++] = str[y++];
	}
	free(str);
	return (tmp);
}

char			*add_apos(char *str, int len)
{
	int		i;
	char	*tmp;

	tmp = ft_strdup(str);
	free(str);
	if (len >= 4)
	{
		i = 1;
		while (len > 1)
		{
			if (len % 3 == 1)
				tmp = put_apos(tmp, i++);
			i++;
			len--;
		}
	}
	return (tmp);
}

void			convert_d(va_list ap, t_boxpf *boxpf)
{
	t_long			d;
	char			*str;

	str = NULL;
	if (TYPE == 'D')
		d = (t_long)va_arg(ap, long int);
	else
		d = get_arg(boxpf, ap);
	if (boxpf->pres != 0 || d)
		str = (d >= 0) ? ft_itoa_base(d, "0123456789") :
			ft_itoa_base(-d, "0123456789");
	if (str && CHR(FLAG, '\''))
		STR = add_apos(str, ft_strlen(str));
	else
		STR = str;
	boxpf->sign = (d < 0) ? 1 : 0;
}
