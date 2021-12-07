/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:49:26 by nvideira          #+#    #+#             */
/*   Updated: 2021/12/07 21:29:14 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd, int count)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		count = 11;
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
			count = 1;
		}
		if (n >= 10)
		{
			ft_putnbr_fd((n / 10), fd);
			ft_putnbr_fd((n % 10), fd);
		}
		else
		{
			ft_putchar_fd((n + '0'), fd);
			count++;
		}
	}
	return (count);
}

int	ft_putunsnbr_fd(unsigned int n, int fd)
{
	unsigned int	count;

	count = 0;
	if (n >= 10)
	{
		ft_putunsnbr_fd((n / 10), fd);
		ft_putunsnbr_fd((n % 10), fd);
	}
	else
	{
		ft_putchar_fd((n + '0'), fd);
		count++;
	}
	return (count);
}
