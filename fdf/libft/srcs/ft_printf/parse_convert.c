/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 19:26:42 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/14 15:53:14 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		parse_width(t_boxpf *boxpf, char *str, int y, va_list ap)
{
	y--;
	boxpf->width = 0;
	while (!CHR("*123456789", str[y]) && y > -1)
		y--;
	if (y >= 0)
	{
		if (ft_isdigit(str[y]))
		{
			while (ft_isdigit(str[y]) && y > 0)
				y--;
			y += (!ft_isdigit(str[y])) ? 1 : 0;
		}
		if (y > 0 && str[y - 1] == '.')
			return (parse_width(boxpf, str, y, ap));
		if (str[y] == '*')
			boxpf->width = (int)va_arg(ap, int);
		else
		{
			boxpf->width = ft_atoi(str + y);
			while (str[y] != '*' && y >= 0)
				y--;
			if ((y > 0 && str[y] != '.') || (y == 0 && str[y] == '*'))
				va_arg(ap, int);
		}
	}
}

static void		parse_presicion(t_boxpf *boxpf, char *str, va_list ap)
{
	int		i;
	char	*tmp;

	if (!CHR(str, '.'))
	{
		boxpf->pres = -1;
		return ;
	}
	tmp = CHR(str, '.');
	i = 1;
	if (tmp[i] == '*')
		boxpf->pres = (int)va_arg(ap, int);
	else if (ft_isdigit(tmp[i]))
		boxpf->pres = ft_atoi(tmp + i);
	else
		boxpf->pres = 0;
}

static char		*parse_length(char *str)
{
	char	*tmp;

	if ((CHR(str, 'j')))
		return ("j");
	if ((CHR(str, 'z')))
		return ("z");
	if ((CHR(str, 't')))
		return ("t");
	if ((CHR(str, 'q')))
		return ("q");
	if ((tmp = CHR(str, 'I')))
		return (*(tmp + 1) == '6' && *(tmp + 2) == '4' ? "I64" : "I");
	if ((CHR(str, 'L')))
		return ("L");
	if ((tmp = CHR(str, 'l')))
		return ((*(tmp + 1) == 'l') ? "ll" : "l");
	if ((tmp = CHR(str, 'h')))
		return ((*(tmp + 1) == 'h') ? "hh" : "h");
	return (NULL);
}

static void		parse_flag(t_boxpf *boxpf, char *str, int y, va_list ap)
{
	int		i;

	i = -1;
	FLAG = NULL;
	while (++i < y)
	{
		if (CHR("0", str[i]) &&
				(i == 0 || (!ft_isdigit(str[i - 1]) && str[i - 1] != '.')))
			FLAG = ft_putchar_str(FLAG, str[i]);
		else if (CHR("#+- \'", str[i]))
			FLAG = ft_putchar_str(FLAG, str[i]);
	}
	parse_width(boxpf, str, y, ap);
	parse_presicion(boxpf, str, ap);
	boxpf->length = parse_length(str);
}

int				parse_convert(va_list ap, char *fmt, t_boxpf *boxpf)
{
	int			i;
	int			y;
	char		*str;

	i = 0;
	y = 0;
	while (ft_strchr(ALL, fmt[i]) != NULL && fmt[i])
		i++;
	if (ft_strchr(ALL, fmt[i - ((i > 0) ? 1 : 0)]) != NULL)
	{
		while (!CHR(CONVERT, fmt[y]) && y < i)
			y++;
		str = ft_strsub(fmt, 0, y + 1);
		TYPE = (ft_strchr(CONVERT, str[y]) != NULL) ? str[y] : FALSE;
		parse_flag(boxpf, str, y, ap);
		ft_strdel(&str);
		if (TYPE == 'n')
			return (y);
		get_fonction(boxpf, ap);
		add_flag(boxpf, fmt[i]);
	}
	return (y - ((!TYPE) ? 1 : 0));
}
