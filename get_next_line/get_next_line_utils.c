/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:17:01 by nvideira          #+#    #+#             */
/*   Updated: 2021/11/29 00:46:19 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strljoin(char const *s1, char const *s2, unsigned int len)
{
	char			*ns;
	unsigned int	i;
	unsigned int	j;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_substr(s2, 0, len));
	ns = malloc((ft_strlen(s1) + len) * sizeof(char) + 1);
	if (!ns)
		return (NULL);
	i = -1;
	while (s1[++i])
		ns[i] = s1[i];
	j = -1;
	while (s2[++j] && j < len)
		ns[i + j] = s2[j];
	ns[i + j] = '\0';
	return (ns);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	if (!s1)
		return (NULL);
	p = malloc(ft_strlen(s1));
	if (!p)
		return (NULL);
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	p[i] = '\0';
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
	if (!src)
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

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		while (*s != (char )c && *s != '\0')
			s++;
		if (*s == (char )c)
			return ((char *)s);
		else
			return (NULL);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!len || ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s) - (size_t)start;
	sub = malloc((len) * sizeof(char));
	if (!sub)
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ns;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s2)
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
