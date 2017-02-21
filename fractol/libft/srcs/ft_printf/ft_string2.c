/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:07:34 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/09 16:08:09 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_stringdelete(t_string *string)
{
	if (string && string->content)
		ft_strdel(&string->content);
	string->size = 0;
	string->alloc_size = 0;
}
