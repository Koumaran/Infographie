/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:53 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/08 17:06:44 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(char *dest, char const *src)
{
	char	*tmp_dest;
	char	*tmp_src;

	tmp_dest = dest;
	tmp_src = (char*)src;
	while (*tmp_dest)
		tmp_dest++;
	while (*tmp_src)
		*tmp_dest++ = *tmp_src++;
	*tmp_dest = '\0';
	return (dest);
}
