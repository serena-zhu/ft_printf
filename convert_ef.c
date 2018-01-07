/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ef.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:28:15 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/06 20:20:40 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //delete me!!!
static void		put_nbr(t_format *format, long double nbr, int move_dot)
{
	int		put_nbr_ct;
	int		show_dot;
	int		flag;
	char	exp;

	put_nbr_ct = format->precision + 1;
	nbr += (format->precision >= 0) ? 0.5 / ft_power(10, format->precision) : 0;	
//	*ct += ft_digits((unsigned long long)nbr, 10) - 1;
	show_dot = (ft_haschar(format->flag, '#') || format->precision > 0) ? 1 : 0;
	flag = 0;
	exp = (nbr >= 1 || nbr == 0) ? '+' : '-';
	while (put_nbr_ct-- > 0) //need to get rid of count in entire function
	{
		ft_putnbr_base(nbr, 10, 0);
		nbr = (nbr - (unsigned long long)nbr) * 10;
		if (!flag && show_dot && (flag = 1))
			ft_putchar('.');
	}
	if (format->conversion == 'e' || format->conversion == 'E')
	{
		ft_putchar(format->conversion);
		ft_putchar(exp);
		if (move_dot < 10)
			ft_putchar('0');
		ft_putnbr_base(move_dot, 10, 0);
//		*ct += (2 + ft_digits(move_dot, 10) + (move_dot < 10));
	}
}

static void		convert_g_to_ef(t_format *format, int move_dot, int less_than_1)
{
	format->precision = (format->precision == 0) ? 1 : format->precision;
	if (!less_than_1)
	{
		format->conversion += (move_dot >= format->precision)
								? ('e' - 'g') : ('f' - 'g');
		if (format->conversion == 'e' || format->conversion == 'E')
			format->precision -= 1;
		else
			format->precision -= (move_dot + 1);
	}
	else
	{
		format->conversion += (move_dot > 4) ? ('e' - 'g') : ('f' - 'g');
		if (format->conversion == 'e' || format->conversion == 'E')
			format->precision -= 1;
	}
}

static int		nbr_processes(t_format *format, int *ct, long double *nbr)//, int print)
{
	int			move_dot;
	char		e;
	long double	tmp;
	int			is_g;

	move_dot = 0;
	e = (*nbr >= 1 || *nbr == 0) ? '+' : '-';
	tmp = *nbr;
	is_g = (format->conversion == 'g' || format->conversion == 'G') ? 1 : 0;
	if (format->conversion != 'f' && format->conversion != 'F')
	{
		if (*nbr >= 1 || *nbr == 0)
		{
			while (*nbr >= 10 && ++move_dot)
				*nbr /= 10;
			if (format->conversion == 'g' || format->conversion == 'G')
			{
				convert_g_to_ef(format, move_dot, 0);
				*nbr = (format->conversion == 'f' || format->conversion == 'F') ? tmp : *nbr;
			}
		}
		else if (*nbr != 0)
		{
			while (tmp < 1 && ++move_dot)
				tmp *= 10;
			if (format->conversion == 'g' || format->conversion == 'G')
			{
				convert_g_to_ef(format, move_dot, 1);
				*nbr = (format->conversion == 'e' || format->conversion == 'E') ? tmp : *nbr;
			}
		}
	}
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

void			convert_ef(t_format *format, va_list ap, int *ct)
{
	long double		nbr;
	char			fill;
	char			sign;
	int				move_dot;
	int				show_dot;

	format->precision = (format->precision < 0) ? 6 : format->precision;
	fill = (ft_haschar(format->flag, '0') && !ft_haschar(format->flag, '-'))
			? '0' : ' ';
	nbr = (ft_strcmp(format->len, "L") == 0)
			? va_arg(ap, long double) : va_arg(ap, double);
	sign = (ft_haschar(format->flag, ' ') && nbr >= 0) ? ' ' : '\0';
	sign = (ft_haschar(format->flag, '+') && nbr >= 0) ? '+' : sign;
	sign = (nbr < 0) ? '-' : sign;
	nbr = (nbr < 0) ? nbr * -1 : nbr;
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
	put_nbr(format, nbr, move_dot);
	while ((ft_haschar(format->flag, '-') && format->min_wd-- > 0 && ++(*ct)))
		ft_putchar(fill);
}
