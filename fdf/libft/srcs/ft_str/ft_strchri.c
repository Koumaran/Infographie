/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:27:08 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/01 17:57:18 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchri(char const *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != (char)c)
		if (!s[i++])
			return (-1);
	return (i);
}
