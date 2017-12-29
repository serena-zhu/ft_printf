/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 20:08:47 by yazhu             #+#    #+#             */
/*   Updated: 2017/12/28 20:20:06 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_c(t_format *format, va_list ap, int *count, int has_l_mod)
{
	wchar_t wc;
	int		left_adjusted;

	left_adjusted = ft_haschar(format->flag, '-');
	wc = va_arg(ap, int);
	(*count)++;
	format->min_width--;
	while (!left_adjusted && format->min_width-- > 0 && ++(*count))
		ft_putchar(' ');
	if ((format->conversion == 'c' && has_l_mod) || format->conversion == 'C')
		ft_putwchar(wc);
	else
		ft_putchar((char)wc);
	while (left_adjusted && format->min_width-- > 0 && ++(*count))
		ft_putchar(' ');
}
