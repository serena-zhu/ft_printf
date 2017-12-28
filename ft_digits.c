/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:20:06 by yazhu             #+#    #+#             */
/*   Updated: 2017/12/22 18:23:37 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_digits(unsigned long long nbr, int base)
{
	int digits;

	digits = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		digits++;
		nbr /= base;
	}
	return (digits);
}
