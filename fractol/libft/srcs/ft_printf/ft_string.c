/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 18:24:19 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/09 16:08:11 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_stringaddc(t_string *string, char c)
{
	if (!ft_stringext(string, 1))
		return ;
	string->content[string->size] = c;
	string->size++;
}

void	ft_stringadd(t_string *string, char *str, int n)
{
	if (!ft_stringext(string, n))
		return ;
	ft_memmove(string->content + string->size, str, n);
	string->size += n;
}

void	ft_stringaddnl(t_string *string, char *str, int n)
{
	if (!ft_stringext(string, n + 1))
		return ;
	ft_memmove(string->content + string->size, str, n);
	string->size += n;
	string->content[string->size++] = '\n';
}
