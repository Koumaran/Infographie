/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 17:02:10 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/13 16:49:57 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		add_flag_for_x(t_boxpf *boxpf, int i, int size)
{
	if (CHR(FLAG, '#') && !boxpf->sign)
	{
		if (boxpf->width == size)
		{
			if (CHR(FLAG, '-'))
			{
				STR = (TYPE == 'x') ? JN(DP("0x"), STR) : JN(DP("0X"), STR);
				STR[size] = '\0';
			}
			else
			{
				if (!CHR(FLAG, '0'))
				{
					while (STR[i] == ' ')
						i++;
					i -= 2;
				}
				STR[i++] = '0';
				STR[i] = (TYPE == 'x') ? 'x' : 'X';
			}
		}
		else
			STR = (TYPE == 'x') ? JN(DP("0x"), STR) : JN(DP("0X"), STR);
	}
}

static void		add_flag_second(t_boxpf *boxpf, int size)
{
	int		i;

	if (CHR(FLAG, '+') || boxpf->sign)
	{
		i = 0;
		if (boxpf->width > boxpf->pres && boxpf->width >= size)
		{
			if (CHR(FLAG, '-') && (boxpf->sign || boxpf->pres > 0))
				STR = (boxpf->sign) ? JN(DP("-"), STR) : STR;
			if (CHR(FLAG, '+') && boxpf->width > size && !boxpf->sign)
				STR = JN(DP("+"), STR);
			else
			{
				while (STR[i] == ' ' && STR[i])
					i++;
				STR[i + ((i > 0) ? -1 : 0)] =
					(CHR(FLAG, '+') && !boxpf->sign) ? '+' : '-';
			}
		}
		else
			STR = (CHR(FLAG, '+') && !boxpf->sign) ?
				JN(DP("+"), STR) : JN(DP("-"), STR);
	}
}

void			add_flag(t_boxpf *boxpf, char c)
{
	int		size;

	size = (STR) ? (int)ft_strlen(STR) : 0;
	if (boxpf->width < 0)
	{
		boxpf->flag = ft_putchar_str(boxpf->flag, '-');
		boxpf->width *= -1;
	}
	if (size)
		if (boxpf->pres > size && TYPE != 'c' && TYPE != 'C')
			precision(boxpf);
	flag_0_neg(boxpf, (STR) ? (int)ft_strlen(STR) : 0, c);
	if (STR)
		if (CHR(FLAG, ' ') && (!TYPE || (CHR("dDi", TYPE)))
				&& !boxpf->sign && !CHR(FLAG, '+') && *STR)
			STR = JN(DP(" "), STR);
	if (CHR("dDifFeE", TYPE))
		add_flag_second(boxpf, (STR) ? (int)ft_strlen(STR) : 0);
	if (TYPE == 'x' || TYPE == 'X')
		add_flag_for_x(boxpf, 0, (STR) ? (int)ft_strlen(STR) : 0);
}
