/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:35:35 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/06 22:07:35 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_ws(t_format *format, va_list ap, int *count)
{
	wchar_t *wstr;
	int		left_adjusted;
	int		word_length;
	int		trim;

	left_adjusted = ft_haschar(format->flag, '-');
	if (!(wstr = va_arg(ap, wchar_t *)))
		convert_s(format, ap, count, 1);
	word_length = ft_wstrlen(wstr);
	trim = (format->precision > 0 && format->precision < word_length) ? 1 : 0;
	*count += (trim) ? format->precision : word_length;
	format->min_w -= (trim) ? format->precision : word_length;
	while (!left_adjusted && format->min_w-- > 0 && ++(*count))
		ft_putchar(' ');
	while (trim && format->precision-- > 0)
		ft_putwchar(*wstr++);
	if (!trim)
		ft_putwstr(wstr);
	while (left_adjusted && format->min_w-- > 0 && ++(*count))
		ft_putchar(' ');
}
