/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_sqrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:25:08 by jsivanes          #+#    #+#             */
/*   Updated: 2016/04/22 16:57:46 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_memalloc_2d(size_t x, size_t y)
{
	void	**tmp;
	size_t	i;

	i = 0;
	if (!(tmp = (void**)malloc(sizeof(tmp) * y + 1)))
		return (tmp);
	while (i < y)
		tmp[i++] = (void*)ft_memalloc(x);
	tmp[y] = 0;
	return (tmp);
}
