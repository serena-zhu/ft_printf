/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:31:06 by yazhu             #+#    #+#             */
/*   Updated: 2017/12/27 17:32:43 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str);

void				ft_putchar(char c);
void				ft_putstr(char const *s);

#endif
