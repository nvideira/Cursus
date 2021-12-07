/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:27:43 by nvideira          #+#    #+#             */
/*   Updated: 2021/12/07 21:29:00 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	oct_to_dec(int n)
{
	int	ndigits;
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	ndigits = 0;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	while (n > 0)
	{
		res += (n % 10) * ft_iterative_power(8, ndigits);
		n /= 10;
		ndigits++;
	}
	return (res * sign);
}

int	hex_to_dec(int n)
{
	
}
