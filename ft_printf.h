/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:00:45 by yazhu             #+#    #+#             */
/*   Updated: 2017/12/27 20:01:53 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h> //need to include this?

typedef struct		s_format
{
	char			flag[5];
	int				min_width;
	int				precision;
	char		 	length[3];
	char			conversion;
}					t_format;

size_t				ft_wstrlen(const wchar_t *s);
void				ft_putwstr(const wchar_t *s);
void				ft_putwchar(wchar_t c);
int					ft_digits(unsigned long long nbr, int base);
int					ft_haschar(const char *str, const char c);
void				process_putnbr(unsigned long long nbr, t_format *format, int base);
void				ft_putnbr_base(unsigned long long n, int base, int cap);
void				convert_xou(t_format *format, va_list ap, int *count);
void				convert_di(t_format *format, va_list ap, int *count);
void				convert_p_percent(t_format *format, va_list ap, int *count);
int					ft_printf(const char *s, ...);

#endif
