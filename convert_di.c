/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:37:05 by yazhu             #+#    #+#             */
/*   Updated: 2017/12/28 21:41:15 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_neg_and_mod_nbr(unsigned long long *nbr, t_format *format)
{
	int neg;

	neg = 1;
//	*nbr = process_nbr(*nbr, format);
	if (ft_strcmp(format->length, "hh") == 0 && (signed char)(*nbr) < 0)
		*nbr = (signed char)(*nbr) * -1;
	else  if (ft_strcmp(format->length, "h") == 0 && (short)(*nbr) < 0)
		*nbr = (short)(*nbr) * -1;
	else if (ft_strcmp(format->length, "l") == 0 && (long)(*nbr) < 0)
		*nbr = (long)(*nbr) * -1;
	else if (ft_strcmp(format->length, "ll") == 0 && (long long)(*nbr))
		*nbr = (long long)(*nbr) * -1;
	else if (ft_strcmp(format->length, "j") == 0 && (intmax_t)(*nbr) < 0)
		*nbr = (intmax_t)(*nbr) * -1;
//	else if (ft_strcmp(format->length, "z") == 0)
//		neg = 0;
	else if ((int)(*nbr) < 0)
		*nbr = (int)(*nbr) * -1;
	else
		neg = 0;
	*nbr = process_nbr(*nbr, format); // put outside of else statement?
	return (neg);
}

static void		set_sign(char *sign, int neg, t_format *format)
{
	*sign = '\0';
	if (neg)
	{
		*sign = '-';
		format->min_width--;
	}
	else
	{
		if (ft_haschar(format->flag, ' '))
			*sign = ' ';
		if (ft_haschar(format->flag, '+'))
			*sign = '+';
	}
}

void	convert_di(t_format *format, va_list ap, int *count)
{
	char				fill;
	unsigned long long	nbr;
	char				sign;
	int					neg;

	fill = ' ';
	nbr = va_arg(ap, unsigned long long);
	neg = is_neg_and_mod_nbr(&nbr, format);
	set_sign(&sign, neg, format);
	format->min_width -= (ft_digits(nbr, 10) + (sign == ' ' ||  sign == '+'));
	*count += (ft_digits(nbr, 10) + (sign == ' ' || sign == '+' || neg));
	if (format->precision > 0)
	{
		if ((format->precision -= ft_digits(nbr, 10)) > 0)
			format->min_width -= format->precision;
	}
	else if (ft_haschar(format->flag, '0') && !ft_haschar(format->flag, '-'))
	{
		fill = '0';
		if (sign)
			ft_putchar(sign);
	}
	while (!(ft_haschar(format->flag, '-')) && format->min_width-- > 0 && ++(*count))
		ft_putchar(fill);
	if (fill == ' ' && sign)
		ft_putchar(sign);
	while (format->precision-- > 0 && ++(*count))
		ft_putchar('0');
	ft_putnbr_base(nbr, 10, 0);
	while (ft_haschar(format->flag, '-') && format->min_width-- > 0 && ++(*count)) 
		ft_putchar(fill);
}
