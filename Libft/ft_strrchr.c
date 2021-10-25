/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:00:32 by nvideira          #+#    #+#             */
/*   Updated: 2021/10/25 16:38:52 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ini;
	int			i;

	ini = s;
	i = ft_strlen(s);
	s += i;
	while (s != ini && *s != c)
		s--;
	if (*s == c)
		return ((char *)s);
	return (0);
}
