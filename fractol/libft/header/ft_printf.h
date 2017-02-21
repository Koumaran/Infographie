/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 17:39:12 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/15 19:22:38 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <wchar.h>
# include <locale.h>
# include <stdarg.h>
# include "libft.h"

# define NB_FLAG			11
# define ALL				"%#+-0123456789 .*sSpdDiIoOuUxXcChLljzfFeEnb\'"
# define LENGTH				"hhllLjzI64"
# define CONVERT			"sSpdDioOuUxXcCfFeEnb%"

# define CHR(s, c)			(ft_strchr(s, c))
# define DP(x)				(ft_strdup(x))
# define JN(a, b)			(ft_strjoin_safe(a, b))

# define RET				boxpf->ret
# define STR				boxpf->str
# define FLAG				boxpf->flag
# define TYPE				boxpf->type
# define WIDTH				boxpf->width
# define PRES				boxpf->pres

typedef struct				s_boxpf
{
	char					*str;
	char					*flag;
	char					*length;
	char					type;
	int						ret;
	int						width;
	int						pres;
	int						sign;
}							t_boxpf;

typedef struct				s_ft
{
	char					*name;
	void					(*ft)(va_list ap, t_boxpf *boxpf);
}							t_ft;

int							ft_printf(const char *restrict fmt, ...);
int							ft_printf_string(t_string *string,\
							const char *restrict fmt, ...);
int							parse(va_list ap, char *fmt, t_string *string);
int							parse_convert(va_list ap, char *fmt,
							t_boxpf *boxpf);
int							parse_color(char *fmt, t_boxpf *boxpf);
void						get_fonction(t_boxpf *boxpf, va_list ap);
void						add_flag(t_boxpf *boxpf, char c);
void						flag_0_neg(t_boxpf *boxpf, int size, char c);
void						precision(t_boxpf *boxpf);
t_long						get_arg(t_boxpf *boxpf, va_list ap);
t_ulong						get_unsigned_arg(t_boxpf *boxpf, va_list ap);
long double					get_float_arg(t_boxpf *boxpf, va_list ap);
int							ft_wstrlen(wchar_t *wstr);
int							ft_wstrnconv(char *b, wchar_t *wstr, int n);
int							unicode_to_utf8(char *b, wchar_t w);
void						convert_d(va_list ap, t_boxpf *boxpf);
void						convert_s(va_list ap, t_boxpf *boxpf);
void						convert_c(va_list ap, t_boxpf *boxpf);
void						convert_o(va_list ap, t_boxpf *boxpf);
void						convert_u(va_list ap, t_boxpf *boxpf);
void						convert_x(va_list ap, t_boxpf *boxpf);
void						convert_p(va_list ap, t_boxpf *boxpf);
void						convert_percent(va_list ap, t_boxpf *boxpf);
void						convert_f(va_list ap, t_boxpf *boxpf);
void						convert_e(va_list ap, t_boxpf *boxpf);
void						convert_n(va_list ap, t_boxpf *boxpf, int size);
void						convert_b(va_list ap, t_boxpf *boxpf);
char						*before_cama(double nbr, int pres, char *flag);
void						after_cama(char *str, double f, int pres);
void						fix_precision(char *str);
char						*add_apos(char *str, int len);
#endif
