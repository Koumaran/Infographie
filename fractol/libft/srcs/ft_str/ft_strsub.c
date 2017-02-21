/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:47:44 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/09 17:12:09 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	if (!(tmp = (char *)ft_memalloc(len + 1)))
		return (NULL);
	i = -1;
	while (++i < len && s[start] != '\0')
		tmp[i] = s[start++];
	tmp[i] = '\0';
	return (tmp);
}
