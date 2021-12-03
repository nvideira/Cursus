/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:27:30 by nvideira          #+#    #+#             */
/*   Updated: 2021/12/03 18:00:10 by nvideira         ###   ########.fr       */
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
		
	if (c == 'd')
		
	if (c == 'i')
		
	if (c == 'u')
		
	if (c == 'x')
		
	if (c == 'X')
		
	if (c == '%')
		
}
