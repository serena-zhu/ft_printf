/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_putnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 15:03:40 by yazhu             #+#    #+#             */
/*   Updated: 2017/12/23 16:32:11 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		process_putnbr(unsigned long long nbr, t_format *format, int base)
{
	int cap;

	cap = (format->conversion == 'X') ? 1 : 0;
	if (ft_strcmp(format->length, "hh") == 0)
		ft_putnbr_base((unsigned char)nbr, base, cap);
	else if (ft_strcmp(format->length, "h") == 0)
		ft_putnbr_base((unsigned short)nbr, base, cap);
	else if (ft_strcmp(format->length, "l") == 0)
		ft_putnbr_base((unsigned long)nbr, base, cap);
	else if (ft_strcmp(format->length, "ll") == 0)
		ft_putnbr_base((unsigned long long)nbr, base, cap);
	else if (ft_strcmp(format->length, "j") == 0)
		ft_putnbr_base((uintmax_t)nbr, base, cap);
	else if (ft_strcmp(format->length, "z") == 0)
		ft_putnbr_base((size_t)nbr, base, cap);
	else
		ft_putnbr_base((unsigned int)nbr, base, cap);
}
