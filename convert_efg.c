/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_efg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:23:22 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/09 22:44:40 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		convert_g_to_ef(t_format *format, int move_dot, int less_than_1)
{
	format->prec = (format->prec == 0) ? 1 : format->prec;
	if (!less_than_1)
	{
		format->conv += (move_dot >= format->prec)
								? ('e' - 'g') : ('f' - 'g');
		if (format->conv == 'f' || format->conv == 'F')
			format->prec -= (move_dot + 1);
	}
	else
		format->conv += (move_dot > 4) ? ('e' - 'g') : ('f' - 'g');
	if (format->conv == 'e' || format->conv == 'E')
		format->prec -= 1;
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
		if (format->conv == 'g' || format->conv == 'G')
		{
			convert_g_to_ef(format, *move_dot, 0);
			*nbr = (format->conv == 'f' || format->conv == 'F')
					? tmp : *nbr;
		}
	}
	else if (*nbr != 0)
	{
		while (tmp < 1 && ++(*move_dot))
			tmp *= 10;
		if (format->conv == 'g' || format->conv == 'G')
		{
			convert_g_to_ef(format, *move_dot, 1);
			*nbr = (format->conv == 'e' || format->conv == 'E')
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
	int			i;

	move_dot = 0;
	tmp = *nbr;
	is_g = (format->conv == 'g' || format->conv == 'G') ? 1 : 0;
	i = 0;
	if (format->conv != 'f' && format->conv != 'F')
		shift_decimal(format, nbr, &move_dot);
	if (is_g)
	{
		while (i++ < format->prec)
			tmp *= 10;
		while (((int)tmp % 10 == 0 || ((int)tmp % 10 == 9
						&& (int)(tmp / 10) % 10 == 9)) && format->prec--)
			tmp /= 10;
		if ((int)tmp % 10 == 9 && (int)(tmp / 10) % 10 == 1)
			format->prec--;
		format->prec = (format->prec < 0) ? 0 : format->prec;
	}
	if (ft_haschar(format->flag, '\'') && *nbr >= 1000)
		*ct += (ft_digits(*nbr, 10) / 3);
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

	format->prec = (format->prec < 0) ? 6 : format->prec;
	nbr = (ft_strcmp(format->len, "L") == 0)
			? va_arg(ap, long double) : va_arg(ap, double);
	set_fill_sign(format, &nbr, &fill, &sign);
	move_dot = nbr_processes(format, ct, &nbr);
	show_dot = (ft_haschar(format->flag, '#') || format->prec > 0);
	*ct += ft_digits(nbr, 10) + format->prec + show_dot + (sign != '\0');
	if (format->conv == 'e' || format->conv == 'E')
		*ct += (2 + ft_digits(move_dot, 10) + (move_dot < 10));
	format->min_w -= *ct;
	if (fill == '0' && sign)
		ft_putchar(sign);
	while (!(ft_haschar(format->flag, '-')) && format->min_w-- > 0 && ++(*ct))
		ft_putchar(fill);
	if (fill == ' ' && sign)
		ft_putchar(sign);
	put_nbr_ef(format, nbr, move_dot);
	while ((ft_haschar(format->flag, '-') && format->min_w-- > 0 && ++(*ct)))
		ft_putchar(fill);
}
