/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:37:58 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/21 12:52:46 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(t_ulong nb, const char *base)
{
	int				base_len;
	char			*str;
	int				i;
	t_ulong			tmp;

	base_len = ft_strlen(base);
	if (nb == 0 || base_len == 0)
		return (ft_strdup("0"));
	tmp = nb;
	i = 1;
	while ((tmp /= base_len) != 0)
		i++;
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	tmp = nb;
	while (--i >= 0)
	{
		str[i] = base[tmp % base_len];
		tmp /= base_len;
	}
	return (str);
}
