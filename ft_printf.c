/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:07:42 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/05 11:54:28 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		conversion(t_format *format, va_list ap, int *count)
{
	char				c;
	int					has_l_mod;

	c = format->conversion;
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
		*(va_arg(ap, int *)) = *count; //need to incorporate length modifiers?
	else if (c == 'f' || c == 'F' || c == 'e' || c == 'E')
		convert_ef(format, ap, count);
//	else if (c == 'e' || c == 'E')
//		convert_e(format, ap, count);
	return (0);
}

static void		occupy_conversion(const char *s, int *i, t_format *format)
{
	char c;

	c = s[*i];
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
			|| c == 'X' || c == 'c' || c == 'C' || c == '%' || c == 'n'
			|| c == 'f' || c == 'F' || c == 'e' || c == 'E')
		format->conversion = s[(*i)++];
	else
	{
		format->conversion = '\0';
		if ((s[*i] == 'l' && format->len[0] == 'l')
				|| (s[*i] == 'h' && format->len[0] == 'h'))
		{
			(*i)++;
			while (s[*i] != '\0')
				(*i)++;
		}
	}
}

/*
**	order of precedence if >1 length modifier is provided:
**  [l, ll, j, t, z] then [h] then [hh]
*/

static void		occupy_len(const char *s, int *i, t_format *format, int replace)
{
	if (replace == 0)
	{
		format->len[0] = (s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'j'
				|| s[*i] == 'z'/* || s[*i] == 'L'*/) ? s[(*i)++] : '\0';
		format->len[1] = ((s[*i - 1] == 'h' && s[*i] == 'h')
				|| (s[*i - 1] == 'l' && s[*i] == 'l')) ? s[(*i)++] : '\0';
		format->len[2] = '\0';
	}
	else
	{
		if ((s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'j' || s[*i] == 'z'
				||/* s[*i] == 'L'*/) && (*i)++)
			format->len[0] = (!(format->len[0]) || format->len[1] == 'h'
				|| (format->len[0] == 'h' && s[(*i) - 1] != 'h'))
				? s[(*i) - 1] : format->len[0];
		format->len[1] = ((s[(*i) - 1] == 'h' && s[*i] == 'h')
				|| (s[(*i) - 1] == 'l' && s[*i] == 'l'))
				? s[(*i)++] : format->len[1];
	}
}

static void		occupy_format(const char *s, int *i, t_format *format, va_list ap)
{
	int j;

	j = 0;
	occupy_len(s, i, format, 0);
	while (s[*i] == '#' || s[*i] == '0' || s[*i] == '-' || s[*i] == '+'
			|| s[*i] == ' ')
		format->flag[j++] = s[(*i)++];
	format->min_wd = (s[*i] >= '0' && s[*i] <= '9') ? ft_atoi(&s[*i]) : -1;
	while (s[*i] >= '0' && s[*i] <= '9')
		(*i)++;
	format->min_wd = (s[*i] == '*' && (*i)++) ? va_arg(ap, int) : format->min_wd;
	while (s[*i] == '#' || s[*i] == '0' || s[*i] == '-' || s[*i] == '+'
			|| s[*i] == ' ')
		format->flag[j++] = s[(*i)++];
	while (j < 5)
		format->flag[j++] = '\0';
	format->precision = (s[*i] == '.') ? 0 : -1;
	format->precision = (s[*i] == '.' && s[++(*i)] >= '0' && s[*i] <= '9')
						? ft_atoi(&s[*i]) : format->precision;
	while (s[*i] >= '0' && s[*i] <= '9')
		(*i)++;
	occupy_len(s, i, format, 1);
	occupy_conversion(s, i, format);
}

int				ft_printf(const char *s, ...)
{
	int			i;
	int			count;
	va_list		ap;
	t_format	format;

	count = 0;
	va_start(ap, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			occupy_format(s, &i, &format, ap);
			if (format.conversion == 'D' || format.conversion == 'O'
					|| format.conversion == 'U' || format.conversion == 'S'
					|| format.conversion == 'C')
				format.len[0] = 'l';
			conversion(&format, ap, &count);
		}
		else
			count += write(1, &s[i++], 1);
	}
	va_end(ap);
	return (count);
}
