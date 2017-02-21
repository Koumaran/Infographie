/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:50:37 by jsivanes          #+#    #+#             */
/*   Updated: 2016/05/06 19:02:38 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*ft_dup_word(char const *s, char c)
{
	char		*word;
	t_list		*lst;
	int			len;
	int			i;

	len = 0;
	lst = NULL;
	while (s[len] && s[len] != c)
		len++;
	word = ft_memalloc(len + 1);
	i = -1;
	while (++i < len)
		word[i] = s[i];
	word[i] = '\0';
	lst = ft_lstnew(word, len);
	return (lst);
}

t_list				*ft_strsplit_lst(char const *s, char c)
{
	t_list		*lst_first;
	t_list		*lst;

	lst_first = NULL;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (lst_first == NULL)
			{
				lst_first = ft_dup_word(s, c);
				lst = lst_first;
			}
			else
			{
				lst->next = ft_dup_word(s, c);
				lst = lst->next;
			}
		}
		while (*s && *s != c)
			s++;
	}
	return (lst_first);
}
