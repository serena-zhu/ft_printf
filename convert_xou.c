/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xou.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:48:40 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/09 21:11:34 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		alternate_form(t_format *format)
{
	if (format->conversion == 'x')
		ft_putstr("0x");
	else if (format->conversion == 'X')
		ft_putstr("0X");
	else if (format->conversion == 'o' || format->conversion == 'O')
		ft_putchar('0');
}

static char		processes(t_format *format, unsigned long long *nbr,
							int *count, int base)
{
	char	fill;
	int		alt_form_count;
	int		digits;

	fill = ' ';
	digits = ft_digits(*nbr, base);
	if (!(alt_form_count = 0) && ft_haschar(format->flag, '#') && *nbr != 0)
		alt_form_count = (base == 16) ? 2 : (base == 8);
	*count += (digits + alt_form_count);
	format->min_w -= (digits + alt_form_count);
	if (*nbr >= 1000 && ft_haschar(format->flag, '\'')
			&& (format->conversion == 'u' || format->conversion == 'U'))
		format->min_w -= (*count += digits / 3) ? digits / 3 : 0;
	if (format->precision > 0)
	{
		if ((format->precision -= ((digits > 0) + (alt_form_count == 1))))
			format->min_w -= format->precision;
	}
	else if (ft_haschar(format->flag, '0') && !ft_haschar(format->flag, '-'))
	{
		fill = '0';
		if (base != 10 && ft_haschar(format->flag, '#') && nbr != 0)
			alternate_form(format);
	}
	return (fill);
}

void			convert_xou(t_format *format, va_list ap, int *ct)
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
	fill = (!skip_nbr) ? processes(format, &nbr, ct, base) : fill;
	while (!(ft_haschar(format->flag, '-')) && format->min_w-- > 0 && ++(*ct))
		ft_putchar(fill);
	if (!is_u && fill == ' ' && ft_haschar(format->flag, '#') && nbr != 0)
		alternate_form(format);
	while (format->precision-- > 0 && ++(*ct))
		ft_putchar('0');
	if (!skip_nbr)
		ft_putnbr_base(nbr, base, format->conversion == 'X', is_u
			&& ft_haschar(format->flag, '\''));
	while (ft_haschar(format->flag, '-') && format->min_w-- > 0 && ++(*ct))
		ft_putchar(fill);
}
