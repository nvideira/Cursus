/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:03:49 by nvideira          #+#    #+#             */
/*   Updated: 2021/10/28 17:49:14 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	size_t			ni;
	char			**new;

	i = 0;
	j = 0;
	ni = 0;
	while (*s)
	{
		if (s[i] != c)
			i++;
		if (s[i] == c)
		{
			*new[ni] = *ft_substr(s, j, i);
			j = i;
			i++;
			ni++;
		}
	}
	*new[ni] = (char )ft_memset(*new[ni], '\0', 1);
	return (new);
}
