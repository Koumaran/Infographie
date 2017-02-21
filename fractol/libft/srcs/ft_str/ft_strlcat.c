/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:37:48 by jsivanes          #+#    #+#             */
/*   Updated: 2016/03/18 15:37:49 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char const *src, size_t count)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] && i < count)
		i++;
	j = i;
	while (src[i - j] && i < count - 1)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < count)
		dest[i] = '\0';
	return (j + ft_strlen(src));
}
