/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:17:01 by nvideira          #+#    #+#             */
/*   Updated: 2021/11/30 16:20:17 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	p = malloc(ft_strlen(s1) + 1);
	if (!p)
		return (NULL);
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	p[i] = '\0';
	return (p);
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
	sub = malloc((len + 1) * sizeof(char));
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
