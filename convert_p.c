/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 20:42:14 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/06 22:10:35 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_p(t_format *format, va_list ap, int *count)
{
	unsigned long long	nbr;
	int					left_adjusted;

	nbr = va_arg(ap, unsigned long long);
	*count += (ft_digits(nbr, 16) + 2);
	format->min_w -= (ft_digits(nbr, 16) + 2);
	left_adjusted = ft_haschar(format->flag, '-');
	while (!left_adjusted && format->min_w-- > 0 && ++(*count))
		ft_putchar(' ');
	ft_putstr("0x");
	ft_putnbr_base(nbr, 16, 0);
	while (left_adjusted && format->min_w-- > 0 && ++(*count))
		ft_putchar(' ');
}
