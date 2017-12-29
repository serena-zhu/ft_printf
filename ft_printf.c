/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:07:42 by yazhu             #+#    #+#             */
/*   Updated: 2017/12/28 20:34:28 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		conversion(t_format *format, va_list ap, int *count)
{
	char				c;
	int					has_l_mod;

	c = format->conversion;
	has_l_mod = (ft_strcmp(format->length, "l") == 0);
	if ((c == 's' && has_l_mod) || c == 'S')
		convert_ws(format, ap, count);
	else if (c == 's')
		convert_s(format, ap, count, 0);
	else if (c == 'd' || c == 'D' || c == 'i') 
		convert_di(format, ap, count);
	else if (c == 'x' || c == 'X' ||  c == 'o' || c == 'O' || c == 'u' || c == 'U')
		convert_xou(format, ap, count);
	else if (c == 'c' || c == 'C')
		convert_c(format, ap, count, has_l_mod);
	else if (c == 'p' || c == '%')
		convert_p_percent(format, ap, count);
	else
		return (-1);
	return (0);
}

static int		occupy_format(const char *s, int i, t_format *format)
{
	int j;

	j = 0;
	while (s[i] == '#' || s[i] == '0' || s[i] == '-' || s[i] == '+' || s[i] == ' ')
		format->flag[j++] = s[i++];
	while (j < 5)
		format->flag[j++] = '\0';
	format->min_width = (s[i] >= '0' && s[i] <= '9') ? ft_atoi(&s[i]) : -1;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	format->precision = (s[i] == '.' && s[++i] >= '0' && s[i] <= '9') 
						? ft_atoi(&s[i]) : -1;
	while (s[i] >= '0' && s[i] <='9')
		i++;
	format->length[0] = (s[i] == 'h' || s[i] == 'l' || s[i] == 'j'
						|| s[i] == 'z') ? s[i++] : '\0';
	format->length[1] = ((s[i - 1] == 'h' && s[i] == 'h') 
						|| (s[i - 1] == 'l' && s[i] == 'l')) ? s[i++] : '\0';
	format->length[2] = '\0';
	format->conversion = (s[i] == 's' || s[i] == 'S' || s[i] == 'p' 
						|| s[i] == 'd' || s[i] == 'D' || s[i] == 'i' 
						|| s[i] == 'o' || s[i] == 'O' || s[i] == 'u'
						|| s[i] == 'U' || s[i] == 'x' || s[i] == 'X'
						|| s[i] == 'c' || s[i] == 'C' || s[i] == '%') ? s[i++] : '\0';
	return (i);
}

int		ft_printf(const char *s, ...)
{
	int			i;
	int			count;
	va_list		ap;
	t_format 	format;

	count = 0;
	va_start(ap, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i = occupy_format(s, ++i, &format);
			if (format.conversion == 'D' || format.conversion == 'O' 
					|| format.conversion == 'U' || format.conversion == 'S'
					|| format.conversion == 'C')
				format.length[0] = 'l';
			if (conversion(&format, ap, &count) < 0)
				return (-1);
		}
		else
			count += write(1, &s[i++] , 1);
	}
	va_end(ap);
	return (count);
}
