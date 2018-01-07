/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ef.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:28:15 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/06 18:33:01 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //delete me!!
static void		put_fnbr(t_format *format, int *ct, long double nbr, int is_g)
{
	int			put_nbr_ct;
	long double	tmp;
	int			flag;
	int			show_dot;

	flag = 0;
	tmp = nbr * ft_power(10, format->precision);
/*	if ((int)(tmp * 10) % 10 >= 5)
	{
		printf("nbr is %Lf, tmp is %Lf and tmp * 10 mod 10 is %d\n", nbr, tmp, (int)(tmp *10) % 10);
		nbr += 0.5 / ft_power(10, format->precision);
		printf("nbr is now %Lf\n", nbr);
	}
*/	if (is_g) //this gets rid of trailing zeros
	{
		while (((int)tmp % 10 == 0 || ((int)tmp % 10 == 9
						&& (int)(tmp / 10) % 10 == 9)) && format->precision--)
			tmp /= 10;
		if ((int)tmp % 10 == 9 && (int)(tmp / 10) % 10 == 1)
			format->precision--;
		format->precision = (format->precision < 0) ? 0 : format->precision;
	}
	tmp = nbr * ft_power(10, format->precision);
//	if ((int)(tmp * 10) % 10 >= 0)
//	{
//		printf("nbr is %Lf, tmp is %Lf and tmp * 10 is %Lf mod 10 is %d\n", nbr, tmp, tmp * 10, (int)(tmp * 10) % 10);
//		printf("precision is %d and adding this to nbr %f\n", format->precision, 0.5/ft_power(10, format->precision));
		if (format->precision >= 0)
			nbr += 0.5 / ft_power(10, format->precision);
//		printf("nbr is now %Lf\n", nbr);
//	}
	*ct += ft_digits((unsigned long long)nbr, 10) - 1;
	put_nbr_ct = format->precision + 1;
	show_dot = (ft_haschar(format->flag, '#') || format->precision > 0) ? 1 : 0;
	while (put_nbr_ct-- > 0 && ++(*ct))
	{
		ft_putnbr_base(nbr, 10, 0);
		nbr = (nbr - (unsigned long long)nbr) * 10;
		if (!flag && show_dot && ++(*ct) && (flag = 1))
			ft_putchar('.');
	}
}

static void		put_exp_for_e(t_format *format, int move_dot, char e, int *ct)
{
	ft_putchar(format->conversion);
	ft_putchar(e);
	if (move_dot < 10)
		ft_putchar('0');
	ft_putnbr_base(move_dot, 10, 0);
	*ct += (2 + ft_digits(move_dot, 10) + (move_dot < 10));
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
//		else
//			format->precision -= move_dot - 1;
	}
}

static void		nbr_processes(t_format *format, int *ct, long double nbr)
{
	int			move_dot;
	char		e;
	long double	tmp;
	int			is_g;

	move_dot = 0;
	e = (nbr >= 1 || nbr == 0) ? '+' : '-';
	tmp = nbr;
	is_g = (format->conversion == 'g' || format->conversion == 'G') ? 1 : 0;
	if (format->conversion != 'f' && format->conversion != 'F')
	{
		if (nbr >= 1 || nbr == 0)
		{
			while (nbr >= 10 && ++move_dot)
				nbr /= 10;
			if (format->conversion == 'g' || format->conversion == 'G')
			{
				convert_g_to_ef(format, move_dot, 0);
				nbr = (format->conversion == 'f' || format->conversion == 'F') ? tmp : nbr;
			}
		}
		else if (nbr != 0)
		{
			while (tmp < 1 && ++move_dot)
				tmp *= 10;
			if (format->conversion == 'g' || format->conversion == 'G')
			{
				convert_g_to_ef(format, move_dot, 1);
				nbr = (format->conversion == 'e' || format->conversion == 'E') ? tmp : nbr;
			}
		}
	}
	put_fnbr(format, ct, nbr, is_g);
	if (format->conversion == 'e' || format->conversion == 'E')
		put_exp_for_e(format, move_dot, e, ct);
}

//what about negative 0?

void			convert_ef(t_format *format, va_list ap, int *ct)
{
	long double		nbr;
	char			fill;
	char			sign;
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
//	if (format->conversion == 'g' || format->conversion == 'G')
//		convert_g_to_ef(format, nbr);//, (format->precision < 0));
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
	nbr_processes(format, ct, nbr); //what about printing remaining things for - flag?
}
