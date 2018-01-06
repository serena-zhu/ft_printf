/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ef.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:28:15 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/05 16:35:46 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>//delete me!!!
static void		put_fnbr(t_format *format, int *ct, int show_dot,
															long double nbr)
{
	int			amp;
	long double	n;

	amp = ft_power(10, format->precision);
	ft_putnbr_base(nbr + (!show_dot && ((int)(nbr * 10) % 10 >= 5)), 10, 0);
	if (show_dot && ++*(ct))
		ft_putchar('.');
	if (format->precision > 0 && (*ct += format->precision))
	{
		if ((n = nbr * amp - (unsigned long long)nbr * amp))
		{
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

static void		put_exp_for_e(t_format *format, int shift_dot, char exp)
{
	ft_putchar(format->conversion);
	ft_putchar(exp);
	if (shift_dot < 10)
		ft_putchar('0');
	ft_putnbr_base(shift_dot, 10, 0);
}

static void		nbr_processes(t_format *format, int *ct, int show_dot,
															long double nbr)
{
	int		shift_dot;
	int		tmp;
	char	exp;

	shift_dot = (nbr >= 1) ? ft_digits((unsigned long long)nbr, 10) - 1 : 0;
	tmp = shift_dot;
	exp = (nbr >= 1 || nbr == 0) ? '+' : '-';
	if (format->conversion == 'e' || format->conversion == 'E')
	{
		if (nbr >= 1)
			while (tmp-- > 0)
				nbr /= 10;
		else if (nbr != 0)
		{
			while (nbr < 1 && ++shift_dot)
				nbr *= 10;
		}
	}
	else
		*ct = shift_dot + 1;
	put_fnbr(format, ct, show_dot, nbr);
	if ((format->conversion == 'e' || format->conversion == 'E') && (*ct += 5))
		put_exp_for_e(format, shift_dot, exp);
}

static void		convert_g_to_ef(t_format *format, long double nbr, int no_precision)
{
	int digits;
	int	shift_dot;
	int	trailing_zeros;

	format->precision = (format->precision == 0) ? 1 : format->precision;
	format->precision = (no_precision) ? 6 : format->precision;
	shift_dot = 0;
	if (nbr < 1 && nbr > 0)
	{
		while (nbr < 1 && ++shift_dot)
			nbr *= 10;
		if (shift_dot > 4)
		{
			format->conversion += ('e' - 'g');
			format->precision -= 1;
		}
		else
		{
			format->conversion += ('f' - 'g');
			format->precision += (shift_dot - 1);
		}
//		printf("precision is %d and nbr is %LF\n", format->precision, nbr);
	}
	else
	{
		digits = ft_digits((unsigned long long)nbr, 10);
		shift_dot = digits - 1;
		if (shift_dot >= format->precision)
		{
			format->conversion += ('e' - 'g');
			format->precision -= 1;
		}
		else
		{
			format->conversion += ('f' - 'g');
			format->precision -= digits;
		}
		nbr *= 10;
	}
	trailing_zeros = 0;
//	nbr *= 10;
	if (no_precision)
	{
		format->precision = 0;
//		printf("nbr is %Lf and mod 10 is %d and next mod 10 is %d and next next mod is %d\n", nbr, (int)nbr % 10, (int)(nbr * 10) % 10, (int)(nbr * 100) % 10);
		while (((int)nbr % 10) != 0 && ++(format->precision) && ((int)(nbr * 10) % 10 != 9))//  && ++(format->precision))
		{
			nbr *= 10;	
//			format->precision++;
		}
	}
	else 
	{
//		nbr *= 10;
		while ((trailing_zeros < format->precision) && (((int)nbr % 10) == 0))
		{
			nbr *= 10;
			trailing_zeros++;
		}
		format->precision = (trailing_zeros == format->precision) ? 0 : format->precision;
	}
}

//what about negative 0?

void			convert_ef(t_format *format, va_list ap, int *ct)
{
	long double		nbr;
	char			fill;
	char			sign;
	int				show_dot;

//	format->precision = (format->precision < 0) ? 6 : format->precision;
	fill = (ft_haschar(format->flag, '0') && !ft_haschar(format->flag, '-'))
			? '0' : ' ';
	nbr = (ft_strcmp(format->len, "L") == 0)
			? va_arg(ap, long double) : va_arg(ap, double);
	sign = (ft_haschar(format->flag, ' ') && nbr >= 0) ? ' ' : '\0';
	sign = (ft_haschar(format->flag, '+') && nbr >= 0) ? '+' : sign;
	sign = (nbr < 0) ? '-' : sign;
	nbr = (nbr < 0) ? nbr * -1 : nbr;
	if (format->conversion == 'g' || format->conversion == 'G')
		convert_g_to_ef(format, nbr, (format->precision < 0));
	else if (format->precision < 0)
		format->precision = 6;
	show_dot = (ft_haschar(format->flag, '#') || format->precision > 0) ? 1 : 0; //'#' for %gG?
	format->min_wd -= (format->precision + show_dot + (sign != '\0'));
	format->min_wd -= (format->conversion == 'f' || format->conversion == 'F')
		? ft_digits((unsigned long long)nbr, 10) : 5;
	if (fill == '0' && sign)
		ft_putchar(sign);
	while (!(ft_haschar(format->flag, '-')) && format->min_wd-- > 0 && ++(*ct))
		ft_putchar(fill);
	if (fill == ' ' && sign && ++(*ct))
		ft_putchar(sign);
	nbr_processes(format, ct, show_dot, nbr);
}
