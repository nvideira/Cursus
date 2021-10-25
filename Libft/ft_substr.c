/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 01:36:05 by nvideira          #+#    #+#             */
/*   Updated: 2021/10/25 02:15:49 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	unsigned int	i;
	char	*str1;

	str1 = (char *)s;
	i = 0;
	while (i < len && *s)
		i++;
	sub = malloc(i);
	if (!sub)
		return (NULL);
	while (start < len && str1[start] != '\0')
	{
		sub = &str1[start];
		start++;
	}
	return (sub);
}

int	main(void)
{
	char	*s = "abcdefghijklmnop";

	printf("%s\n", ft_substr(s, 5, 7));
}
