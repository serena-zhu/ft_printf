/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:07:42 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/09 20:59:18 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		occupy_conversion(const char *s, int *i, t_format *format)
{
	char c;

	c = s[*i];
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
			|| c == 'X' || c == 'c' || c == 'C' || c == '%' || c == 'n'
			|| c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g'
			|| c == 'G')
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
	if (format->conversion == 'D' || format->conversion == 'O'
			|| format->conversion == 'U' || format->conversion == 'S'
			|| format->conversion == 'c')
		format->len[0] = 'l';
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
				|| s[*i] == 'z' || s[*i] == 'L') ? s[(*i)++] : '\0';
		format->len[1] = ((s[*i - 1] == 'h' && s[*i] == 'h')
				|| (s[*i - 1] == 'l' && s[*i] == 'l')) ? s[(*i)++] : '\0';
		format->len[2] = '\0';
	}
	else
	{
		if ((s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'j' || s[*i] == 'z'
				|| s[*i] == 'L') && (*i)++)
			format->len[0] = (!(format->len[0]) || format->len[1] == 'h'
				|| (format->len[0] == 'h' && s[(*i) - 1] != 'h'))
				? s[(*i) - 1] : format->len[0];
		format->len[1] = ((s[(*i) - 1] == 'h' && s[*i] == 'h')
				|| (s[(*i) - 1] == 'l' && s[*i] == 'l'))
				? s[(*i)++] : format->len[1];
	}
}

/*
**	set_w will use absolute value of user specified min_w
**	if the number provided by user is negative, a '-' flag is added
*/

static int		set_w(t_format *format, int *i, int *j, va_list ap)
{
	unsigned long long tmp;

	tmp = va_arg(ap, int);
	if ((int)tmp < 0)
	{
		tmp = (int)tmp * -1;
		format->flag[(*j)++] = '-';
	}
	(*i)++;
	return (tmp);
}

/*
** format->precision:
** set to -1 if there is no '.'
** set to 0 if there is a '.' but no number
*/

static void		occupy_format(const char *s, int *i, t_format *format,
																va_list ap)
{
	int j;

	j = 0;
	occupy_len(s, i, format, 0);
	while (s[*i] == '#' || s[*i] == '0' || s[*i] == '-' || s[*i] == '+'
			|| s[*i] == ' ' || s[*i] == '\'')
		format->flag[j++] = s[(*i)++];
	format->min_w = (s[*i] >= '0' && s[*i] <= '9') ? ft_atoi(&s[*i]) : -1;
	while (s[*i] >= '0' && s[*i] <= '9')
		(*i)++;
	format->min_w = (s[*i] == '*') ? set_w(format, i, &j, ap) : format->min_w;
	while (s[*i] == '#' || s[*i] == '0' || s[*i] == '-' || s[*i] == '+'
			|| s[*i] == ' ' || s[*i] == '\'')
		format->flag[j++] = s[(*i)++];
	while (j < 6)
		format->flag[j++] = '\0';
	format->precision = (s[*i] == '.') ? 0 : -1;
	format->precision = (s[*i] == '.' && s[++(*i)] >= '0' && s[*i] <= '9')
						? ft_atoi(&s[*i]) : format->precision;
	format->precision = (s[*i] == '*' && ++(*i))
						? va_arg(ap, int) : format->precision;
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
	int			reset_text_color;

	count = 0;
	reset_text_color = 0;
	i = 0;
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && ++i)
		{
			occupy_format(s, &i, &format, ap);
			conversion(&format, ap, &count);
		}
		else if (s[i] == '{')
			set_color(s, &i, &reset_text_color, &count);
		else
			count += write(1, &s[i++], 1);
	}
	va_end(ap);
	ft_putstr((reset_text_color) ? "\x1B[39m" : "");
	return (count);
}
