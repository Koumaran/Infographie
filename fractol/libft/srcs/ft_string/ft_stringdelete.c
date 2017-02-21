/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringdelete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:45:23 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/10 12:45:25 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stringdelete(t_string *string)
{
	if (string && string->content)
		ft_strdel(&string->content);
	string->size = 0;
	string->alloc_size = 0;
}
