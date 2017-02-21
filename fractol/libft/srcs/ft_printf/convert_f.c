/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 21:41:09 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/14 16:03:49 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*before_cama(double nbr, int pres, char *flag)
{
	int		tmp;
	int		len;
	char	*str;
	int		i;

	if (nbr != nbr)
		return (ft_strdup("nan"));
	i = 0;
	len = pres + 2;
	while ((nbr /= 10) > 1)
		len++;
	str = ft_strnew(len);
	while (i < len - pres - 1)
	{
		nbr *= 10;
		tmp = (int)nbr;
		str[i++] = '0' + tmp;
		nbr -= tmp;
	}
	if (str && CHR(flag, '\''))
		return (add_apos(str, ft_strlen(str)));
	return (str);
}

void	fix_precision(char *str)
{
	int		i;

	i = ft_strlen(str);
	while (str[--i] == '9')
		str[i] = '0';
	str[i]++;
}

void	after_cama(char *str, double f, int pres)
{
	int				i;
	int				tmp;
	int				y;

	if (pres == 0 || f != f)
		return ;
	i = ft_strlen(str);
	str[i++] = '.';
	f -= (t_long)f;
	y = -1;
	while (++y < pres)
	{
		f *= 10;
		if ((y + 1) >= pres)
			f += 0.5;
		tmp = (int)f;
		if (tmp >= 10)
		{
			tmp = tmp % 10;
			fix_precision(str);
		}
		str[i++] = tmp + '0';
		f -= tmp;
	}
}

void	convert_f(va_list ap, t_boxpf *boxpf)
{
	long double		f;
	char			*str;

	f = get_float_arg(boxpf, ap);
	if (f < 0)
	{
		boxpf->sign = 1;
		f *= -1;
	}
	str = before_cama(f, ((PRES == -1) ? 6 : PRES), FLAG);
	after_cama(str, f, ((PRES == -1) ? 6 : PRES));
	if (TYPE == 'F')
		ft_strupper(str);
	STR = ft_strdup(str);
	free(str);
}
