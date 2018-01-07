/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_efg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:23:22 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/06 21:31:07 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		convert_g_to_ef(t_format *format, int move_dot, int less_than_1)
{
	format->precision = (format->precision == 0) ? 1 : format->precision;
	if (!less_than_1)
	{
		format->conversion += (move_dot >= format->precision)
								? ('e' - 'g') : ('f' - 'g');
		if (format->conversion == 'f' || format->conversion == 'F')
			format->precision -= (move_dot + 1);
	}
	else
		format->conversion += (move_dot > 4) ? ('e' - 'g') : ('f' - 'g');
	if (format->conversion == 'e' || format->conversion == 'E')
		format->precision -= 1;
}

/*
** shift_decimal will move the decimal over for scientific notation as needed
*/

static void		shift_decimal(t_format *format, long double *nbr, int *move_dot)
{
	long double tmp;

	tmp = *nbr;
	if (*nbr >= 1 || *nbr == 0)
	{
		while (*nbr >= 10 && ++(*move_dot))
			*nbr /= 10;
		if (format->conversion == 'g' || format->conversion == 'G')
		{
			convert_g_to_ef(format, *move_dot, 0);
			*nbr = (format->conversion == 'f' || format->conversion == 'F')
					? tmp : *nbr;
		}
	}
	else if (*nbr != 0)
	{
		while (tmp < 1 && ++(*move_dot))
			tmp *= 10;
		if (format->conversion == 'g' || format->conversion == 'G')
		{
			convert_g_to_ef(format, *move_dot, 1);
			*nbr = (format->conversion == 'e' || format->conversion == 'E')
					? tmp : *nbr;
		}
	}
}

/*
** second part of nbr_processes will trim trailing zeros for gG conversions
*/

static int		nbr_processes(t_format *format, int *ct, long double *nbr)
{
	int			move_dot;
	long double	tmp;
	int			is_g;

	move_dot = 0;
	tmp = *nbr;
	is_g = (format->conversion == 'g' || format->conversion == 'G') ? 1 : 0;
	if (format->conversion != 'f' && format->conversion != 'F')
		shift_decimal(format, nbr, &move_dot);
	if (is_g)
	{
		tmp = *nbr * ft_power(10, format->precision);
		while (((int)tmp % 10 == 0 || ((int)tmp % 10 == 9
						&& (int)(tmp / 10) % 10 == 9)) && format->precision--)
			tmp /= 10;
		if ((int)tmp % 10 == 9 && (int)(tmp / 10) % 10 == 1)
			format->precision--;
		format->precision = (format->precision < 0) ? 0 : format->precision;
	}
	*ct += format->precision + 1;
	return (move_dot);
}

static void		set_fill_sign(t_format *format, long double *nbr,
													char *fill, char *sign)
{
	*fill = (ft_haschar(format->flag, '0') && !ft_haschar(format->flag, '-'))
				? '0' : ' ';
	*sign = (ft_haschar(format->flag, ' ') && nbr >= 0) ? ' ' : '\0';
	*sign = (ft_haschar(format->flag, '+') && nbr >= 0) ? '+' : *sign;
	*sign = (*nbr < 0) ? '-' : *sign;
	*nbr = (*nbr < 0) ? (*nbr) * -1 : *nbr;
}

void			convert_efg(t_format *format, va_list ap, int *ct)
{
	long double		nbr;
	char			fill;
	char			sign;
	int				move_dot;
	int				show_dot;

	format->precision = (format->precision < 0) ? 6 : format->precision;
	nbr = (ft_strcmp(format->len, "L") == 0)
			? va_arg(ap, long double) : va_arg(ap, double);
	set_fill_sign(format, &nbr, &fill, &sign);
	move_dot = nbr_processes(format, ct, &nbr);
	show_dot = (ft_haschar(format->flag, '#') || format->precision > 0);
	*ct = ft_digits((unsigned long long)nbr, 10) + format->precision + show_dot;
	if (format->conversion == 'e' || format->conversion == 'E')
		*ct += (2 + ft_digits(move_dot, 10) + (move_dot < 10));
	format->min_wd -= *ct;
	if (fill == '0' && sign && ++(*ct))
		ft_putchar(sign);
	while (!(ft_haschar(format->flag, '-')) && format->min_wd-- > 0 && ++(*ct))
		ft_putchar(fill);
	if (fill == ' ' && sign && ++(*ct))
		ft_putchar(sign);
	put_nbr_ef(format, nbr, move_dot);
	while ((ft_haschar(format->flag, '-') && format->min_wd-- > 0 && ++(*ct)))
		ft_putchar(fill);
}
