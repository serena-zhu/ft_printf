/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_ef.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 20:41:07 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/09 09:46:45 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_nbr_ef(t_format *format, long double nbr, int move_dot)
{
	int		put_nbr_ct;
	int		show_dot;
	int		flag;
	char	exp;

	put_nbr_ct = format->precision + 1;
	exp = (nbr >= 1 || nbr == 0) ? '+' : '-';
	nbr += (format->precision >= 0) ? 0.5 / ft_power(10, format->precision) : 0;
	show_dot = (ft_haschar(format->flag, '#') || format->precision > 0) ? 1 : 0;
	flag = 0;
	while (put_nbr_ct-- > 0)
	{
		ft_putnbr_base(nbr, 10, 0, 0);
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
		ft_putnbr_base(move_dot, 10, 0, 0);
	}
}
