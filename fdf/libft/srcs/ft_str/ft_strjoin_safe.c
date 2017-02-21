/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_safe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:43:04 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/28 16:15:30 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_safe(char *s1, char *s2)
{
	char		*tmp;

	tmp = NULL;
	if (s1 && s2)
	{
		tmp = ft_strjoin(s1, s2);
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	if (!s2 && s1)
	{
		tmp = ft_strdup(s1);
		ft_strdel(&s1);
	}
	if (!s1 && s2)
	{
		tmp = ft_strdup(s2);
		ft_strdel(&s2);
	}
	return (tmp);
}
