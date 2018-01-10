/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:12:59 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/09 21:29:38 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conversion(t_format *format, va_list ap, int *count)
{
	char				c;
	int					has_l_mod;

	c = format->conv;
	has_l_mod = (ft_strcmp(format->len, "l") == 0);
	if ((c == 's' && has_l_mod) || c == 'S')
		convert_ws(format, ap, count);
	else if (c == 's')
		convert_s(format, ap, count, 0);
	else if (c == 'd' || c == 'D' || c == 'i')
		convert_di(format, ap, count);
	else if (c == 'x' || c == 'X' || c == 'o' || c == 'O'
			|| c == 'u' || c == 'U')
		convert_xou(format, ap, count);
	else if (c == 'c' || c == 'C' || c == '%')
		convert_c(format, ap, count, has_l_mod);
	else if (c == 'p')
		convert_p(format, ap, count);
	else if (c == 'n')
		*(va_arg(ap, unsigned long long *)) = *count;
	else if (c == 'f' || c == 'F' || c == 'e' || c == 'E'
			|| c == 'g' || c == 'G')
		convert_efg(format, ap, count);
	return (0);
}
