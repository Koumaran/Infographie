/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 20:44:18 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/14 16:04:14 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		write_e(char *str, int e)
{
	int		i;
	int		y;
	char	*tmp;

	i = ft_strlen(str);
	str[i++] = 'e';
	str[i++] = (e >= 0) ? '+' : '-';
	e = (e < 0) ? -e : e;
	if (e < 10 && e >= 0)
	{
		str[i++] = '0';
		str[i] = '0' + e;
		return ;
	}
	y = 0;
	tmp = ft_itoa(e);
	while (e)
	{
		str[i++] = tmp[y++];
		e /= 10;
	}
	free(tmp);
}

static char		*pre_convert_e(t_boxpf *boxpf, long double nb, int e)
{
	char	*str;

	if (nb != nb)
		return (ft_strdup("nan"));
	if (nb < 0)
	{
		boxpf->sign = 1;
		nb *= -1;
	}
	while ((int)nb > 9)
	{
		e++;
		nb /= 10;
	}
	while ((int)nb <= 0)
	{
		e--;
		nb *= 10;
	}
	str = before_cama(nb, ((PRES == -1) ? 6 : PRES), FLAG);
	after_cama(str, nb, ((PRES == -1) ? 6 : PRES));
	write_e(str, e);
	return (str);
}

void			convert_e(va_list ap, t_boxpf *boxpf)
{
	long double		nb;
	char			*str;

	nb = va_arg(ap, double);
	str = pre_convert_e(boxpf, nb, 0);
	if (TYPE == 'E')
		ft_strupper(str);
	STR = ft_strdup(str);
	free(str);
}
