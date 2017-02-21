/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:26:27 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/22 10:52:37 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->content = NULL;
	tmp->next = NULL;
	if (!content)
	{
		tmp->content_size = 0;
		return (tmp);
	}
	tmp->content = malloc(content_size);
	ft_memcpy(tmp->content, content, content_size);
	tmp->content_size = content_size;
	return (tmp);
}
