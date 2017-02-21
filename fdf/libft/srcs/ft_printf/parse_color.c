/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 21:59:37 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/08 18:21:39 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*color_me(char *str)
{
	if (ft_strequ(str, "{eoc}"))
		return (ft_strdup("\033[0m"));
	if (ft_strequ(str, "{black}"))
		return (ft_strdup("\033[30m"));
	if (ft_strequ(str, "{red}"))
		return (ft_strdup("\033[31m"));
	if (ft_strequ(str, "{green}"))
		return (ft_strdup("\033[32m"));
	if (ft_strequ(str, "{yellow}"))
		return (ft_strdup("\033[33m"));
	if (ft_strequ(str, "{blue}"))
		return (ft_strdup("\033[34m"));
	if (ft_strequ(str, "{magenta}"))
		return (ft_strdup("\033[35m"));
	if (ft_strequ(str, "{cyan}"))
		return (ft_strdup("\033[36m"));
	if (ft_strequ(str, "{white}"))
		return (ft_strdup("\033[37m"));
	return (NULL);
}

int				parse_color(char *fmt, t_boxpf *boxpf)
{
	int		end;
	char	*str;
	int		ret;

	if ((end = ft_strchri(fmt, '}')) == -1)
		return (-1);
	ret = 0;
	str = ft_strsub(fmt, 0, end + 1);
	STR = color_me(str);
	ret = (STR != NULL) ? (int)(ft_strlen(str) - 2) : (int)-1;
	free(str);
	return (ret);
}
