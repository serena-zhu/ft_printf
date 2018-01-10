/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xou.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:48:40 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/09 21:54:18 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		alternate_form(t_format *format)
{
	if (format->conv == 'x')
		ft_putstr("0x");
	else if (format->conv == 'X')
		ft_putstr("0X");
	else if (format->conv == 'o' || format->conv == 'O')
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
			&& (format->conv == 'u' || format->conv == 'U'))
		format->min_w -= (*count += digits / 3) ? digits / 3 : 0;
	if (format->prec > 0)
	{
		if ((format->prec -= (digits + (alt_form_count == 1))) > 0)
			format->min_w -= format->prec;
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
	skip_nbr = ((ft_haschar(format->flag, '#') && (format->conv == 'o'
		|| format->conv == 'O')) || !(format->prec == 0 && nbr == 0)) ? 0 : 1;
	is_u = (format->conv == 'u' || format->conv == 'U') ? 1 : 0;
	base = (format->conv == 'x' || format->conv == 'X') ? 16 : 8;
	base = (is_u) ? 10 : base;
	fill = (!skip_nbr) ? processes(format, &nbr, ct, base) : fill;
	while (!(ft_haschar(format->flag, '-')) && format->min_w-- > 0 && ++(*ct))
		ft_putchar(fill);
	if (!is_u && fill == ' ' && ft_haschar(format->flag, '#') && nbr != 0)
		alternate_form(format);
	while (format->prec-- > 0 && ++(*ct))
		ft_putchar('0');
	if (!skip_nbr)
		ft_putnbr_base(nbr, base, format->conv == 'X', is_u
			&& ft_haschar(format->flag, '\''));
	while (ft_haschar(format->flag, '-') && format->min_w-- > 0 && ++(*ct))
		ft_putchar(fill);
}
