/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ef.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:28:15 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/04 21:52:24 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_fnbr(t_format *format, int *ct, int show_dot, double nbr)
{
	int					amp;
	double				n;

	amp = ft_power(10, format->precision);
//	n = nbr * amp - (unsigned long long)nbr * amp; //why not work if nbr is casted as int instead of ull?
	ft_putnbr_base(nbr + (!show_dot && ((int)(nbr * 10) % 10 >= 5)), 10, 0);
	if (show_dot && ++*(ct))
		ft_putchar('.');
	if (format->precision > 0 && (*ct += format->precision))
	{
		if ((n = nbr * amp - (int)nbr * amp))
		{
//			while ((nbr *= 10) && ((int)nbr % 10) == 0
//											&& ((int)(nbr * 10) % 10 != 9))
			nbr *= 10;
			while (((int)nbr % 10) == 0 && ((int)(nbr * 10) % 10 != 9))
			{
				ft_putchar('0');
				nbr *= 10;
			}
			ft_putnbr_base(n + ((int)(n * 10) % 10 >= 5), 10, 0);
		}
		else
		{
			while (format->precision-- > 0)
				ft_putnbr_base(0, 10, 0);
		}
	}
}

static void		processes(t_format *format, int *ct, int show_dot, double nbr)
{
	int shift_dot;

	shift_dot = ft_digits((unsigned long long)nbr, 10) - 1;
	if (format->conversion == 'e' || format->conversion == 'E')
		nbr /= ft_power(10, shift_dot);
	else
		*ct = shift_dot + 1;
	put_fnbr(format, ct, show_dot, nbr);
	if (format->conversion == 'e' || format->conversion == 'E')
	{
		ft_putchar(format->conversion);
		ft_putchar('+');
		if (shift_dot < 10)
			ft_putchar('0');
		ft_putnbr_base(shift_dot, 10, 0);
		*ct += 5;
	}
}

//what about negative 0?
//L modifier?

void			convert_ef(t_format *format, va_list ap, int *ct)
{
	double	nbr;
	char	fill;
	char	sign;
	int		show_dot;

	fill = (ft_haschar(format->flag, '0') && !ft_haschar(format->flag, '-'))
			? '0' : ' ';
	nbr = va_arg(ap, double);
	sign = (ft_haschar(format->flag, ' ') && nbr >= 0) ? ' ' : '\0';
	sign = (ft_haschar(format->flag, '+') && nbr >= 0) ? '+' : sign;
	sign = (nbr < 0) ? '-' : sign;
	nbr = (nbr < 0) ? nbr * -1 : nbr;
	format->precision = (format->precision < 0) ? 6 : format->precision;
	show_dot = (ft_haschar(format->flag, '#') || format->precision > 0) ? 1 : 0;
	format->min_wd -= (format->precision + show_dot + (sign != '\0'));
	format->min_wd -= (format->conversion == 'f' || format->conversion == 'F')
		? ft_digits((unsigned long long)nbr, 10) : 5; //will this work with int?
	if (fill == '0' && sign)
		ft_putchar(sign);
	while (!(ft_haschar(format->flag, '-')) && format->min_wd-- > 0 && ++(*ct))
		ft_putchar(fill);
	if (fill == ' ' && sign)
		ft_putchar(sign);
	*ct += (sign != '\0');
	processes(format, ct, show_dot, nbr);
}
