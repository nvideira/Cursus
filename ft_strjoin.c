/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:36:44 by nvideira          #+#    #+#             */
/*   Updated: 2021/10/27 22:28:13 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *ns;
    unsigned int    i;
    unsigned int    j;

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