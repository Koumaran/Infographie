/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:15:22 by jsivanes          #+#    #+#             */
/*   Updated: 2016/03/18 15:47:18 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	str2[ft_strlen(str)];

	i = -1;
	j = -1;
	while (str[++i] != '\0')
		str2[i] = str[i];
	while (i-- > 0)
		str[++j] = str2[i];
	return (str);
}
