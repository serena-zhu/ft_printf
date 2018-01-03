/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xou.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:48:40 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/02 20:04:26 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		alternate_form(t_format *format)
{
	if (format->conversion == 'x')
		ft_putstr("0x");
	else if (format->conversion == 'X')
		ft_putstr("0X");
	else if (format->conversion == 'o')
		ft_putchar('0');
}

static char		processes(t_format *format, unsigned long long *nbr,
							int *count, int base)
{
	char	fill;
	int		alt_form_count;

	fill = ' ';
	if (!(alt_form_count = 0) && ft_haschar(format->flag, '#') && *nbr != 0)
		alt_form_count = (base == 16) ? 2 : (base == 8);
	format->min_width -= (ft_digits(*nbr, base) + alt_form_count);
	*count += (ft_digits(*nbr, base) + alt_form_count);
	if (format->precision > 0)
	{
		if ((format->precision -= ft_digits(*nbr, base)) > 0)
			format->min_width -= format->precision;
	}
	else if (ft_haschar(format->flag, '0') && !ft_haschar(format->flag, '-'))
	{
		fill = '0';
		if (base != 10 && ft_haschar(format->flag, '#') && nbr != 0)
			alternate_form(format);
	}
	return (fill);
}

void			convert_xou(t_format *format, va_list ap, int *count)
{
	char				fill;
	unsigned long long	nbr;
	int					base;
	int					is_u;
	int					skip_nbr;

	fill = ' ';
	nbr = process_nbr(va_arg(ap, unsigned long long), format);
	skip_nbr = ((format->conversion == 'o' && ft_haschar(format->flag, '#'))
			|| !(format->precision == 0 && nbr == 0)) ? 0 : 1;
	is_u = (format->conversion == 'u' || format->conversion == 'U') ? 1 : 0;
	base = (format->conversion == 'x' || format->conversion == 'X') ? 16 : 8;
	base = (is_u) ? 10 : base;
	if (!skip_nbr)
		fill = processes(format, &nbr, count, base);
	while (!(ft_haschar(format->flag, '-')) && format->min_width-- > 0
			&& ++(*count))
		ft_putchar(fill);
	if (!is_u && fill == ' ' && ft_haschar(format->flag, '#') && nbr != 0)
		alternate_form(format);
	while (format->precision-- > 0 && ++(*count))
		ft_putchar('0');
	if (!skip_nbr)
		ft_putnbr_base(nbr, base, format->conversion == 'X');
	while (ft_haschar(format->flag, '-') && format->min_width-- > 0
			&& ++(*count))
		ft_putchar(fill);
}
