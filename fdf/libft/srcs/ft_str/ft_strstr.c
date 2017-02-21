/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:47:33 by jsivanes          #+#    #+#             */
/*   Updated: 2016/04/22 16:32:17 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *str, char const *to_find)
{
	size_t	size;

	if (*to_find == '\0')
		return ((char *)str);
	size = ft_strlen(to_find);
	while (*str)
	{
		if (ft_strncmp(str, to_find, size) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
