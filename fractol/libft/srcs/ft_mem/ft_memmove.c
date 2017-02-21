/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:30:15 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/25 18:45:19 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	char	*tmp_dest;
	char	*tmp_src;

	tmp_dest = (char *)dest;
	tmp_src = (char *)src;
	if (tmp_src < tmp_dest)
	{
		tmp_dest = tmp_dest + n - 1;
		tmp_src = tmp_src + n - 1;
		while (n-- > 0)
			*tmp_dest-- = *tmp_src--;
	}
	else
		while (n-- > 0)
			*tmp_dest++ = *tmp_src++;
	return (dest);
}
