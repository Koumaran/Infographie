/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 17:35:31 by jsivanes          #+#    #+#             */
/*   Updated: 2016/05/14 17:51:53 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getnbr(char const *s)
{
	int		res;

	res = 0;
	if (!s)
		return (0);
	if (s != NULL && *s == '-')
		return (-ft_getnbr(s + 1));
	while ((*s >= '0') && (*s <= '9'))
		res = (res * 10) + (*s++ - '0');
	return (res);
}
