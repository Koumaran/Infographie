/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 20:13:58 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/27 20:24:34 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*tmp;

	tmp = *alst;
	if (alst && *alst && new)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else if (new)
		*alst = new;
}
