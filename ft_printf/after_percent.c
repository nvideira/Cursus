/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:27:30 by nvideira          #+#    #+#             */
/*   Updated: 2021/12/07 21:29:02 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

void	next_arg(char c, int *char_print, va_list args)
{
	if (c == 'c')
		*char_print += ft_putchar_fd(va_arg(args, char), 1);
	if (c == 's')
		*char_print += ft_putstr_fd(va_arg(args, char *), 1);
	if (c == 'p')
		*char_print += ;
	if (c == 'd')
		*char_print += ft_putnbr_fd(va_arg(args, int), 1, 0);
	if (c == 'i')
		*char_print += ;
	if (c == 'u')
		*char_print += ft_putunsnbr_fd(va_arg(args, unsigned int), 1);
	if (c == 'x')
		*char_print += ;
	if (c == 'X')
		*char_print += ;
	if (c == '%')
		*char_print += ;
}
