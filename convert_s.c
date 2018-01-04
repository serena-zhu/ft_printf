/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:11:23 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/03 20:12:14 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_null(t_format *format, int trim)
{
	int		i;
	char	null_char[6];

	i = 0;
	null_char[0] = '(';
	null_char[1] = 'n';
	null_char[2] = 'u';
	null_char[3] = 'l';
	null_char[4] = 'l';
	null_char[5] = ')';
	while (trim && format->precision-- > 0)
		ft_putchar(null_char[i++]);
	if (!trim)
		ft_putstr("(null)");
}

void			convert_s(t_format *format, va_list ap, int *count, int is_null)
{
	char	*str;
	int		left_adjust;
	int		word_length;
	int		trim;

	left_adjust = ft_haschar(format->flag, '-');
	word_length = 6;
	if (is_null || !(str = va_arg(ap, char *)))
		is_null = 1;
	else
		word_length = ft_strlen(str);
	trim = (format->precision > 0 && format->precision < word_length) ? 1 : 0;
	*count += (trim) ? format->precision : word_length;
	format->min_wd -= (trim) ? format->precision : word_length;
	while (!left_adjust && format->min_wd-- > 0 && ++(*count))
		ft_putchar((ft_haschar(format->flag, '0') && !left_adjust) ? '0' : ' ');
	if (is_null)
		print_null(format, trim);
	while (trim && !is_null && format->precision-- > 0)
		ft_putchar(*str++);
	if (!trim && !is_null)
		ft_putstr(str);
	while (left_adjust && format->min_wd-- > 0 && ++(*count))
		ft_putchar(' ');
}
