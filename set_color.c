/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 23:26:38 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/07 00:00:02 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //delete me!!!
void	set_color(const char *s, int *i)
{
	int tmp;
	int	j;
	char color[8];

	tmp = *i + 1; //only set i to this if there is a closing bracket
	j = 0;
	color[7] = '\0';
	while (s[tmp] != '}' && s[tmp] != '\0')
	{
		if (j < 7)
		{
			color[j] = s[tmp];
			j++;
		}
		tmp++;
	}
	if (j < 7)
		color[j] = '\0';
	if (s[tmp] == '}')
	{
		if (ft_strcmp(color, "eoc") == 0)
			ft_putstr("\x1B[39m");
		else if (ft_strcmp(color, "eobc") == 0)
			ft_putstr("\x1B[49m");
		else if (ft_strcmp(color, "red") == 0)
			ft_putstr("\x1B[31m");
		(*i) = tmp + 1; //this will ignore any { } input with colors not supported... do we want that?
	}
}
