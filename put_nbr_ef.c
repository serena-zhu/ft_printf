/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_ef.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 20:41:07 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/09 22:39:33 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_nbr_ef(t_format *format, long double nbr, int move_dot)
{
	int		put_nbr_ct;
	int		show_dot;
	int		flag;
	char	exp;

	put_nbr_ct = format->prec + 1;
	exp = (nbr >= 1 || nbr == 0) ? '+' : '-';
	nbr += (format->prec >= 0) ? 0.5 / ft_power(10, format->prec) : 0;
	show_dot = (ft_haschar(format->flag, '#') || format->prec > 0) ? 1 : 0;
	flag = 0;
	while (put_nbr_ct-- > 0)
	{
		ft_putnbr_base(nbr, 10, 0, (!flag && ft_haschar(format->flag, '\'')));
		nbr = (nbr - (unsigned long long)nbr) * 10;
		if (!flag && show_dot && (flag = 1))
			ft_putchar('.');
	}
	if (format->conv == 'e' || format->conv == 'E')
	{
		ft_putchar(format->conv);
		ft_putchar(exp);
		if (move_dot < 10)
			ft_putchar('0');
		ft_putnbr_base(move_dot, 10, 0, 0);
	}
}
