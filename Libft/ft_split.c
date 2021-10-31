/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:03:49 by nvideira          #+#    #+#             */
/*   Updated: 2021/10/29 17:42:16 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(char s, char c)
{
	if (s == c || s == '\0')
		return (1);
	else
		return (0);
}

static int	ft_wordcount(const char *str, char c)
{
	int		words;
	size_t	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (ft_space(str[i], c) == 0 && ft_space(str[i + 1], c) == 1)
			words++;
		i++;
	}
	return (words);
}

static void	split_it(char const *s, char c, int st, char **ns)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] != '\0' && s[i] == c)
		{
			i++;
			st++;
		}
		if (s[i] == '\0')
			break ;
		if (ft_space(s[i], c) == 0 && ft_space(s[i + 1], c) == 1)
		{
			ns[j++] = ft_substr(s, st, (i - st) + 1);
			st = i + 1;
		}
		i++;
	}
	ns[j] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**ns;
	size_t	st;

	st = 0;
	if (!s)
		return (NULL);
	ns = malloc(sizeof(char *) * (ft_wordcount(s, c)));
	if (!ns)
		return (NULL);
	split_it(s, c, st, ns);
	return (ns);
}
