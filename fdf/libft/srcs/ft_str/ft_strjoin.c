/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:37:33 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/08 17:05:51 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;

	tmp = NULL;
	if (s1 && s2)
	{
		if ((tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
			return (NULL);
		tmp = ft_strcpy(tmp, s1);
		tmp = ft_strcat(tmp, s2);
	}
	return (tmp);
}
