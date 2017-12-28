/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:10:38 by yazhu             #+#    #+#             */
/*   Updated: 2017/12/27 19:14:59 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	convert_p_percent(t_format *format, va_list ap, int *count)
{
	unsigned long long	nbr;
	int					left_adjusted;

	if (format->conversion == 'p')
	{
		nbr = va_arg(ap, unsigned long long);
		*count += (ft_digits(nbr, 16) + 2);
		format->min_width -= (ft_digits(nbr, 16) + 2);
	}
	else
		format->min_width--;
	left_adjusted = ft_haschar(format->flag, '-');
	while(!left_adjusted && format->min_width-- > 0 && ++(*count))
		ft_putchar(' ');
	if (format->conversion == 'p')
	{
		ft_putstr("0x");
		ft_putnbr_base(nbr, 16, 0);
	}
	else if (++(*count))
		ft_putchar('%');
	while (left_adjusted && format->min_width-- > 0 && ++(*count))
		ft_putchar(' ');
}
