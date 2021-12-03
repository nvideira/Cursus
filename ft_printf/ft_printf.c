/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:46:41 by nvideira          #+#    #+#             */
/*   Updated: 2021/12/03 18:00:11 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		char_print;
	size_t	index;

	index = 0;
	va_start(args, s);
	while (s[index])
	{
		if (s[index] != '%')
		{
			ft_putchar_fd(s[index], 1);
			index++;
			char_print++;
		}
		else
		{
			if (check_type(s[i + 1]))
				next_arg(s[i + 1], &char_print, args);
		}
	}
	va_end(args);
	return (char_print);
}
