/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:00:45 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/05 12:33:29 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct		s_format
{
	char			flag[5];
	int				min_wd;
	int				precision;
	char			len[3];
	char			conversion;
}					t_format;

size_t				ft_wstrlen(const wchar_t *s);
void				ft_putwstr(const wchar_t *s);
void				ft_putwchar(wchar_t c);
int					ft_digits(unsigned long long nbr, int base);
int					ft_haschar(const char *str, const char c);
int					ft_power(int nbr, int power);
unsigned long long	process_nbr(unsigned long long nbr, t_format *format);
void				ft_putnbr_base(unsigned long long n, int base, int cap);
void				convert_xou(t_format *format, va_list ap, int *count);
void				convert_di(t_format *format, va_list ap, int *count);
void				convert_p(t_format *format, va_list ap, int *count);
void				convert_s(t_format *format, va_list ap, int *count,
																int is_null);
void				convert_ws(t_format *format, va_list ap, int *count);
void				convert_c(t_format *format, va_list ap, int *count,
																int has_l_mod);
void				convert_ef(t_format *format, va_list ap, int *count);
int					ft_printf(const char *s, ...);

#endif
