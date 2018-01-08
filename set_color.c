/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 23:26:38 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/08 14:29:50 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		match_light_colors(const char *color)
{
	if (ft_strcmp(color, "light red") == 0)
		ft_putstr("\x1B[91m");
	else if (ft_strcmp(color, "light green") == 0)
		ft_putstr("\x1B[92m");
	else if (ft_strcmp(color, "light yellow") == 0)
		ft_putstr("\x1B[93m");
	else if (ft_strcmp(color, "light blue") == 0)
		ft_putstr("\x1B[94m");
	else if (ft_strcmp(color, "light magenta") == 0)
		ft_putstr("\x1B[95m");
	else if (ft_strcmp(color, "light cyan") == 0)
		ft_putstr("\x1B[96m");
	else if (ft_strcmp(color, "white") == 0)
		ft_putstr("\x1B[97m");
}

static void		match_colors(const char *color)
{
	if (ft_strcmp(color, "eoc") == 0)
		ft_putstr("\x1B[39m");
	else if (ft_strcmp(color, "black") == 0)
		ft_putstr("\x1B[30m");
	else if (ft_strcmp(color, "red") == 0)
		ft_putstr("\x1B[31m");
	else if (ft_strcmp(color, "green") == 0)
		ft_putstr("\x1B[32m");
	else if (ft_strcmp(color, "yellow") == 0)
		ft_putstr("\x1B[33m");
	else if (ft_strcmp(color, "blue") == 0)
		ft_putstr("\x1B[34m");
	else if (ft_strcmp(color, "magenta") == 0)
		ft_putstr("\x1B[35m");
	else if (ft_strcmp(color, "cyan") == 0)
		ft_putstr("\x1B[36m");
	else if (ft_strcmp(color, "white") == 0)
		ft_putstr("\x1B[97m");
	else if (ft_strcmp(color, "gray") == 0)
		ft_putstr("\x1B[90m");
	else
		match_light_colors(color);
}

void			set_color(const char *s, int *i)
{
	int		tmp;
	int		j;
	char	color[14];

	tmp = *i + 1;
	j = 0;
	color[13] = '\0';
	while (s[tmp] != '}' && s[tmp] != '\0')
	{
		if (j < 13)
		{
			color[j] = s[tmp];
			j++;
		}
		tmp++;
	}
	if (j < 13)
		color[j] = '\0';
	if (s[tmp] == '}')
	{
		match_colors(color);
		(*i) = tmp + 1;
	}
	else if (s[(*i)++])
		ft_putchar('{');
}
