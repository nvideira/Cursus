/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 23:52:08 by nvideira          #+#    #+#             */
/*   Updated: 2021/10/25 19:39:04 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void			*dr;

	dr = dst;
	if (!dst && !src)
		return (0);
	if (dst < src)
	{
		while (len--)
		{
			*(unsigned char *)dst++ = *(unsigned char *)src++;
		}
	}
	else
	{
		dst = dst + len;
		src = src + len;
		while (len-- != (size_t)-1)
			*(unsigned char *)dst-- = *(unsigned char *)src--;
	}
	return (dr);
}