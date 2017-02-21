/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:55:56 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/09 18:00:59 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoin(const char *str, int len)
{
	int		nb;
	int		sign;

	sign = 1;
	nb = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
		len--;
	}
	else if (*str == '+')
	{
		str++;
		len--;
	}
	while (ft_isdigit(*str) && len-- > 0)
		nb = nb * 10 + (*(str++) - '0');
	return (nb * sign);
}
