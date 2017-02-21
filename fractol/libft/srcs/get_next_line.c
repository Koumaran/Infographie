/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:41:56 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/07 18:29:48 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nl_found(t_list *file, char *str, char **line)
{
	char		*tmp;

	tmp = ft_strchr(str, '\n');
	*line = ft_strsub(str, 0, tmp - str);
	file->content = (void*)ft_strdup(tmp + 1);
	ft_strdel(&str);
	return (1);
}

static t_list	*ft_lstfind_size(t_list **lst, size_t size)
{
	t_list		*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp)
		{
			if (tmp->content_size == size)
				return (tmp);
			tmp = tmp->next;
		}
		tmp = ft_lstnew(NULL, size);
		tmp->content_size = size;
		ft_lstadd(lst, tmp);
		return (tmp);
	}
	*lst = ft_lstnew(NULL, size);
	(*lst)->content_size = size;
	return (*lst);
}

static void		clear_lst(t_list **lst, t_list **to_del)
{
	t_list		*tmp;

	tmp = *lst;
	if ((*to_del)->next)
	{
		while (tmp->next && tmp->next->content_size != (*to_del)->content_size)
			tmp = tmp->next;
		tmp->next = (*to_del)->next;
	}
	free((*to_del)->content);
	free(*to_del);
	*to_del = NULL;
}

static int		get_line(t_list *file, char **line, t_list *afile, char *str)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	ft_bzero(buf, BUFF_SIZE + 1);
	while ((ret = read(afile->content_size, buf, BUFF_SIZE)) > 0)
	{
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
		if (ft_strchr(str, '\n') != NULL)
			return (nl_found(afile, str, line));
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (ret == -1)
		return (-1);
	if (str && *str)
	{
		*line = ft_strdup(str);
		ft_strdel(&str);
		return (1);
	}
	ft_strdel(&str);
	clear_lst(&file, &afile);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	char			*str;
	t_list			*tmp;

	if (line == NULL || fd < 0)
		return (-1);
	tmp = ft_lstfind_size(&file, (size_t)fd);
	if (tmp->content)
	{
		str = ft_strdup((char *)tmp->content);
		ft_strdel((char**)&tmp->content);
	}
	else
		str = ft_strnew(BUFF_SIZE);
	if ((ft_strchr(str, '\n') != NULL) && str && str[0])
		return (nl_found(tmp, str, line));
	return (get_line(file, line, tmp, str));
}
