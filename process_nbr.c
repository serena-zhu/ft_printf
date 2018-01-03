/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 15:03:40 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/02 22:18:27 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	process_nbr(unsigned long long nbr, t_format *format)
{
	if (ft_strcmp(format->len, "hh") == 0)
		return ((unsigned char)nbr);
	else if (ft_strcmp(format->len, "h") == 0)
		return ((unsigned short)nbr);
	else if (ft_strcmp(format->len, "l") == 0)
		return ((unsigned long)nbr);
	else if (ft_strcmp(format->len, "ll") == 0)
		return ((unsigned long long)nbr);
	else if (ft_strcmp(format->len, "j") == 0)
		return ((uintmax_t)nbr);
	else if (ft_strcmp(format->len, "z") == 0)
		return ((size_t)nbr);
	else
		return ((unsigned int)nbr);
}
