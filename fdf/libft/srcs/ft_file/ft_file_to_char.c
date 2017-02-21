/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 17:01:52 by jsivanes          #+#    #+#             */
/*   Updated: 2016/04/22 18:09:04 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_file_to_char(char *file)
{
	int		fd;
	char	*tmp;
	int		filelen;

	filelen = ft_filelen(file);
	if (!filelen || !(tmp = ft_memalloc(filelen + 1)))
		return (NULL);
	fd = open(file, O_RDONLY);
	read(fd, tmp, filelen);
	tmp[filelen] = '\0';
	close(fd);
	return (tmp);
}
