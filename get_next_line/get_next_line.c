/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:16:20 by nvideira          #+#    #+#             */
/*   Updated: 2021/11/07 19:03:19 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	static char		*bufstr;
	static char		*str;
	unsigned int	i;
	unsigned int	j;
	static char		*strfin;
	static char		*overbuff;

	i = 0;
	j = 0;
	if (overbuff != NULL)
	{
		strfin = ft_strjoin(strfin, overbuff);
		free (overbuff);
	}
	if (fd < 0 || buff < 0)
		return (NULL);
	while (fd)
	{
		bufstr = (char *)malloc(BUFFER_SIZE * sizeof(char));
		if (!bufstr)
			return (NULL);
		read(fd, bufstr, BUFFER_SIZE);
		while (bufstr[i] != '\n' && bufstr[i] != '\0')
			i++;
		if (!str)
			str = ft_strdup(bufstr);
		ft_strjoin(str, bufstr);
		free (bufstr);
	}
	while (str[j] != '\n')
		j++;
	strfin = ft_substr(str, 0, j);
	if (j != ft_strlen(str))
		overbuff = ft_substr(str, j + 1, ft_strlen(str) - j);
	free (str);
	return (strfin);
}
