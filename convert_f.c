/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:28:15 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/04 13:52:08 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_fnbr(t_format *format, int *ct, int show_dot, double *nbr)
{
	int amp;

	amp = ft_power(10, format->precision);
	ft_putnbr_base(*nbr + (!show_dot && ((int)(*nbr * 10) % 10 >= 5)), 10, 0);
	if (show_dot && ++*(ct))
		ft_putchar('.');
	if (format->precision > 0 && (*ct += format->precision))
	{
		if ((*nbr = (*nbr * amp - (int)*nbr * amp)))
			ft_putnbr_base(*nbr + ((int)(*nbr * amp * 10) % 10 >= 5), 10, 0);
		else
		{
			while (format->precision-- > 0)
				ft_putnbr_base(0, 10, 0);
		}
	}
}

//what about negative 0?

void			convert_f(t_format *format, va_list ap, int *ct)
{
	double	nbr;
	char	fill;
	char	sign;
	int		show_dot;

	fill = (ft_haschar(format->flag, '0') && !ft_haschar(format->flag, '-'))
			? '0' : ' ';
	nbr = va_arg(ap, double);
	sign = (nbr < 0) ? '-' : '\0';
	nbr = (nbr < 0) ? nbr * -1 : nbr;
	if (format->precision < 0)
		format->precision = 6;
	show_dot = (ft_haschar(format->flag, '#') || format->precision > 0) ? 1 : 0;
	format->min_wd -= (format->precision + ft_digits((int)nbr, 10)
			+ show_dot + (sign == '-'));
	if (fill == '0' && sign)
		ft_putchar(sign);
	while (!(ft_haschar(format->flag, '-')) && format->min_wd-- > 0 && ++(*ct))
		ft_putchar(fill);
	if (fill == ' ' && sign)
		ft_putchar(sign);
	*ct += (ft_digits((int)nbr, 10) + (sign == '-'));
	put_fnbr(format, ct, show_dot, &nbr);
}
