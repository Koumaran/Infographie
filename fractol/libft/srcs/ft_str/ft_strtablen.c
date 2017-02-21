/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtablen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 11:31:28 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/12 11:33:38 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strtablen(char **tab)
{
	size_t		len;

	len = 0;
	if (tab && *tab)
	{
		while (tab[len])
			len++;
	}
	return (len);
}
