/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:37:05 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/09 15:49:14 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_neg_and_mod_nbr(unsigned long long *nbr, t_format *format)
{
	int neg;

	neg = 1;
	if (ft_strcmp(format->len, "hh") == 0 && (signed char)(*nbr) < 0)
		*nbr = (signed char)(*nbr) * -1;
	else if (ft_strcmp(format->len, "h") == 0 && (short)(*nbr) < 0)
		*nbr = (short)(*nbr) * -1;
	else if ((ft_strcmp(format->len, "l") == 0
				|| ft_strcmp(format->len, "z") == 0) && (long)(*nbr) < 0)
		*nbr = (long)(*nbr) * -1;
	else if (ft_strcmp(format->len, "ll") == 0 && (long long)(*nbr) < 0)
		*nbr = (long long)(*nbr) * -1;
	else if (ft_strcmp(format->len, "j") == 0 && (intmax_t)(*nbr) < 0)
		*nbr = (intmax_t)(*nbr) * -1;
	else if (ft_strcmp(format->len, "\0") == 0 && (int)(*nbr) < 0)
		*nbr = (int)(*nbr) * -1;
	else
		neg = 0;
	*nbr = process_nbr(*nbr, format);
	return (neg);
}

static void		set_sign(char *sign, int neg, t_format *format)
{
	if (neg)
		*sign = '-';
	else
	{
		if (ft_haschar(format->flag, ' '))
			*sign = ' ';
		if (ft_haschar(format->flag, '+'))
			*sign = '+';
	}
}

static char		processes(t_format *format, unsigned long long *nbr,
							int *count, char *sign)
{
	int		neg;
	char	fill;
//	int		digits;

	fill = ' ';
	neg = is_neg_and_mod_nbr(nbr, format);
	set_sign(sign, neg, format);
	format->min_w -= (ft_digits(*nbr, 10) + (*sign != '\0'));
	*count += (ft_digits(*nbr, 10) + (*sign != '\0'));
//	digits = ft_digits(*nbr, 10);
//	*count += (digits + (*sign != '\0'));
	if (*nbr >= 1000 && ft_haschar(format->flag, '\''))
	{	
////		*count += digits / 3;
		*count += ft_digits(*nbr, 10) / 3;
		format->min_w -= ft_digits(*nbr, 10) / 3;
	}
//	format->min_w -= *count;
	if (format->precision >= 0)
	{
		if ((format->precision -= ft_digits(*nbr, 10)) > 0)
			format->min_w -= format->precision;
	}
	else if (ft_haschar(format->flag, '0') && !ft_haschar(format->flag, '-'))
	{
		fill = '0';
		if (*sign)
			ft_putchar(*sign);
	}
	return (fill);
}

void			convert_di(t_format *format, va_list ap, int *count)
{
	char				fill;
	unsigned long long	nbr;
	char				sign;
	int					zero_nbr_precision;

	fill = ' ';
	sign = '\0';
	nbr = va_arg(ap, unsigned long long);
	zero_nbr_precision = (format->precision == 0 && nbr == 0) ? 1 : 0;
	if (!zero_nbr_precision)
		fill = processes(format, &nbr, count, &sign);
	while (!(ft_haschar(format->flag, '-')) && format->min_w-- > 0
			&& ++(*count))
		ft_putchar(fill);
	if (fill == ' ' && sign)
		ft_putchar(sign);
	while (format->precision-- > 0 && ++(*count))
		ft_putchar('0');
	if (!zero_nbr_precision)
		ft_putnbr_base(nbr, 10, 0, ft_haschar(format->flag, '\''));
	while (ft_haschar(format->flag, '-') && format->min_w-- > 0
			&& ++(*count))
		ft_putchar(fill);
}
