/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xou.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:48:40 by yazhu             #+#    #+#             */
/*   Updated: 2017/12/28 20:34:59 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //delete me!!!
static void		alternate_form(t_format *format)
{
	if (format->conversion == 'x')
		ft_putstr("0x");
	else if (format->conversion == 'X')
		ft_putstr("0X");
	else if (format->conversion == 'o')
		ft_putchar('0');
}

void	convert_xou(t_format *format, va_list ap, int *count)
{
	char				fill;
	unsigned long long	nbr;
	int					base;
	int					is_uU;
	int					alt_form_count;

	fill = ' ';
	nbr = process_nbr(va_arg(ap, unsigned long long), format);
	is_uU = (format->conversion == 'u' || format->conversion == 'U') ? 1 : 0;
	base = (format->conversion == 'x' || format->conversion == 'X') ? 16 : 8;
	base = (is_uU) ? 10 : base;
	if (!(alt_form_count = 0) && ft_haschar(format->flag, '#') && nbr != 0)
		alt_form_count = (base == 16) ? 2 : (base == 8);
	format->min_width -= (ft_digits(nbr, base) + alt_form_count);
	*count += (ft_digits(nbr, base) + alt_form_count);
	if (format->precision > 0)
	{
		if ((format->precision -= ft_digits(nbr, base)) > 0)
			format->min_width -= format->precision;
	}
	else if (ft_haschar(format->flag, '0') && !ft_haschar(format->flag, '-'))
	{
		fill = '0';
		if (!is_uU && ft_haschar(format->flag, '#') && nbr != 0)
			alternate_form(format);
	}
	while (!(ft_haschar(format->flag, '-')) && format->min_width-- > 0 && ++(*count))
		ft_putchar(fill);
	if (!is_uU && fill == ' ' && ft_haschar(format->flag, '#') && nbr != 0)
		alternate_form(format);
	while (format->precision-- > 0 && ++(*count))
		ft_putchar('0');
	ft_putnbr_base(nbr, base, format->conversion == 'X');
	while (ft_haschar(format->flag, '-') && format->min_width-- > 0 && ++(*count))
		ft_putchar(fill);
}
