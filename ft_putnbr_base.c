/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:40:09 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/09 10:39:44 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long n, int base, int cap, int delimit)
{
	if (delimit == 0)
		delimit -= ft_digits(n, base);
	if (n / base > 0)
		ft_putnbr_base(n / base, base, cap, delimit + 1);
	if (cap)
		ft_putchar(("0123456789ABCDEF")[n % base]);
	else if (base == 10 && delimit)
	{
		ft_putchar(("0123456789")[n % 10]);
		ft_putstr(((delimit - 1) % 3 == 0 && delimit > 1) ? "," : "");
	}
	else
		ft_putchar(("0123456789abcdef")[n % base]);
}
