/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:29:30 by jsivanes          #+#    #+#             */
/*   Updated: 2016/03/18 15:29:31 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(void const *s1, void const *s2, size_t n)
{
	unsigned char *tmp_s1;
	unsigned char *tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	while (n > 0 && *tmp_s1 == *tmp_s2)
	{
		tmp_s1++;
		tmp_s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*tmp_s1 - *tmp_s2);
}
