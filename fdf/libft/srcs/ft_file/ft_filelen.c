/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 17:52:13 by jsivanes          #+#    #+#             */
/*   Updated: 2016/04/22 18:10:44 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_filelen(char *file)
{
	int		fd;
	int		len;
	char	buf;

	len = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (read(fd, &buf, 1))
		len++;
	if (close(fd) == -1)
		return (0);
	return (len);
}
