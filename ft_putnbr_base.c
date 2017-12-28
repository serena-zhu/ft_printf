/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:40:09 by yazhu             #+#    #+#             */
/*   Updated: 2017/12/23 13:32:57 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long n, int base, int cap)
{
	if (n / base > 0)
		ft_putnbr_base(n / base, base, cap);
	if (cap)
		ft_putchar(("0123456789ABCDEF")[n % base]);
	else
		ft_putchar(("0123456789abcdef")[n % base]);	
}
