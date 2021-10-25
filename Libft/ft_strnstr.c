/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:42:42 by nvideira          #+#    #+#             */
/*   Updated: 2021/10/22 18:57:01 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l2;

	l2 = ft_strlen(needle);
	if (l2 == 0)
		return ((char *)haystack);
	while (l2 <= len && *haystack != '\0')
	{
		if (ft_strncmp(haystack, needle, l2) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
