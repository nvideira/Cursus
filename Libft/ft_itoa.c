/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:44:00 by nvideira          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/10/30 18:09:17 by nvideira         ###   ########.fr       */
=======
/*   Updated: 2021/10/29 18:40:45 by nvideira         ###   ########.fr       */
>>>>>>> 546609a62afe398578b308683d623b4c501f408c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nblen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len = 1;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
<<<<<<< HEAD
	int		len;

	len = nblen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		s[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (s);
}
=======
	int	len;
	
	len = nblen(n);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len + 1] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n
	}
	if (n = -2147483648)
	{
		s[0] = '-';
		
	}
	else if (n = 0)
		s[0] = 0;
	else
	{
		while (n > 0)
		{
			s[len] = n % 10;
			n /= 10;
			len--;
		}
	}
	return (s);
	
}
>>>>>>> 546609a62afe398578b308683d623b4c501f408c
