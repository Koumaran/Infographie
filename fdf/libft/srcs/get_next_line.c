/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:41:56 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/25 16:49:16 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			nl_found(t_list *file, char *str, char **line)
{
	char		*tmp;

	tmp = ft_strchr(str, '\n');
	*line = ft_strsub(str, 0, tmp - str);
	file->content = (void*)ft_strdup(tmp + 1);
	ft_strdel(&str);
	return (1);
}

static t_list		*ft_lstfind_size(t_list **lst, size_t size)
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

static int			get_line(const int fd, char **line, t_list *file, char *str)
{
	char			*buf;
	int				ret;

	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoin_safe(str, buf);
		if (ft_strchr(str, '\n') != NULL)
			return (nl_found(file, str, line));
		buf = ft_strnew(BUFF_SIZE);
	}
	ft_strdel(&buf);
	if (ret == -1)
		return (-1);
	if (str && *str)
	{
		*line = ft_strdup(str);
		ft_strdel(&str);
		return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*file;
	char			*str;
	t_list			*tmp;

	if (line == NULL || fd < 0)
		return (-1);
	tmp = ft_lstfind_size(&file, (size_t)fd);
	str = ft_strdup((char *)tmp->content);
	ft_strdel((char**)&tmp->content);
	if ((ft_strchr(str, '\n') != NULL) && str && str[0])
		return (nl_found(tmp, str, line));
	return (get_line(fd, line, tmp, str));
}
