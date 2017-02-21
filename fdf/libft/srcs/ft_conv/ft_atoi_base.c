/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:57:24 by jsivanes          #+#    #+#             */
/*   Updated: 2016/09/23 08:43:59 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ulong		ft_atoi_base(char const *s, char const *base)
{
	int			base_len;
	t_ulong		nb;
	int			i;

	base_len = ft_strlen(base);
	if ((!s && !*s) || base_len == 0)
		return (0);
	nb = 0;
	i = 0;
	while (*s)
	{
		if ((i = ft_strchri(base, *s)) >= 0)
		{
			if (*s - 'A' >= 0)
				nb = nb * base_len + (*s - 'A' + 10);
			else
				nb = nb * base_len + (*s - '0');
		}
		s++;
	}
	return (nb);
}
