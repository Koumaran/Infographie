/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringinit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:44:15 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/10 12:44:35 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stringinit(t_string *string)
{
	string->content = ft_strnew(16);
	string->size = 0;
	string->alloc_size = (string->content) ? 16 : 0;
}

int		ft_stringext(t_string *string, int need)
{
	char	*tmp;
	int		len;

	need += string->size + 1;
	if (need < string->alloc_size)
		return (1);
	len = string->alloc_size - 1;
	while (need >= len)
		len += 16;
	if ((tmp = ft_strnew(len)) == NULL)
		return (0);
	string->alloc_size = len;
	if (string->content)
	{
		ft_memmove(tmp, string->content, sizeof(char) * string->size);
		ft_bzero(tmp + string->size, len - string->size);
		free(string->content);
	}
	string->content = tmp;
	return (1);
}
