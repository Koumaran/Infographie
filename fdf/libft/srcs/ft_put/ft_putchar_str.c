/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 21:26:53 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/23 18:56:08 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_putchar_str(char *str, char c)
{
	char	*tmp;
	int		len;

	if (!str)
	{
		tmp = ft_strnew(1);
		tmp[0] = c;
		return (tmp);
	}
	len = ft_strlen(str) + 1;
	tmp = ft_strnew(len);
	ft_memmove(tmp, str, (sizeof(char) * len));
	tmp[len - 1] = c;
	ft_strdel(&str);
	return (tmp);
}
