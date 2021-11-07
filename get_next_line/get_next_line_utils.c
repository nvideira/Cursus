/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:17:01 by nvideira          #+#    #+#             */
/*   Updated: 2021/11/07 19:03:27 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ns;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	ns = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!ns)
		return (NULL);
	while (s1[i])
	{
		ns[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ns[i + j] = s2[j];
		j++;
	}
	ns[i + j] = '\0';
	return (ns);
}

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = malloc(ft_strlen(s1) + 1);
	if (!p)
		return (NULL);
	ft_memmove(p, s1, ft_strlen(s1) + 1);
	return (p);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dr;
	const char	*sr;
	size_t		i;

	sr = src;
	dr = dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dr < sr)
	{
		while (i < len)
		{
			dr[i] = sr[i];
			i++;
		}
	}
	else
	{
		while (len--)
			dr[len] = sr[len];
	}
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
