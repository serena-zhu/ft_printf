/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 23:26:38 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/09 18:04:57 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		match_light_colors(const char *color, int *reset_text_color)
{
	if (ft_strcmp(color, "light red") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[91m");
	else if (ft_strcmp(color, "light green") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[92m");
	else if (ft_strcmp(color, "light yellow") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[93m");
	else if (ft_strcmp(color, "light blue") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[94m");
	else if (ft_strcmp(color, "light magenta") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[95m");
	else if (ft_strcmp(color, "light cyan") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[96m");
	else if (ft_strcmp(color, "white") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[97m");
	return (*reset_text_color);
}

static int		match_colors(const char *color, int *reset_text_color)
{
	if (ft_strcmp(color, "black") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[30m");
	else if (ft_strcmp(color, "red") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[31m");
	else if (ft_strcmp(color, "green") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[32m");
	else if (ft_strcmp(color, "yellow") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[33m");
	else if (ft_strcmp(color, "blue") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[34m");
	else if (ft_strcmp(color, "magenta") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[35m");
	else if (ft_strcmp(color, "cyan") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[36m");
	else if (ft_strcmp(color, "white") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[97m");
	else if (ft_strcmp(color, "gray") == 0 && (*reset_text_color = 1))
		ft_putstr("\x1B[90m");
	return (match_light_colors(color, reset_text_color));
}

void			set_color(const char *s, int *i, int *reset_text_color,
																int *count)
{
	int		tmp;
	int		j;
	char	color[14];

	tmp = *i + 1;
	j = 0;
	color[13] = '\0';
	while (s[tmp] != '}' && s[tmp] != '\0')
	{
		if (j < 13 && ++j)
			color[j - 1] = s[tmp];
		tmp++;
	}
	color[j] = (j < 13) ? '\0' : color[j];
	if (s[tmp] == '}' && ft_strcmp(color, "eoc") == 0)
	{
		ft_putstr("\x1B[39m");
		*i = tmp + 1;
	}
	else if (s[tmp] == '}' && match_colors(color, reset_text_color))
		*i = tmp + 1;
	else if (s[(*i)++] && ++(*count))
		ft_putchar('{');
}
