/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:01:53 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/09 20:03:06 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwstr(const wchar_t *s)
{
	size_t count;

	count = 0;
	if (s)
	{
		while (s[count] != '\0')
		{
			ft_putwchar(s[count]);
			count++;
		}
	}
}
