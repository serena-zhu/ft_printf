/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 20:08:47 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/06 22:06:02 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_c(t_format *format, va_list ap, int *count, int has_l_mod)
{
	wchar_t wc;
	int		left_adjust;
	char	fill;

	left_adjust = ft_haschar(format->flag, '-');
	fill = ' ';
	wc = (format->conversion == '%') ? '%' : va_arg(ap, int);
	(*count)++;
	format->min_w--;
	if (ft_haschar(format->flag, '0') && !left_adjust)
		fill = '0';
	while (!left_adjust && format->min_w-- > 0 && ++(*count))
		ft_putchar(fill);
	if ((format->conversion == 'c' && has_l_mod) || format->conversion == 'C')
		ft_putwchar(wc);
	else
		ft_putchar((char)wc);
	while (left_adjust && format->min_w-- > 0 && ++(*count))
		ft_putchar(fill);
}
