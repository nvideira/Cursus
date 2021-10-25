/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:28:47 by nvideira          #+#    #+#             */
/*   Updated: 2021/10/25 20:47:00 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*src;

	src = (char *)s;
	while (n-- > 0)
	{
		if (*src == c)
			return ((void *)src);
		src++;
	}
	return (NULL);
}
