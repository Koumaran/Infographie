/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 19:26:51 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/14 14:21:44 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_ft(t_ft *ft_ptr)
{
	ft_ptr[0].name = DP("cC");
	ft_ptr[0].ft = convert_c;
	ft_ptr[1].name = DP("dDi");
	ft_ptr[1].ft = convert_d;
	ft_ptr[2].name = DP("sS");
	ft_ptr[2].ft = convert_s;
	ft_ptr[3].name = DP("eE");
	ft_ptr[3].ft = convert_e;
	ft_ptr[4].name = DP("p");
	ft_ptr[4].ft = convert_p;
	ft_ptr[5].name = DP("oO");
	ft_ptr[5].ft = convert_o;
	ft_ptr[6].name = DP("uU");
	ft_ptr[6].ft = convert_u;
	ft_ptr[7].name = DP("xX");
	ft_ptr[7].ft = convert_x;
	ft_ptr[8].name = DP("%");
	ft_ptr[8].ft = convert_percent;
	ft_ptr[9].name = DP("fF");
	ft_ptr[9].ft = convert_f;
	ft_ptr[10].name = DP("b");
	ft_ptr[10].ft = convert_b;
}

void			get_fonction(t_boxpf *boxpf, va_list ap)
{
	t_ft	*ft_ptr;
	int		i;

	ft_ptr = (t_ft*)ft_memalloc(sizeof(t_ft) * NB_FLAG);
	if (TYPE)
	{
		init_ft(ft_ptr);
		i = 0;
		while (i < NB_FLAG && CHR(ft_ptr[i].name, TYPE) == NULL)
			i++;
		if (i < NB_FLAG)
			ft_ptr[i].ft(ap, boxpf);
		else
		{
			STR = ft_strnew(1);
			STR[0] = TYPE;
		}
	}
	i = -1;
	while (++i < NB_FLAG)
		if (ft_ptr[i].name)
			ft_strdel(&ft_ptr[i].name);
	free(ft_ptr);
}

static void		clear_boxpf(t_boxpf *boxpf)
{
	if (STR)
		free(STR);
	if (FLAG)
		free(FLAG);
	ft_bzero(boxpf, sizeof(t_boxpf));
}

static void		str_string(char *str, int i, t_string *string, t_boxpf *boxpf)
{
	if (RET && CHR(FLAG, '-'))
	{
		str = JN(DP(" "), str);
		str[0] = '\0';
	}
	ft_stringadd(string, str, i);
	free(str);
}

int				parse(va_list ap, char *fmt, t_string *string)
{
	t_boxpf		boxpf;
	int			y;

	y = 0;
	ft_bzero(&boxpf, sizeof(t_boxpf));
	if (*fmt == '%')
		y = parse_convert(ap, ++fmt, &boxpf);
	else if (*fmt == '{')
	{
		y = parse_color(fmt, &boxpf);
		if (!boxpf.str)
			ft_stringaddc(string, '{');
	}
	if (boxpf.type == 'n')
		convert_n(ap, &boxpf, string->size);
	if (boxpf.str)
		str_string(ft_strdup(boxpf.str), ft_strlen(boxpf.str) + boxpf.ret,
				string, &boxpf);
	else if (boxpf.ret)
		ft_stringaddc(string, 0);
	clear_boxpf(&boxpf);
	return (y + 1);
}
